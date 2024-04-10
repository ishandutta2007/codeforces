#pragma GCC optimize("Ofast,unroll-loops,fast-math,inline,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,avx,avx2,abm,mmx,popcnt")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ldb;

vector<int> bits1[64], bits2[64];
vector<int> ind1[64], ind2[64];
vector<int> pref1[64], pref2[64];
int cur_ans = 0;

vector<ll> st1, st2;
vector<int> sz1 = {0}, sz2 = {0};

int get1(int l, int r, int cnt) {
    auto it1 = lower_bound(bits1[cnt].begin(), bits1[cnt].end(), l);
    auto it2 = upper_bound(bits1[cnt].begin(), bits1[cnt].end(), r);
    if (it2 != bits1[cnt].end())
        it2++;
    int L = (int) (it1 - bits1[cnt].begin());
    int R = (int) (it2 - bits1[cnt].begin());
    int ans = 0;
    for (int I = L; I < R; I += max(1, R - L - 1)) {
        int i = ind1[cnt][I];
        if (__builtin_popcountll(st1[i]) == cnt) {
            ans += max(0, min(r,  sz1[i + 1]) - max(l, sz1[i]));
        } else {
            assert(false);
        }
    }
    int add1 = 0;
    if (L + 1 <= R - 1)
        add1 = pref1[cnt][R - 1] - pref1[cnt][L + 1];
    /*int add2 = 0;
    for (int I = L + 1; I < R - 1; I++) {
        int i = ind1[cnt][I];
        add2 += max(0, sz1[i + 1] - sz1[i]);
    }
    assert(add2 == add1);*/
    ans += add1;
    return ans;
}

int get2(int l, int r, int cnt) {
    auto it1 = lower_bound(bits2[cnt].begin(), bits2[cnt].end(), l);
    auto it2 = upper_bound(bits2[cnt].begin(), bits2[cnt].end(), r);
    if (it2 != bits2[cnt].end())
        it2++;
    int L = (int) (it1 - bits2[cnt].begin());
    int R = (int) (it2 - bits2[cnt].begin());
    int ans = 0;
    for (int I = L; I < R; I += max(1, R - L - 1)) {
        int i = ind2[cnt][I];
        if (__builtin_popcountll(st2[i]) == cnt) {
            ans += max(0, min(r,  sz2[i + 1]) - max(l, sz2[i]));
        } else {
            assert(false);
        }
    }
    int add1 = 0;
    if (L + 1 <= R - 1)
        add1 = pref2[cnt][R - 1] - pref2[cnt][L + 1];
    /*int add2 = 0;
    for (int I = L + 1; I < R - 1; I++) {
        int i = ind1[cnt][I];
        add2 += max(0, sz1[i + 1] - sz1[i]);
    }
    assert(add2 == add1);*/
    ans += add1;
    return ans;
}

int cur_time = 1;

void push(ll x) {
    // first stack
    {
        while (!st1.empty() && st1.back() < x) {
            cur_ans -= get2(sz1[sz1.size() - 2], sz1.back(), __builtin_popcountll(st1.back()));
            int cnt = __builtin_popcountll(st1.back());
            bits1[cnt].pop_back();
            ind1[cnt].pop_back();
            pref1[cnt].pop_back();
            st1.pop_back();
            sz1.pop_back();
        }
        cur_ans += get2(sz1.back(), cur_time, __builtin_popcountll(x));
        int cnt = __builtin_popcountll(x);
        bits1[cnt].push_back(cur_time);
        ind1[cnt].push_back((int) st1.size());
        pref1[cnt].push_back(pref1[cnt].back() + cur_time - sz1.back());
        st1.push_back(x);
        sz1.push_back(cur_time);
    }
    // second stack
    {
        while (!st2.empty() && st2.back() > x) {
            cur_ans -= get1(sz2[sz2.size() - 2], sz2.back(), __builtin_popcountll(st2.back()));
            int cnt = __builtin_popcountll(st2.back());
            bits2[cnt].pop_back();
            ind2[cnt].pop_back();
            pref2[cnt].pop_back();
            st2.pop_back();
            sz2.pop_back();
        }
        cur_ans += get1(sz2.back(), cur_time, __builtin_popcountll(x));
        int cnt = __builtin_popcountll(x);
        bits2[cnt].push_back(cur_time);
        ind2[cnt].push_back((int) st2.size());
        pref2[cnt].push_back(pref2[cnt].back() + cur_time - sz2.back());
        st2.push_back(x);
        sz2.push_back(cur_time);
    }
}

void solve() {
    for (int i = 0; i < 64; i++) {
        pref1[i].push_back(0);
        pref2[i].push_back(0);
    }
    int n;
    cin >> n;
    ll tot_ans = 0;
    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        push(x);
        tot_ans += cur_ans;
        cur_time++;
    } 
    cout << tot_ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    while (t--) {
        solve();
    }
}