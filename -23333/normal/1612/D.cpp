#include <bits/stdc++.h>
using namespace std;
#define rep(i,h,t) for (int i=h;i<=t;i++)
#define dep(i,t,h) for (int i=t;i>=h;i--)
#define ll long long
const int N=2e5;
ll n,m,k;
bool tt=0;
void gao(ll x,ll y)
{
	if (x==k||y==k) tt=1;
	if (y==0) return;
	if (x>k&&(x-k)%y==0) tt=1;
	gao(y,x%y);
}
int main()
{
	ios::sync_with_stdio(false);
    int T;
	cin>>T;
	while (T--)
	{ 
	   cin>>n>>m>>k;
	   tt=0;
	   if (n<m) swap(n,m);
	   gao(n,m);
	   if (tt) cout<<"YES"<<endl;
	   else cout<<"NO"<<endl;
    }
	return 0; 
}