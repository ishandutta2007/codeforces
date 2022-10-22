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
#define ll long long 
#define pii pair<int,int>
#define pll pair<ll,ll>
#define over(A) {cout<<A<<endl;exit(0);}
#define ceil(a,b) ((a-1)/b+1)
#define srand() mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rand(l,r) uniform_int_distribution<int>(l,r)(rng)
typedef unsigned long long ull;
const int inf=1039074182;
using namespace std;
int n;
int k;
pair<int,int> t[300005];
priority_queue <int,vector<int>,greater<int> >que;

int main()
{
//	freopen("input.txt","r",stdin);
	cin>>n>>k;
	for(int i=0;i<n;i++)
	{
		scanf("%d%d",&t[i].second,&t[i].first);
	}
	sort(t,t+n);
	reverse(t,t+n);
	for(int i=0;i<n;i++)
	{
		swap(t[i].first,t[i].second);
	}
	ll time=0;
	ll res=0;
	for(int i=0;i<k;i++)
	{
		que.push(t[i].first);
		time+=t[i].first;
		res=max(res,time*t[i].second);
	}
	for(int i=k;i<n;i++)
	{
		que.push(t[i].first);
		time+=t[i].first;
		time-=que.top();
		que.pop();
		res=max(res,time*t[i].second);
	}
	cout<<res<<endl;
	return 0;
}