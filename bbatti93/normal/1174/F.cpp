#include <bits/stdc++.h>
#define FOR(i,n) for(int i = 0; i < (int)n; ++i)
#define REP(i,a,b) for(int i = (int)a; i < (int)b; ++i)
#define PER(i,a,b) for(int i = (int)b-1; i >= (int)a; --i)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define X first
#define Y second
#define pb push_back
template<class T> bool MX(T &l,const T &r){return l<r?l=r,1:0;}
template<class T> bool MN(T &l,const T &r){return l>r?l=r,1:0;}
using namespace std; typedef long long ll;
typedef vector<int> vi; typedef pair<int,int> pii;
const ll MOD = 1e9+7, N=200000;

int ans;
int n, a, b, e;
vector<vi> g(N);
vi l(N,-1), p(N), s(N);
vector<priority_queue<pii> > u(N);

int dfs(int me, int lev) {
	int ret=0;
	if(lev==e) ret++;
	l[me] = lev;
	for(int ne:g[me]) if(l[ne] == -1) {
        p[ne]=me;
		int v = dfs(ne, lev+1);
		u[me].push({v,ne});
		ret += v;
	}
	s[me] = ret;
	return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
	cin >> n;
	FOR(i,n-1) {
		cin >> a >> b; --a; --b;
		g[a].pb(b);
		g[b].pb(a);
	}
	cout << "d 1" << endl;
	cin >> e;
	dfs(0,0);
	int cur=0, cl=0, ne, la;
	while(e!=cl) {
		if(u[cur].size() == 1) {
            cur = u[cur].top().second;
            cl=l[cur];
        } else if(2*u[cur].top().first > s[cur]) {
			ne = cur;
			while(l[ne] != e) ne = u[ne].top().second;
			cout << "d " << ne+1 << endl;
			cin >> ans;
			if (ans == -1) return 0;
			if (ans == 0) {
                cout << "! " << ne+1 << endl;
                return 0;
            }
			FOR(i,ans/2) {
			    ne=p[ne];
            }
			cur = ne;
			cl = l[ne];
			u[cur].pop();
		} else {
			cout << "s " << cur+1 << endl;
			cin >> ans;
			if (ans == -1) return 0;
			cur = ans-1;
			++cl;
		}
	}
	cout << "! " << cur+1 << endl;
	return 0;
}