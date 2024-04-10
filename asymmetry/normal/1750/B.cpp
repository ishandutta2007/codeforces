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
        vector<int> t(n);
        vector<int> sum(2), mx(2), cur(2);
        REP (i, n) {
            char c;
            cin >> c;
            t[i] = c - '0';
            ++cur[t[i]];
            cur[t[i] ^ 1] = 0;
            mx[t[i]] = max(mx[t[i]], cur[t[i]]);
            ++sum[t[i]];
        }
        cout << max({(LL)mx[0] * mx[0], (LL)mx[1] * mx[1], (LL)sum[0] * sum[1]}) << endl;
    }
}