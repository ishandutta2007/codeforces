#include <bits/stdc++.h>
using namespace std;
#define rep(i,h,t) for (int i=h;i<=t;i++)
#define dep(i,t,h) for (int i=t;i>=h;i--)
#define ll long long
const int mo=1e9+7;
const int MN=1e6;
ll jc[MN+10],jc2[MN+10];
int pri[MN+10],phi[MN+10],cntpri;
ll fsp(int x,int y)
{
    if (y==0) return 1;
    if (y==1) return x;
    ll ans=fsp(x,y/2);
    ans=ans*ans%mo;
    if (y%2==1) ans=ans*x%mo;
    return ans; 
}
ll C(int n,int m)
{
    if (n<m) return 0;
    return jc[n]*jc2[m]%mo*jc2[n-m]%mo;
}
const int N=1e6;
int a[N];
int s[N];
int main()
{
	ios::sync_with_stdio(false);
	jc[0]=jc2[0]=1;
    rep(i,1,1e6) jc[i]=jc[i-1]*i%mo;
    jc2[1000000]=fsp(jc[1000000],mo-2);
    dep(i,1e6-1,1) jc2[i]=jc2[i+1]*(i+1)%mo;
    int n;
    cin>>n; n++;
    rep(i,1,n)
	{ 
	  cin>>a[i];
	  s[0]++; s[a[i]]--;
    }
    rep(i,1,2e5) s[i]+=s[i-1];
    ll ans=0;
    rep(i,0,2e5)
    {
    	(ans+=C(s[i]+i,i+1))%=mo;
    }
    cout<<ans<<endl;
	return 0;
}
/*
1
10
7 4 8 1 6 10 3 5 2 9
*/