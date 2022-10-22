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
#define div(a,b) ((a-1)/b+1)
typedef unsigned long long ull;
const int inf=1039074182;
using namespace std;
map <ll,int> m;
vector <ll> prime;
ll a[505];
int die[505];
const int mod=998244353;

int main()
{
//	cout<<pow(512,0.25f)<<endl;
//	freopen("input.txt","r",stdin);
	int n;
	ll x;
	cin>>n;
	vector <ll> vec;
	for(int i=0;i<n;i++)
	{
		cin>>x;
		a[i]=x;
		ll t=pow((long double)x,0.25f);
//		cout<<t<<endl;
		if(t*t*t*t==x)
		{
//			cout<<"FUCK";
			m[t]+=4;
			prime.push_back(t);
			continue;
		}
		t=pow((long double)x,(long double)(1)/3);
		if(t*t*t==x)
		{
			m[t]+=3;
			prime.push_back(t);
			continue;
		}
		t=pow((long double)x,0.5f);
		if(t*t==x)
		{
			m[t]+=2;
			prime.push_back(t);
			continue;
		}
		else
		{
			vec.push_back(x);
		}
	}
	vector <ll> v;
	for(int i=0;i<vec.size();i++)
	{
		for(int j=0;j<n;j++)
		{
//			if(i==j) continue;
			ll t=__gcd(vec[i],a[j]);
			if(t==1) continue;
			if(t==vec[i]) continue;
			die[i]=true;
//			cout<<t<<' '<<vec[i]<<endl;
			m[t]++;
			m[vec[i]/t]++;
			break;
		}
	}
//	for(int i=0;i<vec.size();i++)
//	{
//		cout<<vec[i]<<' ';
//	}
//	cout<<endl;
	v=vec;
	vec.clear();
	for(int i=0;i<v.size();i++)
	{
		if(die[i]) continue;
		vec.push_back(v[i]);
	}
	sort(all(vec));
	ll res=1;
	int s;
	for(int i=0;i<vec.size();i++)
	{
		s=0;
		for(;i+1<vec.size() && vec[i]==vec[i+1];i++)
		{
			s++;
		}
		res*=1LL*(s+2)*(s+2);
		res%=mod;
	}
//	cout<<res<<endl;
	for(map <ll,int> :: iterator it=m.begin();it!=m.end();it++)
	{
//		cout<<it->first<<' '<<it->second<<endl;
		res*=1LL*(it->second+1);
		res%=mod;
	}
	cout<<res<<endl;
	fflush(stdout);
	return 0;
}