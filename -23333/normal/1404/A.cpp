#include <bits/stdc++.h>
using namespace std;
#define rep(i,h,t) for (int i=h;i<=t;i++)
#define dep(i,t,h) for (int i=t;i>=h;i--)
#define ll long long
const int N=4e5;
char c[N];
int f[N];
bool cl(int &x,int y)
{
	if (x==-1)
	{
		x=y; return 1;
	} else
	if (x!=y) return 0;
	return 1;
}
int main()
{
	ios::sync_with_stdio(false);
	int T;
    cin>>T;
    rep(i,1,T)
    {
    	int k,n;
    	cin>>n>>k;
    	cin>>c;
    	rep(i,1,k) f[i]=-1;
    	bool tt=1;
    	rep(i,1,n)
    	{
    		if (c[i-1]=='1') tt&=cl(f[i%k+1],1);
    		if (c[i-1]=='0') tt&=cl(f[i%k+1],0);
    	}
    	int cnt1=0,cnt2=0;
    	rep(i,1,k)
    	{
    		if (f[i%k+1]==1) cnt1++;
    		if (f[i%k+1]==0) cnt2++;
    	}
    	if (cnt1<=k/2&&cnt2<=k/2&&tt)
    	{
    		cout<<"YES"<<endl;
    	} else
    	{
    		cout<<"NO"<<endl;
    	}
    }
	return 0;
}