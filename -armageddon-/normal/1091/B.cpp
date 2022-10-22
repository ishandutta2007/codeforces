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
typedef unsigned long long ull;
const int inf=1039074182;
using namespace std;
int n;
int a[1005];
int b[1005];
int pa[1005];
int pb[1005];
set <pair<int,int> >squ;

int main()
{
//	freopen("input.txt","r",stdin);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i]>>b[i];
	}
	for(int i=0;i<n;i++)
	{
		cin>>pa[i]>>pb[i];
	}
	int x,y;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			squ.insert(mp(pa[j],pb[j]));
		}
		x=a[0]+pa[i];
		y=b[0]+pb[i];
//		cout<<x<<' '<<y<<endl;
		bool f=false;
		for(int j=0;j<n;j++)
		{
			int tx=x-a[j];
			int ty=y-b[j];
//			cout<<tx<<' '<<ty<<endl;
			if(squ.find(mp(tx,ty))!=squ.end())
			{
//				cout<<j<<endl;
				squ.erase(mp(tx,ty));
				continue;
			}
			f=true;
			break;
		}
		if(!f)
		{
			cout<<x<<' '<<y<<endl;
			return 0;
		}
	}
	return 0;
}