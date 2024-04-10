#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; ++i)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 2e5 + 5;
const int M = 500 * 1000 * 1000;
const ll MOD = 1000 * 1000 * 1000 + 7;
const ll INF = 2e9 + 10;
const ld EPS = 1e-7;

ll a[N];

int main() {
    //freopen("a.in", "r", stdin);
    int x;
    cin >> x;
    string s;
    cin >> s;
    if (s[3] >= '6')
        s[3] = '0';
    if (x == 12) {
        if (s[0] == '0' && s[1] == '0')
            s[0] = '1';
        else if (s[1] == '0' && s[0] > '1')
            s[0] = '1';
        else
            if (10 * (s[0] - '0') + s[1] - '0' > 12)
                s[0] = '0';
    }
    if (x == 24)
        if (10 * (s[0] - '0') + s[1] - '0' >= 24)
            s[0] = '0';
    cout << s;
}