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

int a[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
   // freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ll n;
    cin >> n;
    map <int, set <int> > m;
    vector <int> divs;
    frab(i, 1, n + 1)
        if (n % i == 0)
            divs.pb(i);
    fr(i, divs.size()) {
        if (divs[i] != 1)
            m[divs[i]].insert(1);
        frab(j, 2, sqrt(divs[i]) + 1)
            if (divs[i] % j == 0)
                m[divs[i]].insert(j), m[divs[i]].insert(divs[i] / j);
    }
    fr(i, divs.size()) {
        if (divs[i] != 1) a[divs[i]] = -INF;
        for (auto it = m[divs[i]].begin(); it != m[divs[i]].end(); it++)
            a[divs[i]] = max(a[divs[i]], a[*it]);
        a[divs[i]]++;
    }
    vector <int> answ;
    int cur = n;
    while (cur != 1) {
        for (auto it = m[cur].begin(); it != m[cur].end(); it++)
            if (a[*it] + 1 == a[cur]) {
                cur = *it;
                answ.pb(cur);
                break;
            }
    }
    cout << n << " ";
    fr(i, answ.size())
        cout << answ[i] << " ";

}