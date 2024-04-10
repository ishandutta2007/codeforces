#include <bits/stdc++.h>
#define frab(i, a, b) for (ll i = a; i < b; i++)
#define fr(i, n) for (ll i = 0; i < n; i++)
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <ll, ll> pr;

const ll M = 2e4 + 10;
const ll INF = 2e9 + 10;
const ll N = 2e2 + 10;
const ll MOD = 1e9 + 7;

bool d[N][N][N];

int main() {
    //freopen("sweets.in", "r", stdin);
    int n;
    cin >> n;
    string s;
    cin >> s;
    int c1 = 0, c2 = 0, c3 = 0;
    fr(i, n)
        if (s[i] == 'G')
            c1++;
        else if (s[i] == 'R')
            c2++;
        else
            c3++;
    d[c1][c2][c3] = true;
    for (int len = n; len >= 2; len--)
        frab(i1, 0, len + 1)
            frab(i2, 0, len + 1 - i1) {
                int i3 = len - i1 - i2;
                if (!d[i1][i2][i3]) continue;
                if (i1 >= 2) d[i1 - 1][i2][i3] = true;
                if (i2 >= 2) d[i1][i2 - 1][i3] = true;
                if (i3 >= 2) d[i1][i2][i3 - 1] = true;
                if (i1 && i2) d[i1 - 1][i2 - 1][i3 + 1] = true;
                if (i1 && i3) d[i1 - 1][i2 + 1][i3 - 1] = true;
                if (i2 && i3) d[i1 + 1][i2 - 1][i3 - 1] = true;
            }
    if (d[0][0][1])
        cout << 'B';
    if (d[1][0][0])
        cout << 'G';
    if (d[0][1][0])
        cout << 'R';


}