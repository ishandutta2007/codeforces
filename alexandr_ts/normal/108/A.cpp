#include <bits/stdc++.h>
#define fr(i, n) for (ll i = 0; i < n; i++)
#define frab(i, a, b) for (ll i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef pair <long long, long long> pr;
typedef long long ll;
typedef long double ld;

const ll MOD = 1e6 + 3;
const ll INF = 2e9;
const ll N = 1e6 + 2;
const ll MAX = 2e5 + 2;
const ld EPS = 1e-8;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
   // freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    string s;
    cin >> s;
    int x = 10 * 60 * (s[0] - '0') + 60 * (s[1] - '0') + 10 * (s[3] - '0') + s[4] - '0';
    frab(i, x + 1, 24 * 60 * 60 + 1) {
        i %= 60 * 24;
        char a1, a2, a3, a4;
        int mins = i % 60;
        int hours = i / 60;
        a4 = ('0' + mins % 10);
        a3 = ('0' + mins / 10);
        a2 = ('0' + hours % 10);
        a1 = ('0' + hours / 10);
        if (a4 == a1 && a3 == a2) {
            cout << a1 << a2 << ":" << a3 << a4;
            return 0;
        }
        if (!i) break;
    }

}