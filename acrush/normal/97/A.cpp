#include <string>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <ctime>
#include <list>
#include <map>
#include <set>
#include <bitset>
#include <functional>
#include <utility>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string.h>
 
using namespace std;
 
typedef long long int64;
typedef unsigned long long uint64;
#define two(X) (1<<(X))
#define twoL(X) (((int64)(1))<<(X))
#define contain(S,X) ((S&two(X))>0)
#define containL(S,X) ((S&twoL(X))>0)
typedef pair<int,int> ipair;
int countbit(int n) {return (n==0)?0:(1+countbit(n&(n-1)));}
int lowbit(int n) {return (n^(n-1))&n;}
const double pi=acos(-1.0);
const double eps=1e-11;
template<class T> T sqr(T x) {return x*x;}
template<class T> void checkmin(T &a,T b) {if (b<a) a=b;}
template<class T> void checkmax(T &a,T b) {if (b>a) a=b;}
#define SIZE(X) ((int)((X).size()))
#define LENGTH(X) ((int)((X).length()))
#define MP(A,B) make_pair(A,B)

int sizex,sizey;
char board[35][35];
int used[7][7];
int touch[7];
int pattern[14][4];
int color[56],g[56];
int idx[35][35];
bool saved;
char result[35][35];

double DFS(int d,int mc)
{
	if (d==14)
	{
		if (!saved)
		{ 
			saved=true; 
			memcpy(result,board,sizeof(board));
			for (int x=0;x<sizex;x++) for (int y=0;y<sizey;y++) if (idx[x][y]>=0)
				result[x][y]=color[idx[x][y]]+'0';
		}
		return 1;
	}
	int save_used[7][7];
	int save_touch[7];
	memcpy(save_used,used,sizeof(used));
	memcpy(save_touch,touch,sizeof(touch));
	double R=0;
	for (int c=0;c<=mc && c<7;c++)
	{
		bool is_good=true;
		for (int i=0;i<4;i++) 
		{
			color[pattern[d][i]]=c;
			int a=pattern[d][i];
			if (color[g[a]]>=0) 
			{
				if (used[color[a]][color[g[a]]]>0) { is_good=false; break; }
				touch[color[g[a]]]--;
				used[color[a]][color[g[a]]]++;
				used[color[g[a]]][color[a]]++;
			}
			else
				touch[color[a]]++;
		}
		if (is_good)
			for (int i=0;i<7;i++) 
			{
				int left=0;
				for (int j=0;j<7;j++) if (!used[i][j]) left++;
				if (touch[i]>left) { is_good=false; break; }
			}
		if (is_good) R+=((c==mc)?(7-mc):1)*DFS(d+1,min(7,max(mc,c+1)));
		memcpy(used,save_used,sizeof(used));
		memcpy(touch,save_touch,sizeof(touch));
		for (int i=0;i<4;i++) color[pattern[d][i]]=-1;
	}
	return R;
}
int main()
{
#ifdef _MSC_VER
	freopen("input.txt","r",stdin);
#endif
	scanf("%d%d",&sizex,&sizey);
	for (int i=0;i<sizex;i++) scanf("%s",board[i]);
	memset(idx,255,sizeof(idx));
	for (int counter=0,i=0;i<sizex;i++) for (int j=0;j<sizey;j++) if (board[i][j]!='.') idx[i][j]=(counter++);
	for (int x=0;x<sizex;x++) for (int y=0;y<sizey;y++) if (board[x][y]!='.')
		for (int dx=-1;dx<=1;dx++) for (int dy=-1;dy<=1;dy++) if (abs(dx)+abs(dy)==1)
		{
			int x2=x+dx;
			int y2=y+dy;
			if (x2>=0 && x2<sizex && y2>=0 && y2<sizey && board[x2][y2]==board[x][y]) g[idx[x][y]]=idx[x2][y2];
		}
	for (int counter=0,i=0;i<sizex;i++) for (int j=0;j<sizey;j++) if (board[i][j]!='.')
	{
		pattern[counter][0]=idx[i][j];
		pattern[counter][1]=idx[i][j+1];
		pattern[counter][2]=idx[i+1][j];
		pattern[counter][3]=idx[i+1][j+1];
		counter++;
		board[i][j]=board[i][j+1]=board[i+1][j]=board[i+1][j+1]='.';
	}
	saved=false;
	memset(used,0,sizeof(used));
	memset(touch,0,sizeof(touch));
	memset(color,255,sizeof(color));
	double ret=DFS(0,0);
	printf("%.0lf\n",ret);
	for (int x=0;x<sizex;x++) printf("%s\n",result[x]);
	return 0;
}