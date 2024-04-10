/*
 * 	Roses are red
 * 		Violets are blue
 * 			I cried
 * 				And so did you
*/
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#ifndef rd
#define endl '\n'
#endif
#define pb push_back
#define fi first
#define se second
#define int long long
#define double long double
#define pii pair<int,int>
#define fr(a,b,c) for(int a=b; a<=c; a++)
#define all(con) con.begin(),con.end()
#define deb cout<<"Line: "<<__LINE__<<" plz "
typedef long long ll;
const ll inf=1e18;
const ll mod=1000000007;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll powm(ll a, ll b, ll m);

const int N = 1e5 + 5;
vector<int> g[N];
int a[N],b[N];
void solve(){
    int n, m;
    cin >> n >> m;
    fr(i, 1, m){
        int u, v;
        cin >> u >> v;
        if(u > v) swap(u, v);
        g[u].pb(v);
    }
    fr(i, 1, n){
        if(g[i].size() != n - i){
            cout << "YES" << endl;
            sort(all(g[i]));
            int pt = 0;
            g[i].pb(n+1);
            fr(j, i + 1, n){
                if(g[i][pt++] != j){
                	a[i]=i;
                	a[j]=i+1;
                	b[i]=i;
                	b[j]=i;
                	for(int ii=1,k=1; ii<=n; ii++)
                	{
                		while(k==i||k==i+1)
                			k++;
                		if(ii!=i&&ii!=j)
                		{	a[ii]=k;
                			b[ii]=k++;
                		}
                	}
                	for(int ii=1; ii<=n; ii++)
                	    cout<<a[ii]<<" ";
                	cout<<endl;
                	for(int ii=1; ii<=n; ii++)
                		cout<<b[ii]<<" ";
                	cout<<endl;
                	return;
                }
            }
        }
    }
    cout << "NO" << endl;
}
signed main()
{
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	srand(chrono::steady_clock::now().time_since_epoch().count());
	cout<<fixed<<setprecision(10);
	int t=1;
//	auto clk=clock();
//	cin>>t;
	while(t--)
		solve();
//#ifdef rd
//	clk=clock()-clk;
//	cout<<endl<<endl<< "Time Elapsed: " << ((double)clk)/CLOCKS_PER_SEC <<endl;
//#endif
	return 0;
}
ll powm(ll a,ll b, ll m) {
	ll te=1;
	while(b) {
		if(b&1) te=(te*a)%m;
		a=(a*a)%m;
		b>>=1;
	}
	return te;
}