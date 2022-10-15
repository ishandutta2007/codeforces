#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define int ll
#define ld long double
#define pii pair<int, int>
#define f first
#define s second
#define boost() cin.tie(0), cin.sync_with_stdio(0)

const int MN = 505;

int n, k, a[MN], ret, lay[MN], tgt[MN];
bool cmp(int p, int q) {
    return tgt[p] > tgt[q];
}

int32_t main() {
    boost();

    cin >> n >> k;
    //if (n % 2 == 0 && k % 2 == 1) abort();
    int cnt = 0;
    for (int i = 1; i <= 500; i++) {
        int tmp = k * i;
        if (tmp >= n && tmp % 2 == n % 2) {
            int over = (tmp - n) / 2;
            int lays = ((over + n - 1) / n) * 2 + 1;
            if (lays > i) continue;
            cnt = i;
            break;
        }
    }
    if (!cnt) {
        cout << -1 << endl;
        return 0;
    }
    //printf("%d\n", cnt);
    int over = ((cnt * k) - n) / 2;
    int lays = ((over + n - 1) / n) * 2 + 1;
    while (over > n) over -= n;
    //printf("%d %d\n", over, lays);
    if (lays >= 3) {
        for (int i = 1; i <= over; i++) tgt[i] = lays;
        for (int i = over + 1; i <= n; i++) tgt[i] = lays - 2;
    } else for (int i = 1; i <= n; i++) tgt[i] = 1;
    vector<int> v;
    int id = over + 1;
    for (int i = 1; i <= cnt; i++) {
        vector<int> pos;
        for (int j = 1; j <= n; j++) pos.push_back(j);
        sort(pos.begin(), pos.end(), cmp);
        /*int st = 1;
        for (int j = 2; j <= over; j++) if (lay[j] < lay[j - 1]) {st = j; break;}
        int out = k;*/
        cout << "?";
        set<int> s;
        for (int i = 0; i < k; i++) {
            s.insert(pos[i]);
            lay[pos[i]]++;
            assert(tgt[pos[i]] >= 0);
            tgt[pos[i]]--;
            cout << " " << pos[i];
        }
        /*for (int i = st; i <= min(over, st + k - 1); i++) {
            if (lay[i] == lays) continue;
            lay[i]++;
            cout << " " << i;
            s.insert(i);
            out--;
        }
        for (int i = 1; i <= min(st - 1, max(0ll, k - (over - st + 1))); i++) {
            if (lay[i] == lays) continue;
            lay[i]++;
            cout << " " << i;
            s.insert(i);
            out--;
        }
        while (out) {
            lay[id]++;
            cout << " " << id;
            s.insert(id);
            id++;
            out--;
        }*/
        cout << endl;
        cin >> ret;
        v.push_back(ret);
        assert(s.size() == k);
        for (int p : s) assert(1 <= p && p <= n);
    }
    for (int i = 1; i <= n; i++) assert(lay[i] % 2);
    int ans = 0;
    for (int p : v) ans ^= p;
    cout << "! " << ans << endl;

    return 0;
}
/*
50 47
 */