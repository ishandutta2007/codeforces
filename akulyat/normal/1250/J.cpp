#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
typedef long long   ll;
typedef long double ld;
typedef pair<ll, ll> pll;

ifstream in;
ofstream out;

const long long kk = 1000;
const long long ml = kk * kk;
const long long mod = ml * kk + 7;
const long long inf = ml * ml * ml + 7;


ll n, i, j;
vector<ll> m;
bool viv = false;

void bad() {
    cout << "-1\n";
    exit(0);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (i = 0; i < n; i++) {
        ll a;
        cin >> a;
        m.push_back(a);
    }
    set<ll> was;
    set<ll> now;
    vector<ll> ans;
    ll las = 0;
    ll nw = 1;
    for (auto i : m) {
  //      cout << i << ' ' << endl;
        if (i > 0) {
            if (was.count(i))
                bad();
            was.insert(i);
            now.insert(i);
        }
        if (i < 0) {
            if (!now.count(-i))
                bad();
            now.erase(-i);
        }
        if (now.empty()) {
            was.clear();
            ans.push_back(nw - las);
            las = nw;
        }
//        cout << i << ' ' << endl;
        nw++;
    }
    if (now.size())
        bad();
    cout << ans.size() << endl;
    for (auto i : ans)
        cout << i << ' ';




    return 0;
}