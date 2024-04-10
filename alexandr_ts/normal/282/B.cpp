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
const ll N = 1e3 + 2;
const ll MAX = 2e5 + 2;
const ld EPS = 1e-8;

struct tmp {
    int x, pos;
} a[N];

bool cmp(tmp a, tmp b) {
    return abs(a.x) > abs(b.x);
}

char ans[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    int n, t1, t2;
    cin >> n;
    ll sum = 0;
    fr(i, n) {
        cin >> t1 >> t2;
        sum += t1;
    }
    ll ans = (sum + 500) / 1000;
    if (ans > n)
        cout << -1;
    else
    {
        for (int i = 0; i < ans; i++)
            cout << 'G';
        fr(i, n - ans)
            cout << 'A';
    }

}