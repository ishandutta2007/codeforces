#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < (int)n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

const ll MOD = 1e9 + 7;
const ld EPS = 1e-6;
const ll INF = 1e9 + 10;
const int M = 1e3 + 10;
const int N = 1e6 + 10;

int a[N];

int main() {
    //srand(time(NULL));
    ios_base::sync_with_stdio(false);
    //freopen("a.in", "r", stdin);
    int k;
    cin >> k;
    string s;
    cin >> s;
    int cur = 0;
    fr(i, s.size())
        a[s[i] - '0']++, cur += (s[i] - '0');
    int ans = 0;
    fr(i, 10)
        while (cur < k && a[i]) {
            cur += 9 - i;
            a[i]--;
            ans++;
        }
    cout << ans;
}