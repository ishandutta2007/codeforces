#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fr(i, n) for (ll i = 0; i < n; ++i)
#define frab(i, a, b) for (ll i = a; i < b; ++i)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pr;

const int N = 2e5 + 1;
const ll INF = 2e9;
const ll MAX = 2e6 + 1;
const ll ALPH = 300;
const ld PI = acos(-1);
const int MOD = 1e9 + 7;

char a[10][10];

int main() {
    srand(time(NULL));
    ios_base::sync_with_stdio(false);
    fr(i, 8)
        fr(j, 8)
            cin >> a[i][j];
    ll answ = INF, ansb = INF;
    fr(i, 8)
        fr(j, 8)
            if (a[i][j] == 'W') {
                bool er = false;
                for (int k = i - 1; k >= 0; k--)
                    if (a[k][j] != '.')
                        er = true;
                if (!er)
                    answ = min(answ, i);
            }
    fr(i, 8)
        fr(j, 8)
            if (a[i][j] == 'B') {
                bool er = false;
                for (int k = i + 1; k <= 7; k++)
                    if (a[k][j] != '.')
                        er = true;
                if (!er)
                    ansb = min(ansb, 8 - i - 1);
            }
    //cout << answ << " " << ansb << endl;
    if (answ <= ansb) {
        cout << "A";
    }
    else
        cout << "B";
}