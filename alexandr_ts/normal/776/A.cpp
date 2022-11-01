#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 2e5 + 1;
const int M = 1e3 + 2;
const ll INF = 2e9 + 7;
const ll MOD = 1000 * 1000 * 1000 + 7;
const ld EPS = 1e-10;

int a[N];

int main() {
    //freopen("a.in", "r", stdin);
    //ios_base::sync_with_stdio(false);
    string s, t;
    cin >> s >> t;
    int n;
    cin >> n;
    cout << s << " " << t << endl;
    fr(i, n) {
        string s1, s2;
        cin >> s1 >> s2;
        if (s1 == s) {
            s = s2;
        }
        else if (s2 == s)
            s = s1;
        else if (s1 == t)
            t = s2;
        else if (s2 == t)
            t = s1;
        cout << s << " " << t << endl;
    }
}