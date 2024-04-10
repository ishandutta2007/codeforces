#include<bits/stdc++.h>
using namespace std;
using LL=long long;
#define FOR(i,l,r) for(int i=(l);i<=(r);++i)
#define REP(i,n) FOR(i,0,(n)-1)
#define ssize(x) int(x.size())
template<class A,class B>auto&operator<<(ostream&o,pair<A,B>p){return o<<'('<<p.first<<", "<<p.second<<')';}
template<class T>auto operator<<(ostream&o,T x)->decltype(x.end(),o){o<<'{';int i=0;for(auto e:x)o<<(", ")+2*!i++<<e;return o<<'}';}
#ifdef DEBUG
#define debug(x...) cerr<<"["#x"]: ",[](auto...$){((cerr<<$<<"; "),...)<<'\n';}(x)
#else
#define debug(...) {}
#endif

int main() {
	cin.tie(0)->sync_with_stdio(0);
    int tests;
    cin >> tests;
    REP (test, tests) {
        int n;
        cin >> n;
        vector<vector<int>> t(2, vector<int>(n));
        vector<int> sum(2);
        REP (i, 2) {
            REP (j, n) {
                char c;
                cin >> c;
                t[i][j] = c - '0';
                sum[i] += t[i][j];
            }
        }
        sum[1] = 0;
        vector<pair<int, int>> odp;
        REP (i, n) {
            if (t[0][i]) {
                odp.emplace_back(i + 1, i + 1);
            }
            sum[1] += (sum[0] & 1) ^ t[0][i] ^ t[1][i];
        }
        if (sum[1] && sum[1] != n) {
            cout << "NO\n";
            continue;
        }
        if (sum[1]) {
            odp.emplace_back(1, 1);
            odp.emplace_back(2, n);
            odp.emplace_back(1, n);
        }
        cout << "YES\n";
        cout << ssize(odp) << '\n';
        for (auto [a, b] : odp) {
            cout << a << ' ' << b << '\n';
        }
    }
}