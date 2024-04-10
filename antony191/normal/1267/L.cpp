#include <bits/stdc++.h>

#ifdef ONLINE_JUDGE
#pragma GCC optimize("Ofast")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("fast-math")
#pragma GCC optimize("vpt")
#endif
using namespace std;

typedef long long ll;
typedef long double ld;
const char el = '\n';
const int inf = 1e9, mod = 1000'000'007;
const ll llinf = 1e18;

#define forn(i, n) for (int i = 0; i < (int)n; ++i)
#define firn(i, n) for (int i = 1; i < (int)n; ++i)
#define all(v) v.begin(), v.end()
#define x first
#define y second
#define pb push_back
#define debug(x) cout << #x << ": " << x << el
#define left left228
#define right right228
#define prev prev228

template<typename T> bool uin(T &a, T b) { if (b < a) { a = b; return true;} return false; }
template<typename T> bool uax(T &a, T b) { if (b > a) { a = b; return true;} return false; }
template<class iterator> void output(iterator begin, iterator end, char p = ' ', ostream & out = cout) { while (begin != end) { out << (*begin) << p; begin++; } out << el; }
template<class T> void output(T x, char p = ' ', ostream & out = cout) { output(all(x), p, out); }

mt19937 rnd(time(nullptr));

int num[26];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, l, k;
    cin >> n >> l >> k;
    string s;
    cin >> s;
    vector<int> a;
    a.reserve(n * l);
    forn(i, n * l) {
        a.push_back(s[i] - 'a');
        num[a.back()]++;
    }
    sort(all(a));
    vector<string> ans(n);
    int pos = 0, i;
    for (i = 0; i < n * l; ) {
        int c = a[i];
        if (k > num[c]) {
            for (int j = pos; j < pos + num[c]; ++j) {
                ans[j] += char(c + 'a');
                while((int)ans[j].size() < l) {
                    ans[j] += char(a.back() + 'a');
                    num[a.back()]--;
                    a.pop_back();
                }
            }
            pos += num[c];
            i += num[c];
            k -= num[c];
            num[c] = 0;
            continue;
        }
        for (int j = pos; j < pos + k; ++j) {
            ans[j] += char(c + 'a');
        }
        i += k;
        num[c] -= k;
        if ((int)ans[pos].size() == l) break;
    }
    forn(j, n) {
        while((int)ans[j].size() < l) {
            ans[j] += char(a.back() + 'a');
            num[a.back()]--;
            a.pop_back();
        }
    }
    sort(all(ans));
    output(ans, el);
    return 0;
}