#include <bits/stdc++.h>
using namespace std;
#define rep(i,h,t) for (int i=h;i<=t;i++)
#define dep(i,t,h) for (int i=t;i>=h;i--)
const int N=1e5;
int a[N]; 
int main()
{
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	rep(i,1,t)
	{
		int n;
		cin>>n;
		rep(j,1,n) cin>>a[j];
		if (n<=2||a[1]+a[2]>a[n])
		{
			cout<<-1<<endl;
			continue;
		}
		cout<<1<<" "<<2<<" "<<n<<endl;
	}
	return 0;
}