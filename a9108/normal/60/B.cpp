#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
#include <map>
#define eps 1e-8
#define PB push_back
#define MP make_pair
using namespace std;
double pi=asin(1.0)*2;

char s[20][20][20];
int n,m,k,x,y;
bool f[20][20][20];
int ans;

void insert(int x,int y,int z){
	if (x<0||x>=n||y<0||y>=m||z<0||z>=k) return;
	if (f[x][y][z]||s[x][y][z]=='#') return;
	ans++;
	f[x][y][z]=true;
	insert(x-1,y,z);
	insert(x+1,y,z);
	insert(x,y-1,z);
	insert(x,y+1,z);
	insert(x,y,z-1);
	insert(x,y,z+1);
}

int main(){
	scanf("%d%d%d",&n,&m,&k);
	for (int i=0;i<n;i++)
	for (int j=0;j<m;j++) scanf("%s",s[i][j]);
	scanf("%d%d",&x,&y);
	memset(f,false,sizeof(f));
	ans=0;
	insert(0,x-1,y-1);
	printf("%d\n",ans);
	return 0;
}