#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fr(i, n) for (int i = 0; i < n; ++i)
#define frab(i, a, b) for (int i = a; i < b; ++i)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pr;

const int N = 2e2 + 1;
const ll INF = 3e18;
const ll MAX = 1e6 + 1;
const ll ALPH = 300;
const ld EPS = 1e-12;
const ll MOD = 1e9 + 7;
string s[N];


int a[N];
int main() {
    string s;
    cin >> s;
    ll l = 0, r = 0;
    ll pos;
    fr(i, s.size())
        if (s[i] == '^')
            pos = i;
    fr(i, s.size())
        if (i < pos && isdigit(s[i]))
            l += (pos - i) * (s[i] - '0');
        else if (i > pos && isdigit(s[i]))
            r += (i - pos) * (s[i] - '0');
    if (l == r)
        cout << "balance";
    else if (l > r)
        cout << "left";
    else
        cout << "right";
}