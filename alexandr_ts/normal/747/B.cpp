#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; ++i)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 2e5 + 5;
const int M = 10001;
const ll MOD = 1000 * 1000 * 1000 + 7;
const ll INF = 2e9 + 10;
const ld EPS = 1e-7;

int main() {
    //freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    string s;
    cin >> s;
    int a1 = count(s.begin(), s.end(), 'A');
    int g1 = count(s.begin(), s.end(), 'G');
    int c1 = count(s.begin(), s.end(), 'C');
    int t1 = count(s.begin(), s.end(), 'T');
    if (n % 4 || a1 > n / 4 || g1 > n / 4 || c1 > n / 4 || t1 > n / 4) {
        cout << "===";
        return 0;
    }
    for (int i = 0; i < n; i++)
        if (s[i] == '?')
            if (a1 < n / 4)
                s[i] = 'A', a1++;
            else if (g1 < n / 4)
                s[i] = 'G', g1++;
            else if (c1 < n / 4)
                s[i] = 'C', c1++;
            else
                s[i] = 'T', t1++;
    cout << s;
}