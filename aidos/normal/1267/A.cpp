//By Don4ick 
//#define _GLIBCXX_DEBUG

#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;
typedef unsigned int ui;

#define forn(i, n) for (int i = 1; i <= n; i++)
#define pb push_back
#define all(x) x.begin(), x.end()
#define y1 qewr1234

#define s second
#define f first
#define mp make_pair

const double PI = acos(-1.0);
const int DIR = 4;

using namespace std;

pair<ll, pair<ll, ll> > a[200200];
int n;
                       
map<ll, vector<int> > X, M;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();		

	//freopen(".in", "r", stdin);
	//freopen(".out", "w", stdout);
	cin >> n;
	vector<ll> d;
	for(int i = 1; i <= n; i++) {
		cin >> a[i].f >> a[i].s.f >> a[i].s.s;
		a[i].s.f -= a[i].s.s;
		d.pb(a[i].f);
		d.pb(a[i].s.f);
		//M[a[i].f].pb(i);
		//X[a[i].s.f+1].pb(i);
	}
	sort(a+1, a + n + 1);
	sort(all(d));
	int t = 1;
	priority_queue<pair<ll, int> > S;
	ll ans = 0;
	ll x = 0;
	for(int i = 0; i < d.size(); ){
		int j = i;
		while(S.size() > 0 && a[S.top().s].s.f < x) {
			S.pop();
		}
		if(S.size() > 0) {
			ll len = -S.top().f;
			//cout << x << " " << len << " " << d[i] << "\n";
			ll cur = (d[i] - x)/len;
			x += cur * len;
			ans += cur;
			//cout << cur << "!\n";
		}
		
		ll mi = (ll)1e18+100;
		int ok = 0;
		if(S.size() > 0) {
			ll len = -S.top().f;
			mi = min(mi, x + len);
			ok = 1;
		}
		
		while(i < d.size() && d[i] < mi) {	
			while(t <= n && a[t].f <= d[i]){
				S.push(mp(-a[t].s.s, t));
				mi = min(d[i] + a[t].s.s, mi);
				ok = 1; 
				t++;
			}
			i++;
		}                 
		x = mi;
		ans+=ok;
		//cout << x << " "<< d[i] << " " << ans << "\n";
		//if(j == i) i++;
		//cout << ok << " " << x << "??\n";   
	}
	cout << ans << "\n";

	return 0;
}