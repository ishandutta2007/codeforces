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
    while (l != r) cout << *l << " \n"[++l == r];
}
template <typename A, typename B> istream& operator >> (istream& o, pair<A, B> &a) {
    return o >> a.X >> a.Y;
}
template <typename A, typename B> ostream& operator << (ostream& o, pair<A, B> a) {
    return o << '(' << a.X << ", " << a.Y << ')';
}
template <typename T> ostream& operator << (ostream& o, vector<T> a) {
    bool is = false;
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
#define owo freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout)
#else
#define test(args...) void(0)
#define owo ios::sync_with_stdio(false); cin.tie(0)
#endif
const int mod = 998244353, N = 500001, logN = 20, K = 450;

string bin(lli x) {
    string s;
    while (x) {
        s.pb('0' + (x & 1));
        x >>= 1;
    }
    reverse(all(s));
    return s;
}

pair <pii, string> con(string t) {
    int l = 0, r = 0;
    while (!t.empty() && t.back() == '1')
        t.pop_back(), r++;
    reverse(all(t));
    while (!t.empty() && t.back() == '1')
        t.pop_back(), l++;
    reverse(all(t));
    return mp(mp(l, r), t);
}

bool chk(string s, string t) {
    int is = 0;
    if (count(all(s), '1') == s.size())
        is |= 1;
    if (count(all(t), '1') == t.size())
        is |= 2;
    if (is) {
        return is == 3 && s.size() <= t.size();
    }
    auto A = con(s), B = con(t);
    string a = A.Y, b = B.Y;
    if (a == b && A.X.X <= B.X.X && A.X.Y <= B.X.Y)
        return true;
    reverse(all(a));
    swap(A.X.X, A.X.Y);
    if (a == b && A.X.X <= B.X.X && A.X.Y <= B.X.Y)
        return true;
    reverse(all(b));
    swap(B.X.X, B.X.Y);
    if (a == b && A.X.X <= B.X.X && A.X.Y <= B.X.Y)
        return true;
    reverse(all(a));
    swap(A.X.X, A.X.Y);
    if (a == b && A.X.X <= B.X.X && A.X.Y <= B.X.Y)
        return true;
    return false;
}

int main () {
    owo;
    lli x, y;
    cin >> x >> y;
    if (x == y)
        return cout << "YES\n", 0;
    string s = bin(x), t = bin(y);
    if (t[0] == '0' || t.back() == '0')
        return cout << "NO\n", 0;
    // add 0 on first step
    {
        string a = s;
        while (a.back() == '0')
            a.pop_back();
        reverse(all(a));
        if (chk(a, t))
            return cout << "YES\n", 0;
        // 1abc1
        // 11cba1
        // 1abc11
        // 1cba1
        // 11abc1
    }
    {
        string a = s;
        a.pb('1');
        reverse(all(a));
        if (chk(a, t))
            return cout << "YES\n", 0;
    }
    cout << "NO\n";
}