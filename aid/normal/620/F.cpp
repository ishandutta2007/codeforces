#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 50 * 1000 + 5, K = 400, MAXB = (MAXN + K - 1) / K,
    MAXX = 1000 * 1000 + 5, LOGN = 17, LOGX = 20;
int s[MAXX], a[MAXN], st[MAXB][LOGN][MAXN], tr[20 * MAXX], logs[MAXN];

void add(int v, int h, int x) {
    tr[v]++;
    if(!h)
        return;
    add(2 * v + ((x >> (h - 1)) & 1), h - 1, x);
}

void del(int v, int h, int x) {
    tr[v]--;
    if(!h)
        return;
    del(2 * v + ((x >> (h - 1)) & 1), h - 1, x);
}

int get(int v, int h, int x) {
    if(!tr[v])
        return -1;
    if(!h)
        return 0;
    int res = get(2 * v + (((x >> (h - 1)) & 1) ^ 1), h - 1, x);
    if(res == -1)
        res = get(2 * v + ((x >> (h - 1)) & 1), h - 1, x);
    else
        res = (res ^ (1 << (h - 1)));
    return res;
}

int stGet(int b, int l, int r) {
    int k = logs[r - l + 1];
    return max(st[b][k][l], st[b][k][r - (1 << k) + 1]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    s[0] = 0;
    for(int i = 1; i < MAXX; i++)
        s[i] = (s[i - 1] ^ i);
    for(int i = 2; i < MAXN; i++)
        logs[i] = logs[i / 2] + 1;
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(int i = 0; i < n; i += K) {
        int b = i / K, l = i, r = min(i + K, n);
        vector< pair<int, int> > ev;
        for(int j = l; j < r; j++)
            ev.push_back(make_pair(a[j], -1));
        for(int j = 0; j < n; j++)
            ev.push_back(make_pair(a[j], j));
        sort(ev.begin(), ev.end());
        for(size_t j = 0; j < ev.size(); j++)
            if(ev[j].second == -1)
                add(1, LOGX, s[ev[j].first - 1]);
            else
                st[b][0][ev[j].second] = get(1, LOGX, s[ev[j].first]);
        for(int j = l; j < r; j++)
            del(1, LOGX, s[a[j] - 1]);
        for(int j = (int)ev.size() - 1; j >= 0; j--)
            if(ev[j].second == -1)
                add(1, LOGX, s[ev[j].first]);
            else
                st[b][0][ev[j].second] =
                    max(st[b][0][ev[j].second],
                        get(1, LOGX, s[ev[j].first - 1]));
        for(int j = l; j < r; j++)
            del(1, LOGX, s[a[j]]);
        for(int j = 1; j < LOGN; j++)
            for(int k = 0; k + (1 << j) <= n; k++)
                st[b][j][k] = max(st[b][j - 1][k], st[b][j - 1][k + (1 << (j - 1))]);
    }
    for(int qq = 0; qq < m; qq++) {
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        int lb = l / K, rb = r / K, ans = 0;
        for(int i = lb + 1; i < rb; i++)
            ans = max(ans, stGet(i, l, r));
        vector<int> v;
        for(int i = lb * K; i < (lb + 1) * K && i < n; i++)
            if(l <= i && i <= r)
                v.push_back(a[i]);
        if(lb != rb)
            for(int i = rb * K; i < (rb + 1) * K && i < n; i++)
                if(l <= i && i <= r)
                    v.push_back(a[i]);
        sort(v.begin(), v.end());
        for(size_t i = 0; i < v.size(); i++) {
            add(1, LOGX, s[v[i] - 1]);
            ans = max(ans, get(1, LOGX, s[v[i]]));
        }
        for(size_t i = 0; i < v.size(); i++)
            del(1, LOGX, s[v[i] - 1]);
        cout << ans << '\n';
    }
    return 0;
}