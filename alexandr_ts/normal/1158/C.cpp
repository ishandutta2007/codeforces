#include <bits/stdc++.h>
#define fr(i, n) for (ll i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<vector<ll> > mat;

const ld PI = acos(-1);
const ll INF = 1e15 + 10;
const int LOG = 20;
const ll MOD = 1e9 + 7;
const int N = 1e6 + 10;

int a[N];

int fenw[N];

void add(int i, int val, int n) {
    while (i < n) {
        fenw[i] += val;
        i = (i | (i + 1));
    }
}

int sum(int i) {
    int ans = 0;
    while (i >= 0) {
        ans += fenw[i];
        i = (i & (i + 1)) - 1;
    }
    return ans;
}

int ans[N];


void build(int tl, int tr, int firstNum) {
    if (tl > tr) return;
    vector<int> inds;
    int cur = tl;
    while (cur != tr) {
        inds.pb(cur);
        cur = a[cur];
    }
    inds.pb(cur);

    for (int i = 0; i + 1 < (int)inds.size(); i++) {
        ans[inds[i]] = inds[i + 1] - tl + firstNum - 1;
        build(inds[i] + 1, inds[i + 1], firstNum + inds[i] - tl);
    }
}

bool check(int n) {
    vector<int> answ(n, 0);
    a[n] = n + 1;
    vector<int> st = {n};

    for (int i = n - 1; i >= 0; i--) {
        while (a[st.back()] < a[i])
            st.pop_back();
        answ[i] = st.back() + 1;
        st.push_back(i);
    }

    for (int i = 0; i < n; i++)
        if (answ[i] != a[i])
            return false;
    return true;
}

int summ(int l, int r) {
    if (l > r) return 0;
    return sum(r) - (l ? sum(l - 1) : 0);
}

void solve() {
    int n;
    cin >> n;

    fill(ans, ans + n + 2, 0);
    fill(a, a + n + 2, 0);
    fill(fenw, fenw + n + 2, 0);

    fr(i, n) {
        cin >> a[i];
        a[i]--;
        if (a[i] == -2)
            a[i] = i + 1;
    }

//    fr(i, n)
//        cout << a[i] << " ";cout << endl;

    fr(i, n) {
        if (a[i] <= i) {
            cout << "-1\n";
            return;
        }
    }

    fr(i, n) {
        int nxt = a[i];
        if (summ(i + 1, nxt - 1) > 0) {
            cout << "-1\n";
            return;
        }
        add(nxt, 1, n);
    }

    build(0, n, 1);

    for (int i = 0; i < n; i++)
        cout << ans[i] << " ";
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //freopen("a.in", "r", stdin);
    int t;
    cin >> t;
    while (t--)
        solve();

}