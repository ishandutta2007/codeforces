#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <set>
#include <map>
#include <queue>
#include <ctime>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()

using namespace std;

const int P = (int)1e9 + 7;
const int MAXN = (int)1e5 + 10;

long long binPow(long long a, long long b) {
    if (a == 0)
        return 0;
    if (b == 0)
        return 1;
    long long c = binPow(a, b / 2);
    c = (c * c) % P;
    if (b & 1)
        return (c * a) % P;
    return c;
}

vector<long long> fact;
vector<long long> rfact;

long long choose(long long n, long long k) {
    return (fact[n] * rfact[k] % P) * rfact[n - k] % P;
}

int main() {
    int m;
    cin >> m;
    string s;
    cin >> s;
    int k = sz(s);

    fact.resize(MAXN);
    fact[0] = 1;
    for (int i = 1; i < MAXN; ++i)
        fact[i] = fact[i - 1] * i % P;

    rfact.resize(MAXN);
    for (int i = 0; i < MAXN; ++i)
        rfact[i] = binPow(fact[i], P - 2);


    vector<pair<int, int>> query, st;
    for (int i = 0; i < m; ++i) {
        int t;
        cin >> t;
        if (t == 1) {
            cin >> s;
            k = sz(s);
        }
        else {
            int n;
            cin >> n;
            query.push_back(make_pair(k, n));
        }
    }
    st = query;
    sort(all(query));

    map<pair<int, int>, int> res;

    for (int i = 0; i < sz(query); ++i) {
        int l = i;
        while (i < sz(query) - 1 && query[i].first == query[i + 1].first)
            ++i;
        int r = i + 1;
        int len = query[l].first;
        vector<long long> ans;
        ans.push_back(1);
        for (int j = 1; j < len; ++j)
            ans.push_back(ans.back() * 26 % P);
        ans.push_back((ans.back() * 26 - 1 + P) % P);
        long long pw = 25;
        for (int j = len + 1; j < MAXN; ++j) {
            long long tmp = ans.back() - (choose(j - 1, len - 1) * pw) % P;
            if (tmp < 0)
                tmp += P;
            ans.push_back((25 * ans.back() + tmp) % P);
            pw = pw * 25 % P;
        }
        pw = 1;
        for (int j = 0; j < MAXN; ++j) {
            ans[j] = pw - ans[j];
            if (ans[j] < 0)
                ans[j] += P;
            pw = (pw * 26) % P;
        }
        for (int j = l; j < r; ++j)
            res[query[j]] = (int)ans[query[j].second];
    }

    for (int i = 0; i < sz(st); ++i)
        cout << res[st[i]] << endl;
}