#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair
using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 2e5 + 10;
const int M = 301;
const int INF = 2e9 + 10;
const int MOD = 1e9 + 7;

string s[N];
//bool cmp(string s, string t) {
//    return s.size() < t.size();
//}

int main() {
    //freopen("a.in", "r", stdin);
    ll l1, r1, l2, r2, k;
    cin >> l1 >> r1 >> l2 >> r2 >> k;
    ll l = max(l1, l2);
    ll r = min(r1, r2);
    if (l > r)
        cout << 0;
    else if (l <= k && k <= r)
        cout << r - l;
    else
        cout << r - l + 1;
}