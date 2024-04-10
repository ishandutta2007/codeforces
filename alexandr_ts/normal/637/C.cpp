#include <bits/stdc++.h>
#define frab(i, a, b) for (int i = a; i < b; i++)
#define fr(i, n) for (int i = 0; i < n; i++)
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <ll, ll> pr;

const ll M = 2e6 + 10;
const ll INF = 2e9 + 10;
const ll N = 1e5 + 10;
const ll MOD = 1e9 + 7;

char s[N][6];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //srand(time(NULL));
    int n;
    cin >> n;
    fr(i, n)
        fr(j, 6)
            cin >> s[i][j];
    if (n == 1) {
        cout << 6;
        return 0;
    }
    int mx = 0;
    fr(i, n)
        frab(j, i + 1, n) {
            int cnt = 0;
            fr(i1, 6)
                if (s[i][i1] == s[j][i1])
                    cnt++;
            mx = max(mx, cnt);
        }
    if (mx == 6 || mx == 5 || mx == 4)
        cout << 0;
    else if (mx == 3 || mx == 2)
        cout << 1;
    else
        cout << 2;
}