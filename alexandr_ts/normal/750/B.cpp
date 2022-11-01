#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair
using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 1e5 + 10;
const int M = 1e3 + 2;
const int INF = 2e9 + 10;
const int MOD = 1e9 + 7;

int main() {
    //freopen("a.in", "r", stdin);
    int n;
    cin >> n;
    int cur = 0;
    for (int i = 0; i < n; i++) {
        int x;
        string s;
        cin >> x >> s;
        if (s == "South") {
            if (x + cur > 20000) {
                cout << "NO";
                return 0;
            }
            else
                cur += x;
        }
        else if (s == "North") {
            if (cur - x < 0) {
                cout << "NO";
                return 0;
            }
            else
                cur -= x;
        }
        else {
            if (cur == 0 || cur == 20000) {
                cout << "NO";
                return 0;
            }
        }
    }
    if (cur == 0)
    cout << "YES";
    else
        cout << "NO";

}