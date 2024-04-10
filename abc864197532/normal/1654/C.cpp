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
const int mod = 1e9 + 7, N = 1e5 + 4, logN = 18, C = 1;

int main () {
    owo;
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        map <lli, int> cur;
        priority_queue <lli> now;
        lli sum = 0;
        for (int i = 0, x; i < n; ++i)
            cin >> x, cur[x]++, sum += x;
        if (n == 1) {
            cout << "YES\n";
            continue;
        }
        now.push(sum);
        int cnt = n;
        while (!now.empty()) {
            if (cnt < now.size())
                break;
            lli x = now.top(); now.pop();
            if (cur[x >> 1])
                cur[x >> 1]--, cnt--;
            else
                now.push(x >> 1);
            if (cur[x + 1 >> 1])
                cur[x + 1 >> 1]--, cnt--;
            else
                now.push(x + 1 >> 1);
        }
        cout << (!cnt ? "YES\n" : "NO\n");
    }
}