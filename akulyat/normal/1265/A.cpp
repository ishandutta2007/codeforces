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

void show(string s) {
    for (ll i = 1; i < s.size(); i++)
        if (s[i] == s[i-1]) {
            cout << "-1\n";
            return;
        }
    cout << s << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t;
    cin >> t;
    for (i = 0; i < t; i++) {
        string s;
        cin >> s;
        n = s.size();
        for (ll i = 0; i < n; i++) {
            if (s[i] == '?') {
                bool a, b, c;
                a = b = c = true;
                if (i > 0) {
                    if (s[i-1] == 'a')
                        a = false;
                    if (s[i-1] == 'b')
                        b = false;
                    if (s[i-1] == 'c')
                        c = false;
                }
                if (i < n - 1) {
                    if (s[i+1] == 'a')
                        a = false;
                    if (s[i+1] == 'b')
                        b = false;
                    if (s[i+1] == 'c')
                        c = false;
                }
                if (a)
                    s[i] = 'a';
                if (b)
                    s[i] = 'b';
                if (c)
                    s[i] = 'c';
            }
        }
        show(s);
    }


    return 0;
}