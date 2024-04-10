#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, n) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef pair <int, int> pr;
typedef long long ll;
typedef long double ld;

const ll MOD = 1e9 + 7;
const ll INF = 2e9;
const ll N = 1e6 + 1;
const ld EPS = 1e-8;

int f[N], b[N], a[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    int n, m;
    cin >> n >> m;
    fr(i, n)
        cin >> f[i];
    fr(i, m)
        cin >> b[i];
    map <int, vector <int> > mp;
    fr(i, n)
        mp[f[i]].pb(i);
    bool many = false, zero = false;
    fr(i, m) {
        if (mp[b[i]].size() == 1)
            a[i] = mp[b[i]][0];
        if (mp[b[i]].size() == 0)
            zero = true;
        if (mp[b[i]].size() > 1)
            many = true;
    }
    if (zero) {
        cout << "Impossible";
        return 0;
    }
    if (many) {
        cout << "Ambiguity";
        return 0;
    }
    cout << "Possible" << endl;
    fr(i, m)
        cout << a[i] + 1 << " ";

}