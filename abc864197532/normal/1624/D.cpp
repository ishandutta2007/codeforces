#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define pii pair <int, int>
#define X first
#define Y second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
void abc() {cout << endl;}
template <typename T, typename ...U> void abc(T a, U ...b) {
    cout << a << ' ', abc(b...);
}
template <typename T> void printv(T l, T r) {
    for (; l != r; ++l) cout << *l << " \n"[l + 1 == r];
}
template <typename A, typename B> istream& operator >> (istream& o, pair<A, B> &a) {
    return o >> a.X >> a.Y;
}
template <typename A, typename B> ostream& operator << (ostream& o, pair<A, B> a) {
    return o << '(' << a.X << ", " << a.Y << ')';
}
template <typename T> ostream& operator << (ostream& o, vector<T> a) {
    bool is = false;
    if (a.empty()) return o << "{}";
    for (T i : a) {o << (is ? ' ' : '{'), is = true, o << i;}
    return o << '}';
}
template <typename T> struct vv : vector <vector <T>> {
    vv(int n, int m, T v) : vector <vector <T>> (n, vector <T>(m, v)) {}
    vv() {}
};
template <typename T> struct vvv : vector <vv <T>> {
    vvv(int n, int m, int k, T v) : vector <vv <T>> (n, vv <T>(m, k, v)) {}
    vvv() {}
};
#ifdef Doludu
#define test(args...) abc("[" + string(#args) + "]", args)
#define owo freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout); 
#else
#define test(args...) void(0)
#define owo ios::sync_with_stdio(false); cin.tie(0)
#endif
const int mod = 1e9 + 7, N = 100000, logN = 20, K = 48763;

int main () {
    owo;
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        string s;
        cin >> n >> k >> s;
        vector <int> cnt(26, 0);
        for (char c : s)
            cnt[c - 'a']++;
        int c = 0, c2 = 0;
        for (int i = 0; i < 26; ++i) {
            while (cnt[i] >= 2)
                cnt[i] -= 2, c++;
            c2 += cnt[i];
        }
        auto ask = [&](int len) {
            int res = c, res2 = c2;
            if (len % 2 == 0)
                return res / (len / 2);
            int ans = 0;
            while (true) {
                if (res >= len / 2) {
                    res -= len / 2;
                    if (res2)
                        res2--;
                    else if (res)
                        res--, res2++;
                    else
                        break;
                    ans++;
                } else {
                    break;
                }
            }
            return ans;
        };
        int l = 0, r = n + 1;
        while (r - l > 1) {
            (ask(l + r >> 1) >= k ? l : r) = l + r >> 1;
        }
        cout << l << endl;
    }
}