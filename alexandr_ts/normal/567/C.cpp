#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fr(i, n) for (ll i = 0; i < (ll)n; i++)
#define frab(i, a, b) for (ll i = (ll)a; i < (ll)b; i++)

using namespace std;

typedef long long ll;

const ll N = 1e6 + 10;
const ll INF = 2e9;
const ll ALPH = 300;

ll a[N];

int main() {
    ios_base::sync_with_stdio(false);
    srand(time(NULL));
    //freopen("a.in", "r", stdin);
    ll n, k;
    cin >> n >> k;
    //multiset <ll> st2;
    map <ll, ll> st2, st;
    fr(i, n) {
        cin >> a[i];
        st2[a[i]]++;
    }
    //cout << -100 % 5 << endl;
    ll ans = 0;
    //multiset <ll> st;
    fr(i, n) {
        st2[a[i]]--;
        if (a[i] % k == 0) {
            //if (a[i] == -500)
               // cout << st.count(a[i] / k) << " " << st2.count(a[i] * k) << endl;
            if (st.count(a[i] / k) && st2.count(a[i] * k))
                ans += st[a[i] / k] * st2[a[i] * k];
        }
        st[a[i]]++;
    }
    cout << ans;
}