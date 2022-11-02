#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn = 5e6 + 100;
int n;
int L[maxn];
int R[maxn];
string s;
vector< pair<int, int> > d;
vector<int> le, ri;
int pref[maxn];
int pref2[maxn];
int first_o[maxn];
int first2_o[maxn];
int ans[maxn];
int p[maxn];
int rec(int l, int r, int &st, int &curL, int &curR) {
    if(r - l <= 1) {
        return true;
    }
    if(!(s.size() - st >= curL && s.size() - st <= curR)) return false;
    int m = (l + r) >> 1;
    if(!rec(l, m, st, curL, curR)) return false;
    if(!rec(m, r, st, curL, curR)) return false;
    ans[d.size()] = st;
    d.push_back({l, r});
    le.push_back(m-l);
    ri.push_back(r-m);
    int len1 = le.back();
    int len2 = ri.back();
    int sum1 = pref[st] + len2;
    int sum2 = pref2[st] + len1;
    curL -= min(m-l, r-m);
    curR -= r-l-1;
    if(first_o[sum1] == -1 && first2_o[sum2] == -1) {
        return false;
    }
    if(first_o[sum1] == -1) {
        st = first2_o[sum2];
        return true;
    }
    if(first2_o[sum2] == -1) {
        st = first_o[sum1];
        return true;
    }
    if(first_o[sum1] < first2_o[sum2]) {
        st = first_o[sum1];
        return true;
    }
    st = first2_o[sum2];
    return true;
}
bool check() {
    int last = 0;
    for(int i = 0; i < d.size(); i++) {
        ans[i] = last;
        int len1 = le[i];
        int len2 = ri[i];
        int sum1 = pref[last] + len2;
        int sum2 = pref2[last] + len1;
        if(first_o[sum1] == -1 && first2_o[sum2] == -1) {
            return false;
        }
        if(first_o[sum1] == -1) {
            last = first2_o[sum2];
            continue;
        }
        if(first2_o[sum2] == -1) {
            last = first_o[sum1];
            continue;
        }
        if(first_o[sum1] < first2_o[sum2]) {
            last = first_o[sum1];
            continue;
        }
        last = first2_o[sum2];
    }
    return last == s.size();
}
void restore(int cur, int pos) {
    if(cur < 0) return;
    int st = ans[cur];
    int en = pos;
    int l = d[cur].first;
    int r = d[cur].second;
    vector<int> A, B, C;
    for(int i = l; i < r; i++) {
        A.push_back(p[i]);
    }
    int P=0;
    for(int i = st; i < en; i++) {
        if(s[i] == '0') {
            B.push_back(A[P]);
            P++;
        } else {
            C.push_back(A[P]);
            P++;
        }
    }
    while(B.size() < le[cur]) {
        B.push_back(A[P]);
        P++;
    }
    while(C.size() < ri[cur]) {
        C.push_back(A[P]);
        P++;
    }
    int m = (l + r)/2;
    for(int i = l; i < m; i++) {
        p[i]=B[i-l];
    }
    for(int i = m; i < r; i++) {
        p[i]=C[i-m];
    }
    restore(cur-1, ans[cur]);
}
void solve() {
    cin >> s;
    for(int i = 2; i <= 100000; i++) {
        L[i] = L[i/2] + L[i - i/2];
        R[i] = R[i/2] + R[i- i/2];
        L[i] += i/2;
        R[i] += i-1;
    }
    for(int i = 1; i <= s.size(); i++) {
        pref[i] = pref[i-1] + s[i-1] - '0';
        pref2[i] = pref2[i-1] + '1' - s[i-1];

    }
    memset(first_o, -1,sizeof first_o);

    memset(first2_o, -1, sizeof first2_o);

    for(int i = s.size(); i >= 0; i--) {
        first_o[pref[i]] = i;
        first2_o[pref2[i]] = i;
    }
    for(int i = 1; i < maxn; i++) {
        p[i] = i;
    }
    for(int i = 100000; i >= 0; i--) {
        if(L[i] <= s.size() && s.size() <= R[i]) {
            d.clear();
            le.clear();
            ri.clear();
            int cur = 0;
            int curL = L[i];
            int curR = R[i];
            if(rec(0, i, cur, curL, curR)) {
                if(cur != s.size()) continue;
                restore(d.size()-1, s.size());
                cout << i << "\n";
                for(int j = 0; j < i; j++) {
                    cout << p[j] + 1 << " ";
                }
                return;
            }
        }
    }
}

int main() {
    int t = 1;
    //cin >> t;
    for(int i = 1; i <= t; i++) {
        //printf("Case %d:\n", i);
        solve();
    }

    return 0;
}