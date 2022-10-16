#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ab abab
bool cmp(int a,int b){return a>b;}
ll sum,k,n,a[100002],cnta,b[100002],cntb;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)cin>>k,k%2?a[++cnta]=k:b[++cntb]=k;
	sort(a+1,a+cnta+1,cmp);
	sort(b+1,b+cntb+1);
	for(int i=1;i<=cntb;i++)
		sum+=b[i];
	for(int i=1;i<=cnta/2;i++)
		sum+=a[i*2-1]+a[i*2];
	cout<<sum;
	return 0;
}