#include <bits/stdc++.h>
using namespace std;
#define rep(i,h,t) for (int i=h;i<=t;i++)
#define dep(i,t,h) for (int i=t;i>=h;i--)
#define ll long long
const int N=2e5;
ll a[N],f[N];
int main()
{
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	rep(i,1,n) cin>>a[i];
	if (n==1)
	{
		cout<<1<<" "<<1<<endl;
		cout<<0<<endl;
		cout<<1<<" "<<1<<endl;
		cout<<0<<endl;
		cout<<1<<" "<<1<<endl;
		cout<<-a[1]<<endl;
		return 0;
	}
	rep(i,0,n-1)
	{
		int t=(1ll*i*(n-1))%n;
		f[t]=i;
	}
	cout<<1<<" "<<n-1<<endl;
	rep(i,1,n-1)
 	{
 		int t=(n-a[i]%n)%n;
 		cout<<f[t]*(n-1)<<" ";
 		a[i]=a[i]+f[t]*(n-1);
    }
    cout<<endl;
	cout<<1<<" "<<n<<endl;
	rep(i,1,n-1)
	{
		cout<<-a[i]<<" ";
    }
    cout<<0<<endl;
    cout<<n<<" "<<n<<endl;
    cout<<-a[n]<<endl;
	return 0; 
}