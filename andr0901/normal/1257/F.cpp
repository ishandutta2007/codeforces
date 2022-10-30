#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

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
// vector continue break return void int double 

const int M = 16;
int n;

map <vector <int>, int> get(const vector<int>& a) {
    map <vector <int>, int> ans;
    forn (i, 0, 1 << M) {
        vector <int> cur(n);
        forn (j, 0, n)
            cur[j] = __builtin_popcount(a[j] ^ i);
        ans[cur] = i;
    }
    return ans; 
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    vector <int> a(n);
    forn (i, 0, n)
        cin >> a[i];
    vector <int> b(n);
    forn (i, 0, n) {
        b[i] = (a[i] >> M);
        //cout << b[i] << " ";
    }
    //cout << "\n";
    vector <int> c(n);
    forn (i, 0, n) {
        c[i] = ((b[i] << M) ^ a[i]);
        //cout << c[i] << " ";
    }
    //cout << "\n";
    auto left = get(b), right = get(c);
    forn (i, 0, 31) {
        for (const auto& j : left) {
            vector <int> needed = j.fs;
            forn (k, 0, n)
                needed[k] = i - needed[k];
            if (right.find(needed) != right.end()) {
                cout << ((j.sc << M) | right[needed]);
                return 0; 
            }
        }
    }
    cout << -1;
    return 0;
};