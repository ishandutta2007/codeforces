/*
 * Words like "tomorrow" or "future" or "fate"
 *		No matter how far they extend their hands
 *			We breathe, we dream, we raise our love
 *				In a timeless land that is far out of reach
 */
#include <bits/stdc++.h>
#define IO ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#ifndef rd
#define endl '\n'
#endif
#define pii pair<int,int>
#define pb push_back
#define fi first
#define se second
#define int long long
#define double long double
#define fr(a,b,c) for(int a=b; a<=c; a++)
typedef long long ll;
using namespace std;
const ll mod=1e9+7;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll powm(ll a, ll b, ll m);
int x;
int getNextX()
{
	x = (x * 37 + 10007) % 1000000007;
	return x;
}
int a[100001],b[100001],ans[100001],reva[100001];
signed main()
{
	IO;
	int n,d;
	cin>>n>>d>>x;
	for(int i = 0; i < n; i = i + 1){
	        a[i] = i + 1;
	    }
	    for(int i = 0; i < n; i = i + 1){
	        swap(a[i], a[getNextX() % (i + 1)]);
	    }
	    for(int i = 0; i < n; i = i + 1){
	        if (i < d)
	            b[i] = 1;
	        else
	            b[i] = 0;
	    }
	    for(int i = 0; i < n; i = i + 1){
	        swap(b[i], b[getNextX() % (i + 1)]);
	    }
	    vector<int> pos;
	    for(int i=0; i<n; i++)
	    	if(b[i])
	    		pos.pb(i);
	    if(d<=2000)
	    {
	    	for(int i:pos)
	    		for(int j=0; j<n-i; j++)
	    			ans[i+j]=max(ans[(i+j)%n],a[j]);
	    	for(int i=0; i<n; i++)
	    		cout<<ans[i]<<endl;
	    }
	    else
	    {
	    	for(int i=0; i<n; i++)
	    		reva[a[i]]=i;
	    	set<int> nums;
	    	for(int i=0; i<n; i++)
	    		nums.insert(i);
	    	vector<int> tel;
	    	for(int i=n; i>0; i--)
	    	{
	    		tel.clear();
	    		for(int j:nums)
	    			if(j>=reva[i]&&b[j-reva[i]])
	    			{
	    				ans[j]=i;
	    				tel.pb(j);
	    			}
	    		for(int j:tel)
	    			nums.erase(j);
	    	}
	    	for(int i=0; i<n; i++)
	    		cout<<ans[i]<<endl;
	    }
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