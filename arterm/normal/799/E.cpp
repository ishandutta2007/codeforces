#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
typedef long double ld;
typedef long long ll;

const int M = 200200;
const ll infl = 1e18;

int n, m, k;
int c[M];
int x[M];
vector<int> a[4];
vector<ll> pref[4];

multiset<int> A, B;
ll sum = 0;

void add(int x) {
    if (A.empty() || x >= *A.rbegin())
        B.insert(x);
    else {
        A.insert(x);
        sum += x;
    }
}

void rem(int x) {
    auto af = A.find(x);
    if (af != A.end()) {
        sum -= x;
        A.erase(af);
    } else {
        B.erase(B.find(x));
    }
}

void shift(int n) {
    while ((int) A.size() > n) {
        auto last = --A.end();
        sum -= *last;
        B.insert(*last);
        A.erase(last);
    }

    while ((int) A.size() < n && !B.empty()) {
        auto front = B.begin();
        sum += *front;
        A.insert(*front);
        B.erase(front);
    }
}

void prf(const vector<int> &a, vector<ll> &b) {
    b.push_back(0);
    for (int x : a)
        b.push_back(b.back() + x);
}

void read() {
    cin >> n >> m >> k;
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
    }

    int a;
    cin >> a;
    for (int i = 0; i < a; ++i) {
        int id;
        cin >> id;
        --id;
        x[id] |= 1;
    }

    cin >> a;
    for (int i = 0; i < a; ++i) {
        int id;
        cin >> id;
        --id;
        x[id] |= 2;
    }
}

void kill() {
    for (int i = 0; i < n; ++i)
        a[x[i]].push_back(c[i]);

    for (int i = 0; i < 4; ++i) {
        sort(all(a[i]));
        prf(a[i], pref[i]);
    }


    int mid = min<int>(k, a[3].size());
   
    if (k - mid > min<int>(a[1].size(), a[2].size())) {
        cout << "-1\n";
        return;
    }

    if (k > m) {
        cout << "-1\n";
        return;
    }

    for (int x : a[0])
        add(x);

    for (int i = k - mid; i < (int) a[1].size(); ++i)
        add(a[1][i]);

    for (int i = k - mid; i < (int) a[2].size(); ++i)
        add(a[2][i]);

    for (int i = mid; i < (int) a[3].size(); ++i)
        add(a[3][i]);

    ll ans = infl;
    while (true) {

        int taken = (k - mid) + (k - mid) + mid;
        int need = m - taken;

        if (need >= 0) {
            shift(need);

            ll cost = sum + pref[1][k - mid] + pref[2][k - mid]
                + pref[3][mid];

            ans = min(ans, cost);
        }

        --mid;
        if (mid < 0) {
            break;
        }
        if (k - mid > min<int>(a[1].size(), a[2].size()))
            break;

        add(a[3][mid]);
        rem(a[1][k - mid - 1]);
        rem(a[2][k - mid - 1]);
    }

    if (ans == infl)
        ans = -1;
    cout << ans << "\n";
}


int main() {
#ifdef LOCAL
  assert(freopen("e.in", "r", stdin));
#endif

  ios_base::sync_with_stdio(false);

  read();
  kill();
}