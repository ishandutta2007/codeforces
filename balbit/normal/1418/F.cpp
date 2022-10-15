#include <bits/stdc++.h>
using namespace std;

#define ll long long

#ifdef BALBIT
#define bug(...) cerr<<"#"<<#__VA_ARGS__<<": ", _do(__VA_ARGS__)
template <typename T> void _do(T&&x) {cerr<<x<<endl;}
template <typename T, typename ...S> void _do(T &&x, S &&...y) {cerr<<x<<", ", _do(y...);}
#else
#define endl '\n'
#define bug(...)
#endif // BALBIT

#define pb push_back
#define pii pair<int, int>
#define f first
#define s second

const int maxn = 2e5+5;

vector<int>fac[maxn];
//set <int>here[maxn*4];

signed main(){
    ios::sync_with_stdio(0), cin.tie(0);

    int n,m;
    ll l,r; cin>>n>>m>>l>>r;
    for (int i = 1; i<=max(n,m); ++i) {
        for(int j = i; j<=max(n,m); j += i) {
            fac[j].pb(i);
        }
    }
    int lnow = m+1, rnow = m;
    map<int, int> now;
    for (int ab = 1; ab<=n; ++ab) {
        ll L = (l+ab-1)/ab, R = r/ab;
        while (lnow > L) {
            -- lnow;
            for(int c :fac[lnow]) {
//                bug("Inserting", c);
                now[c] = lnow/c;
//                now.insert({c,lnow});
            }
        }
        while (rnow > R) {
            for(int c :fac[rnow]) {
                if (now[c] == rnow/c) {
                    now.erase(c);
                }
//                now.erase({c,rnow});
            }
            -- rnow;
        }
//        if(ab) {
//            bug("Fac", ab);
//            for (pii pp : now) bug(pp.f, pp.s);
//        }
        bug(lnow, rnow, ab);
        bool done = 0;
        for (int a : fac[ab]) {
            int b = ab/a;
            int cL = b+1, cR = n/a;
            auto it = now.lower_bound(cL);
            if (it != now.end() && it-> f <= cR) {
                // c is found
                int c = it->f;
                int d = it->s;
                cout<<ab<<' '<<c*d<<' '<<a*c<<' '<<b*d<<endl;
                done = 1; break;
            }
        }
        if (!done) cout<<-1<<endl;
    }

}