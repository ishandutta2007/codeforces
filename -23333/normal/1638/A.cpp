#include <bits/stdc++.h>
using namespace std;
#define rep(i,h,t) for (int i=h;i<=t;i++)
#define dep(i,t,h) for (int i=t;i>=h;i--) 
#define ll long long
const int P=998244353;
map<int,int> M;
const int N=1e6;
int a[N];
int main()
{
	int T;
	cin>>T;
	while (T--)
	{
		int n;
		cin>>n;
		rep(i,1,n) cin>>a[i];
		int pos=0;
		rep(i,1,n) if (a[i]!=i) {pos=i;break;}
		if (pos)
		{
			int jl=0;
			rep(i,1,n)
			{
				if (a[i]==pos) jl=i;
			}
			reverse(a+pos,a+jl+1);
		}
		rep(i,1,n) cout<<a[i]<<" ";
		cout<<endl;
	}
	return 0;
}