#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; ++i)
#define frab(i, a, b) for (int i = a; i < b; ++i)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

const ll N = 1e5 + 10;
const ld EPS = 1e-8;
const ll INF = 2e9 + 10;
const ll MOD = 1e9 + 7;

string name(int n) {
    string ans;
    fr(i, 10) {
        ans += ('a' + n % 10);
        n /= 10;
    }
    ans[0] = toupper(ans[0]);
    return ans;
}

string ans[N];

int main() {
    //freopen("a.in", "r", stdin);
    //ios_base::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    fr(i, n - k + 1) {
        string typ;
        cin >> typ;
        if (typ == "YES") {
            if (i == 0) {
                fr(j, k)
                    ans[j] = name(j);
            }
            else
                ans[i + k - 1] = name(i + k);
        }
        else {
            if (i == 0) {
                fr(j, k - 1)
                    ans[j] = name(j);
                ans[k - 1] = ans[0];
            }
            else
                ans[i + k - 1] = ans[i];
        }

    }
    fr(i, n)
            cout << ans[i] << " ";
}