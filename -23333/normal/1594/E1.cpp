#include <bits/stdc++.h>
using namespace std;
#define rep(i,h,t) for (int i=h;i<=t;i++)
#define dep(i,t,h) for (int i=t;i>=h;i--)
#define ll long long
const int N=5e5;
const int mo=1e9+7;
ll f[N];
int main()
{
	ios::sync_with_stdio(false);
	int k;
	cin>>k;
	f[1]=1;
	rep(i,2,k)
	  f[i]=f[i-1]*f[i-1]%mo*16%mo;
	cout<<f[k]*6%mo<<endl; 
	return 0;
}