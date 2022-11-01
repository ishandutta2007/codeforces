#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef pair <long long, long long> pr;
typedef long long ll;
typedef long double ld;

const ll MOD = 1e9 + 7;
const ll INF = 2e9;
const ll N = 1e6 + 1;
const ld EPS = 1e-8;

ll a[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    ll n, k;
    cin >> n >> k;
    fr(i, n)
        cin >> a[i];
    map <ll, ll> m;
    fr(i, n)
        m[a[i]]++;
    if (k == 1) {
        cout << m.size();
        return 0;
    }
    for (auto it = m.begin(); it != m.end(); it++)
        if (m.count(k * it->first))
            m.erase(k * it->first);
    cout << m.size();

}