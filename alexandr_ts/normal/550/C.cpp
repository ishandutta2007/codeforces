#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fr(i, n) for (ll i = 0; i < n; i++)
#define frab(i, a, b) for (ll i = a; i < b; i++)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pr;

const int N = 4e5;
const int INF = 2e9 + 1;

ll a[N];

int main() {
    //freopen("input.txt", "r", stdin);
    string s;
    cin >> s;
    fr(i, s.size())
        if (s[i] == '0') {
            cout << "YES\n0";
            return 0;
        }
        else if (s[i] == '8') {
            cout << "YES\n8";
            return 0;
        }

    fr(i, s.size())
        frab(j, i + 1, s.size())
            if ((10 * (s[i] - '0') + s[j] - '0') % 8 == 0) {
                cout << "YES\n" << s[i] << s[j];
                return 0;
            }

    fr(i, s.size())
        frab(j, i + 1, s.size())
            frab(k, j + 1, s.size())
                if ((100 * (s[i] - '0') + 10 * (s[j] - '0') + s[k] - '0') % 8 == 0) {
                    cout << "YES\n" << s[i] << s[j] << s[k];
                    return 0;
                }
    cout << "NO";
}