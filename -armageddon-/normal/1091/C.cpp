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
vector <ll> vec;
vector <ll> res;

int main()
{
//	freopen("input.txt","r",stdin);
	int n;
	cin>>n;
	for(int i=1;i*i<=n;i++)
	{
		if(n%i==0)
		{
			vec.push_back(i);
			if(i*i!=n) vec.push_back(n/i);
		}
	}
	for(int i=0;i<vec.size();i++)
	{
		res.push_back(1LL*n/vec[i]+1LL*vec[i]*(n/vec[i])*(n/vec[i]-1)/2);
	}
	sort(res.begin(),res.end());
	res.resize(unique(res.begin(),res.end())-res.begin());
	for(int i=0;i<res.size();i++)
	{
		printf("%I64d ",res[i]);
	}
	return 0;
}