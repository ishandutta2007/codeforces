#include <iostream>
#include <string>

using namespace std;

const int MAXN = 5000 + 5;
int l[MAXN], r[MAXN], m;
pair<int, char *> segs[2 * MAXN];
string s;

string get(int l, int r) {
    string res;
    for(int i = 0; i < m && r > 0; i++) {
        if(segs[i].first > l) {
            int ls = max(l, 0), rs = min(r, segs[i].first);
            for(int j = ls; j < rs; j++)
                res += segs[i].second[j];
        }
        l -= segs[i].first;
        r -= segs[i].first;
    }
    return res;
}

int split(int pos) {
    int res = 0;
    while(res < m && segs[res].first <= pos) {
        pos -= segs[res].first;
        res++;
    }
    if(res == m) {
        m++;
        return res;
    }
    if(!pos) {
        m++;
        for(int i = m - 1; i > res; i--)
            segs[i] = segs[i - 1];
        return res;
    }
    m += 2;
    for(int i = m - 1; i > res + 1; i--)
        segs[i] = segs[i - 2];
    segs[res + 2] = make_pair(segs[res].first - pos, segs[res].second + pos);
    segs[res].first = pos;
    return res + 1;
}

void build(int pos, int k) {
    if(pos < 0) {
        segs[m] = make_pair(k, new char[k]);
        for(int i = 0; i < k; i++)
            segs[m].second[i] = s[i];
        m++;
        return;
    }
    if(r[pos] >= k) {
        build(pos - 1, k);
        return;
    }
    int len = r[pos] - l[pos], x = min(k, r[pos] + len) - r[pos];
    build(pos - 1, k - x);
    int p = split(r[pos]);
    string t = get(l[pos], min(r[pos], l[pos] + 2 * x));
    segs[p] = make_pair(x, new char[x]);
    for(int i = 0; i < x; i++)
        segs[p].second[i] = i < len / 2? t[2 * i + 1] : t[2 * (i - len / 2)];
}

int main() {
    ios_base::sync_with_stdio(false);
    int k, n;
    cin >> s >> k >> n;
    for(int i = 0; i < n; i++) {
        cin >> l[i] >> r[i];
        l[i]--;
    }
    build(n - 1, k);
    string ans = get(0, k);
    cout << ans << '\n';
    return 0;
}