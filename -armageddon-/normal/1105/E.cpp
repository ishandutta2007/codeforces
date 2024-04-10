//is it real that C++17 is faster than C++11
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
const int mod=19260817;
using namespace std;
char c[45];
int n;
map <int,int> m;
bool road[45][45];
ll can[45];
int res;
ll index[45];
int times;
int l2[19260817];

void init()
{
	for(int i=0;i<=40;i++)
	{
		l2[(1LL<<i)%19260817]=i;
	}
}

inline int calc(ll mask)
{
	return l2[mask%19260817];
}

void dfs(int x,ll mask,ll opt)
{
	times++;
	if(times>=7e7) over(res);
//	cout<<mask<<endl;
	res=max(res,__builtin_popcount(mask&((1LL<<31)-1))+(int)__builtin_popcount(mask>>31));
	ll t=(~mask)&index[x]&opt;
	if((int)__builtin_popcount(t&((1LL<<31)-1))+(int)__builtin_popcount(mask&((1LL<<31)-1))+(int)__builtin_popcount(mask>>31)+(int)__builtin_popcount(t>>31)<=res) return;
	while(t)
	{
		int lowbit=calc(t&(-t));
//		if((can[lowbit]&mask)==mask)
//		{
		dfs(lowbit,mask|(1LL<<lowbit),opt&can[lowbit]);
//		}
		t&=(t-1);
	}
}

int myhash(char c[])
{
	int res=0;
	int len=strlen(c);
	for(int i=0;i<len;i++)
	{
		res=(1LL*res*107+c[i]-'0')%mod;
	}
	return res;
}

int main()
{
//	cout<<(((1LL<<30)+(1LL<<35))&((1LL<<(33))-1))<<endl;
//	freopen("input.txt","r",stdin);
	init();
	memset(road,true,sizeof(road));
	int t;
	cin>>t>>n;
	int type;
	string s;
	vector <int> vec;
	int k=0;
	while(t--)
	{
		scanf("%d",&type);
		if(type==1)
		{
//			cout<<"FUCK";
			sort(all(vec));
			vec.erase(unique(all(vec)),vec.end());
//			if(vec.size()==3)cout<<vec[0]<<' '<<vec[1]<<' '<<vec[2]<<endl;
			for(int i=0;i<vec.size();i++)
			{
				for(int j=0;j<vec.size();j++)
				{
					if(vec[i]==vec[j]) continue;
					road[vec[i]][vec[j]]=false;
				}
			}
			vec.clear();
		}
		else
		{
			scanf("%s",c);
			if(m.find(myhash(c))==m.end())
			{
				vec.push_back(k++);
				m[myhash(c)]=k-1;
			}
			else
			{
				vec.push_back(m[myhash(c)]);
			}
		}
	}
	sort(all(vec));
	vec.erase(unique(all(vec)),vec.end());
	for(int i=0;i<vec.size();i++)
	{
		for(int j=0;j<vec.size();j++)
		{
			if(vec[i]==vec[j]) continue;
			road[vec[i]][vec[j]]=false;
		}
	}
	vec.clear();
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			can[i]|=((ll)road[i][j]<<j);
		}
	}
	index[n-1]=0;
	for(int i=n-2;i>=0;i--)
	{
		index[i]=index[i+1]|(1LL<<(i+1));
	}
	for(int source=0;source<n;source++)
	{
		dfs(source,(1LL<<source),can[source]);
//		basic^=(1LL<<source);
	}
	cout<<res<<endl;
	return 0;
}