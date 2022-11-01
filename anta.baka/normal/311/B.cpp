#include <bits/stdc++.h>

using namespace std;

#define k first
#define l second

struct CHT {
    vector<pair<long long, long long>> st;
    int pt = 0;
    double X(pair<long long, long long> a, pair<long long, long long> b) {
        return (.0 + b.l - a.l) / (a.k - b.k);
    }
    void add_line(long long k, long long l) {
        pair<long long, long long> line = {k, l};
        while(st.size() > 1) {
            int sz = st.size();
            if(X(st[sz - 2], st[sz - 1]) < X(st[sz - 1], line)) break;
            st.pop_back();
            if(pt == sz - 1)
                pt--;
        }
        st.push_back(line);
    }
    long long get_val(long long x) {
        while(pt + 1 < st.size() && X(st[pt], st[pt + 1]) <= x)
            pt++;
        return st[pt].k * x + st[pt].l;
    }
};

int n, m, p;
long long d[100000];
long long cat[100000];
long long pref[100000];
long long dp[100][100000];
CHT cht[100];
vector<bool> otr(100000, false);

long long cost(int i, int j) {
    return pref[j] - pref[i] - i * (cat[j] - cat[i]);
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //freopen("input.txt", "r", stdin);
    cin >> n >> m >> p;
    for(int i = 1; i < n; i++) {
        cin >> d[i];
        d[i] += d[i - 1];
    }
    for(int i = 0; i < m; i++) {
        long long x, y;
        cin >> x >> y;
        --x;
        cat[i] = y - d[x];
    }
    sort(cat, cat + m);
    long long x0 = cat[0];
    for(int i = 0; i < m; i++)
        cat[i] -= x0;
    pref[0] = 0;
    for(int i = 1; i < m; i++)
        pref[i] = pref[i - 1] + (cat[i] - cat[i - 1]) * i;
    //
    for(int j = 0; j < p; j++)
        dp[j][0] = 0;
    for(int j = 0; j < p; j++)
        cht[j].add_line(-1, -pref[1] + cat[1]);
    for(int i = 1; i < m; i++) {
        dp[0][i] = pref[i];
        for(int j = 1; j < p; j++)
            dp[j][i] = pref[i] + cht[j - 1].get_val(cat[i]);
        for(int j = 0; j < p; j++)
            cht[j].add_line(-(i + 1), dp[j][i] - pref[i + 1] + (i + 1) * cat[i + 1]);
    }
    cout << dp[p - 1][m - 1];
}