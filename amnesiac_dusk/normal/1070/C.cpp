/*
 * Words like "tomorrow" or "future" or "fate"
 *		No matter how far they extend their hands
 *			We breathe, we dream, we raise our love
 *				In a timeless land that is far out of reach
 */
#include <bits/stdc++.h>
#define IO ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
//#define endl '\n'
#define pii pair<int,int>
#define pb push_back
#define fi first
#define se second
#define int long long
#define fr(a,b,c) for(int a=b; a<=c; a++)
typedef long long ll;
using namespace std;
const ll mod=998244353;
ll powm(ll a, ll b, ll m);


struct node
{
	node(int lefty, int righty,int minc)
	{
		size=righty-lefty+1;
		minval=minc;
		lb=lefty;
		rb=righty;
		if(lefty==righty)
		{
			left=NULL;
			right=NULL;
		}
		else{
			left=new node(lefty,(lefty+righty)/2,minc);
			right=new node((lefty+righty)/2+1,righty,minc);
		}
		lazy=0;
	}
	node* left;
	node *right;
	int lb,rb;
	int size;
	int minval;
	int lazy;
	int query(int l, int r, int core)
	{
		if(size==0)
			return 0;
		if(lb>r||rb<l)
			return 0;
		if(l<=lb&&rb<=r&&minval>core)
		{
			minval-=core;
			lazy+=core;
			return size*core;
		}
		if(lb==rb)
		{
			size=0;
			int te=minval;
			minval=1e18;
			return te;
		}
		int ans=0;
		size=0;
		left->minval-=lazy;
		left->lazy+=lazy;
		right->minval-=lazy;
		right->lazy+=lazy;
		lazy=0;
		ans+=left->query(l, r, core);
		ans+=right->query(l, r, core);
		size=left->size+right->size;
		minval=min(left->minval,right->minval);
//		cout<<ans<<endl;
		return ans;
	}
};
vector<pair<pii,pii>> temp;
signed main()
{
	IO;
	int n,k,m;
	cin>>n>>k>>m;
	node* a=new node(1,n,k);
	int l,r,c,p;
//	cout<<"hola"<<endl;
	for(int i=0; i<m; i++)
	{
		cin>>l>>r>>c>>p;
		temp.pb({{p,c},{l,r}});
	}
	sort(temp.begin(),temp.end());
	int ans=0;
	for(auto te:temp)
	{
		int tol=a->query(te.se.fi, te.se.se, te.fi.se);
//		cout<<tol<<endl;
		ans+=tol*te.fi.fi;
	}
	cout<<ans<<endl;
}


ll powm(ll a,ll b, ll m)
{
	ll te=1;
	while(b)
	{
		if(b&1)
			te=(te*a)%m;
		a=(a*a)%m;
		b>>=1;
	}
	return te;
}