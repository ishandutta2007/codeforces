#include <iostream>
#include <map>

using namespace std;

const int MAXN = 100 * 1000 + 5;
int a[MAXN], st[2][4 * MAXN];
map<int, int> mp;

void add(int t, int v, int tl, int tr, int pos, int val) {
    if(tl == tr - 1) {
        st[t][v] += val;
        return;
    }
    int tm = (tl + tr) / 2;
    if(pos < tm)
        add(t, 2 * v, tl, tm, pos, val);
    else
        add(t, 2 * v + 1, tm, tr, pos, val);
    st[t][v] = st[t][2 * v] + st[t][2 * v + 1];
}

int get(int t, int v, int tl, int tr, int l, int r) {
    if(l == tl && r == tr)
        return st[t][v];
    int tm = (tl + tr) / 2, res = 0;
    if(l < tm)
        res += get(t, 2 * v, tl, tm, l, min(r, tm));
    if(r > tm)
        res += get(t, 2 * v + 1, tm, tr, max(l, tm), r);
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    long long k;
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        mp[a[i]];
    }
    int m = 0;
    for(map<int, int>::iterator it = mp.begin(); it != mp.end(); it++)
        it->second = m++;
    for(int i = 0; i < n; i++)
        a[i] = mp[a[i]];
    long long cnt = 0;
    for(int i = n - 1; i > 0; i--) {
        if(a[i] > 0)
            cnt += get(1, 1, 0, m, 0, a[i]);
        add(1, 1, 0, m, a[i], 1);
    }
    long long ans = 0;
    for(int i = 0, j = 1; i < n - 1; i++) {
        if(j == i) {
            if(a[j] < m - 1)
                cnt -= get(0, 1, 0, m, a[j] + 1, m);
            if(a[j] > 0)
                cnt -= get(1, 1, 0, m, 0, a[j]);
            add(1, 1, 0, m, a[j], -1);
            j++;
        }
        if(a[i] < m - 1)
            cnt += get(0, 1, 0, m, a[i] + 1, m);
        if(a[i] > 0)
            cnt += get(1, 1, 0, m, 0, a[i]);
        add(0, 1, 0, m, a[i], 1);
        while(j < n && cnt > k) {
            if(a[j] < m - 1)
                cnt -= get(0, 1, 0, m, a[j] + 1, m);
            if(a[j] > 0)
                cnt -= get(1, 1, 0, m, 0, a[j]);
            add(1, 1, 0, m, a[j], -1);
            j++;
        }
        ans += n - j;
    }
    cout << ans << '\n';
    return 0;
}