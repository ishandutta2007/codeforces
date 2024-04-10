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


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    int up = 0;
    vector <ll> ans;
    for (i = 0; i < n; i++) {
        ll a;
        cin >> a;
        m.push_back(a);
        if (a & 1) {
            ll k = 0;
            if (up & 1) {
                if (a > 0)
                    k = (a+1) / 2;
                else
                    k = (a) / 2;
            } else {
                if (a < 0)
                    k = (a-1) / 2;
                else
                    k = (a) / 2;
            }
            ans.push_back(k);

            up++;
        } else {
            ans.push_back(a/2);
        }
    }
    for (auto i : ans)
        cout << i << '\n';



    return 0;
}