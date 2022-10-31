#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
 
using namespace std;
 
//vector string deque break continue
#define forn(i, s, f) for (int i = (int)s; i < (int)f; i++)
#define ll long long
#define ull unsigned long long
#define ld long double
#define pii pair <int, int>
#define fs first
#define sc second
#define pf push_front
#define pb push_back
#define pop_f pop_front
#define pop_b pop_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()

vector<int> Less(vector<int> a) {
    stack<int> s;
    vector<int> res(sz(a), 0);
    for (int i = sz(a) - 1; i >= 0; i--) {
        while (!s.empty() && a[s.top()] >= a[i])
            s.pop();
        if (s.empty())
            res[i] = -1;
        else
            res[i] = s.top();
        s.push(i);
    }
    return res;
}
 
void solve() {
    int n;
    cin >> n;
    vector <int> a(n);
    forn (i, 0, n)
        cin >> a[i];
    auto right = Less(a);
    reverse(all(a));
    auto left = Less(a);
    reverse(all(left));
    reverse(all(a));

    for (int& i : right)
        if (i == -1) 
            i = n;

    for (int& i : left) {
        if (i == -1)
            i = -1;
        else
            i = n - i - 1;
    }
    //cout << "\n";

    vector <long long> sf(n + 1);
    for (int i = n - 1; i >= 0; --i)
        sf[i] = sf[right[i]] + (1LL * right[i] - i) * 1LL * a[i];
    vector <long long> pr(n);
    forn (i, 0, n) {
        pr[i] = 1LL * (i - left[i]) * 1LL * a[i];
        if (left[i] != -1)
            pr[i] += pr[left[i]];
    }

    int ans_idx;
    long long ans = 0;
    forn (i, 0, n) {
        long long t;
        if (!i)
            t = a[i];
        else
            t = pr[i];
        if (t + sf[i] - a[i] > ans) {
            ans = t + sf[i] - a[i];
            ans_idx = i;
        }
    }
    /*
    for (int i : sf)
        cout << i << " ";
    cout << "\n";
    for (int i : pr)
        cout << i << " ";*/
    
    //cerr << ans << " " << ans_idx << "\n";;
    vector <int> ans_v(n);
    ans_v[ans_idx] = a[ans_idx];
    forn (i, ans_idx + 1, n)
        ans_v[i] = min(ans_v[i - 1], a[i]);
    for (int i = ans_idx - 1; i >= 0; --i)
        ans_v[i] = min(ans_v[i + 1], a[i]);
    for (int i : ans_v)
        cout << i << " ";
    cout << "\n";
}


 
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t = 1;
    while (t --> 0)
        solve();
    return 0;
}