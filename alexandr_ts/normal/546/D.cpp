#include <bits/stdc++.h>
#define fr(i, n) for (ll i = 0; i < n; i++)
#define frab(i, a, b) for (ll i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 6e6 + 10;
const ll INF = 2e9;
const ld EPS = 1e-8;
const int MAX = 6e6 + 1;

ll pref[N], cntDivs[N];
ll prDiv[N];
bool used[N];

int main() {
    //freopen("input.txt", "r", stdin);
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    ll n, a, b;
    used[0] = used[1] = true;
    frab(i, 2, MAX)
        if (!used[i]) {
            prDiv[i] = 1;
            for (int j = 2 * i; j < MAX; j += i)
                used[j] = true, prDiv[j] = i;
        }
    cin >> n;
    //cntDivs[0] = 1;
    cntDivs[1] = 0;
    cntDivs[2] = 1;
    frab(i, 3, MAX) {
        cntDivs[i] = cntDivs[i / prDiv[i]] + 1;
    }
    //frab(i, 1, 11)
      //  cout << i << " " << cntDivs[i] << endl;

    pref[0] = 0;
    frab(i, 1, MAX)
        pref[i] = pref[i - 1] + cntDivs[i];

    fr(i, n) {
        scanf("%d %d", &a, &b);
        printf("%d\n", pref[a] - pref[b]);
        //cout << pref[a] - pref[b] << endl;
    }
}