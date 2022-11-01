#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 2e5 + 5;
const int M = 500 * 1000 * 1000;
const ll MOD = 1000 * 1000 * 1000 + 7;
const ll INF = 2e9 + 10;

int a[N], r[N];
int n;
string s;

void countR() {
    int mn = INF;
    fr(i, n) {
        mn = a[s[i] - 'a'];
        r[i] = 1;
        for (int j = i + 1; j < n; j++) {
            mn = min(mn, a[s[j] - 'a']);
            if (j - i + 1 <= mn)
                r[i]++;
        }
    }
}

ll d[N];

void solve1() {
    fr(i, r[0])
        d[i] = 1;
    fr(i, n - 1)
        frab(j, i + 1, i + 1 + r[i + 1])
            d[j] = (d[j] + d[i]) % MOD;
}

int solve3() {
    int ans = 0;
    int cur = -1;
    while (cur < n - 1) {
        ans++;
        cur += r[cur + 1];
    }
    return ans;
}

int main() {
    //freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n;
    cin >> s;
    fr(i, 26)
        cin >> a[i];
    countR();
    //fr(i, n)
     //   cout << r[i] << " ";cout << endl;

    solve1();
    //fr(i, n)
    //    cout << d[i] << " ";cout << endl;

    cout << d[n - 1] << endl;
    cout << *max_element(r, r + n) << endl;
    cout << solve3();

}