#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair
using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 2e5 + 10;
const int M = 501;
const int INF = 2e9 + 10;
const int MOD = 1e9 + 7;

ll a[N];

int main() {
    //freopen("a.in", "r", stdin);
    string s;
    cin >> s;
    if (s.size() % 2) {
        cout << -1;
        return 0;
    }
    int c1 = 0, c2 = 0;
    fr(i, s.size())
        if (s[i] == 'L')
            c1++;
        else if (s[i] == 'R')
            c1--;
        else if (s[i] == 'D')
            c2++;
        else c2--;
    c1 = abs(c1), c2 = abs(c2);
    int ans = 0;
    if (c1 % 2) {
        c1--, c2--, ans++;
    }
    cout << ans + c1 / 2 + c2 / 2;


}