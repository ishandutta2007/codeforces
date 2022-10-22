#include <iostream>
#include <algorithm>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <string.h>
#include <stack>
#define Endl endl
#define mp make_pair
#define rep(N) for(int i=0;i<N;i++)
#define repj(N) for(int j=0;j<N;j++)
#define ll long long 
#define pii pair<int,int>
#define pll pair<ll,ll>
#define For(I,N) for(int I=0;I<N;I++)
#define cinone(N) int N;cin>>N;
#define scanfone(N) int N;cin>>N;
#define cinng(N,M) int N[M];for(int yiuytvnm=0;yiuytvnm<M;yiuytvnm++) cin>>N[yiuytvnm];
#define scanfng(N,M) int N[M];for(int qrwuoiq=0;qrwuoiq<M;qrwuoiq++) scanf("%d",&N[qrwuoiq]);
#define over(A) {cout<<A<<endl;exit(0);}
#define all(A) A.begin(),A.end()
#define ceil(a,b) ((a-1)/b+1)
#include <windows.h>
typedef unsigned long long ull;
const int inf=1039074182;
using namespace std;
int nxt[2005][2005];
int pre[2005][2005];
bool use[2005][2005];
//const int maxn=450;
//vector <pair<int,int> >vec[maxn];
//vector <pair<int,int> >order;
//int tourist[2005][2005];
//bool gwq[2005][2005];
////unordered_map <pair<int,int>,bool> gwq;
//vector <pair<int,int> >res;
int n,m;

int findnxt(int line,int x)
{
//	cout<<"line x:"<<line<<' '<<x<<endl;
//	cout<<"use[1][1]:"<<use[1][1]<<endl;
//	cout<<"nxt[1][1]:"<<nxt[1][1]<<endl;
//	Sleep(1000);
//	system("pause");
	if(n<m) return (!use[line][x]?x:nxt[line][x]=findnxt(line,nxt[line][x]));
	else return (!use[x][line]?x:nxt[x][line]=findnxt(line,nxt[x][line]));
}

int findpre(int line,int x)
{
	if(n<m) return (!use[line][x]?x:pre[line][x]=findpre(line,pre[line][x]));
	else return (!use[x][line]?x:pre[x][line]=findpre(line,pre[x][line]));
}

inline bool out(int x,int y)
{
	return (x<=0 || y<=0 || x>n || y>m);
}

inline int getd(int x1,int y1,int x2,int y2)
{
	return (abs(x1-x2)+abs(y1-y2));
}

int main()
{
//	freopen("input.txt","r",stdin);
	cin>>n>>m;
	if(n<m)
	{
		for(int i=0;i<=2000;i++)
		{
			for(int j=0;j<=2000;j++)
			{
				nxt[i][j]=j;
				pre[i][j]=j;
			}
		}
		int q;
		cin>>q;
		int x,y;
		int minx;
		pair<int,int> mink=mp(-1,-1);
		int t;
		while(q--)
		{
//			bool debug=(q==4);
	//		if(debug) break;
			scanf("%d%d",&x,&y);
	//		cout<<findpre(0,0);
	//		mink=mp(-1,-1);
			minx=inf;
			for(int i=max(1,x-400);i<=min(x+400,n);i++)
			{
				t=findpre(i,y);
	//			if(debug) cout<<t<<endl;
	//			cout<<out(i,t)<<endl;
				if(!out(i,t) && getd(i,t,x,y)<minx)
				{
	//				if(debug) cout<<i<<' '<<t<<endl;
					minx=getd(i,t,x,y);
					mink=mp(i,t);
				}
				t=findnxt(i,y);
				if(!out(i,t) && getd(i,t,x,y)<minx)
				{
	//				if(debug) cout<<i<<' '<<t<<endl;
					minx=getd(i,t,x,y);
					mink=mp(i,t);
				}
			}
	//		cout<<minx<<endl;
			int nx=mink.first;
			int ny=mink.second;
	//		cout<<nx<<' '<<ny+1<<endl;
	//		cout<<"UK";
	//		cout<<(!use[1][1])<<endl;
	//		cout<<nxt[1][1]<<endl;
	//		system("pause");
	//		if(debug) cout<<nxt[1][1]<<endl;
	//		if(debug) cout<<findnxt(1,1)<<'F';
	//		if(debug) break;
	//		cout<<nxt[nx][ny+1]<<endl;
			pre[nx][ny]=pre[nx][ny-1];
	//		cout<<nxt[1][2];
			nxt[nx][ny]=nxt[nx][ny+1];
	//		cout<<nxt[1][1];
	//		cout<<nxt[1][1]<<endl;
	//		cout<<out(0,0)<<'F';
			use[nx][ny]=true;
			printf("%d %d\n",nx,ny);
		}
	}
	//	vec[0].push_back(mp(0,0));
	//	bool debug;
	//	for(int k=1;k<maxn;k++)
	//	{
	//		int x,y;
	//		x=-k;
	//		y=0;
	//		for(int i=0;i<k;i++)
	//		{
	//			vec[k].push_back(mp(x,y));
	//			x++;
	//			y--;
	//		}
	//		for(int i=0;i<k;i++)
	//		{
	//			vec[k].push_back(mp(x,y));
	//			x++;
	//			y++;
	//		}
	//		for(int i=0;i<k;i++)
	//		{
	//			vec[k].push_back(mp(x,y));
	//			x--;
	//			y++;
	//		}
	//		for(int i=0;i<k;i++)
	//		{
	//			vec[k].push_back(mp(x,y));
	//			x--;
	//			y--;
	//		}
	////		random_shuffle(all(vec[k]));
	//		sort(all(vec[k]));
	//	}
	//	for(int i=0;i<maxn;i++)
	//	{
	//		for(int j=0;j<vec[i].size();j++)
	//		{
	//			order.push_back(vec[i][j]);
	//		}
	//	}
	////	cout<<order.size()<<endl;
	//	int x,y;
	//	int q;
	//	cin>>q;
	//	int nx,ny;
	//	while(q--)
	//	{
	////		if(q/100==) cout<<q<<endl;
	////		cout<<q<<endl;
	//		scanf("%d%d",&x,&y);
	//		x--;
	//		y--;
	////		if(x>=2000 || y>=2000) over("FIC");
	////		if(x<0 || y<0) over("FJC");
	//		debug=(x==1624 && y==16);
	////		if(debug && q<=30000)
	////		{
	////			system("cd C:\src\llvm_package_600-final\llvm\projects\compiler-rt\lib\sanitizer_common & del sanitizer_win.cc");
	////			cout<<"FUCK";
	////			cout<<tourist[x][y];
	////			break;
	////		}
	////		cout<<tourist[mp(x,y)]<<endl;
	//		for(int i=tourist[x][y];;i++)
	//		{
	//			nx=x+order[i].first;
	//			ny=y+order[i].second;
	////			if(nx>=2000 || ny>=2000) over("FUCK");
	//			if(out(nx,ny)) continue;
	////			if(nx>=2000 || ny>=2000) over("FUCK");
	//			if(gwq[nx][ny]==0)
	//			{
	//				gwq[nx][ny]=true;
	////				gwq[mp(x+order[i].first,y+order[i].second)]=1;
	//				tourist[x][y]=i;
	//				printf("%d %d\n",nx,ny);
	////				res.push_back(mp(nx,ny));
	//				break;
	//			}
	//		}	
	//	}
	//	for(int i=0;i<res.size();i++)
	//	{
	//		printf("%d %d\n",res[i].first+1,res[i].second+1);
	//	}
	else
	{
		for(int i=0;i<=2000;i++)
		{
			for(int j=0;j<=2000;j++)
			{
				nxt[i][j]=i;
				pre[i][j]=i;
			}
		}
		int q;
		cin>>q;
		int x,y;
		int minx;
		pair<int,int> mink=mp(-1,-1);
		int t;
		while(q--)
		{
			bool debug=(q==9);
			scanf("%d%d",&x,&y);
			minx=inf;
			for(int j=max(1,y-400);j<=min(m,y+400);j++)
			{
				t=findpre(j,x);
//				if(debug) cout<<use[t][j]<<endl;
//				if(debug) cout<<x<<'-'<<t<<'-'<<j<<endl;
				if(!out(t,j) && (getd(t,j,x,y)<minx || (getd(t,j,x,y)==minx && t<mink.first)))
				{
					minx=getd(t,j,x,y);
					mink=mp(t,j);
				}
				t=findnxt(j,x);
				if(!out(t,j) && (getd(t,j,x,y)<minx || (getd(t,j,x,y)==minx && t<mink.first)))
				{
					minx=getd(t,j,x,y);
					mink=mp(t,j);
				}
			}
			int nx=mink.first;
			int ny=mink.second;
			pre[nx][ny]=pre[nx-1][ny];
			nxt[nx][ny]=nxt[nx+1][ny];
			use[nx][ny]=true;
			printf("%d %d\n",nx,ny);
		}
	}
	return 0;
}