#include <bits/stdc++.h>
#define fr(i, n) for (ll i = 0; i < n; i++)
#define frab(i, a, b) for (ll i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef pair <long long, long long> pr;
typedef long long ll;
typedef long double ld;

const ll MOD = 1e9 + 7;
const ll INF = 2e9;
const ll N = 1e5 + 2;
const ld EPS = 1e-8;

int a[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    int x, n;
    cin >> x >> n;
    fr(i, n) {
        int t, t1, t2;
        cin >> t;
        if (t == 2) {
            cin >> t1;
            a[t1] = 2;
        }
        else {
            cin >> t1 >> t2;
            a[t2] = 2;
            a[t1] = 1;
        }
    }
    int cnt = 0;
    int ansMin = 0, ansMax = 0;
    frab(i, 1, x)
        if (!a[i])
            cnt++;
        else {
            ansMax += cnt;
            ansMin += (cnt + 1) / 2;
            cnt = 0;
        }
            ansMax += cnt;
            ansMin += (cnt + 1) / 2;
    cout << ansMin << " " << ansMax;
}