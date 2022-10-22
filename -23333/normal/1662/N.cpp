#include <bits/stdc++.h>
using namespace std;
#define rep(i,h,t) for (int i=h;i<=t;i++)
#define dep(i,t,h) for (int i=t;i>=h;i--)
#define ll long long
const int N=2000;
int n;
struct re{
	int a,b,c;
	bool operator <  (const re x) const{
		return a<x.a;
	}
};
vector<re> ve;
int M[N][N],a[N],b[N];
int main()
{
	ios::sync_with_stdio(false);
    cin>>n;
    rep(i,1,n)
      rep(j,1,n)
	  { 
	    cin>>M[i][j];
	    ve.push_back({M[i][j],i,j});
	  }
	sort(ve.begin(),ve.end());
	rep(i,1,n) a[i]=b[i]=n;
	ll ans=-1ll*n*n*(n-1)*(n-1)/4;
	for (auto v:ve)
	{
		int x=v.b,y=v.c;
		a[x]--; b[y]--;
		ans+=a[x]*b[y];
	}
	cout<<1ll*n*n*(n-1)*(n-1)/4-ans<<endl;
	return 0;
}