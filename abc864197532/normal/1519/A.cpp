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
#define info() cerr << __PRETTY_FUNCTION__ << ": " << __LINE__ << "\n"
#define test(args...) info(), kout("[" + string(#args) + "]", args)
#define printv(a) {\
    info();\
    for (auto i : a) cerr << i << ' ';\
    cerr << endl;\
}
void kout() {cerr << endl;}
template <class T, class ...U>
void kout(T a, U ...b) {cerr << a << ' ', kout(b...);}
template <typename A, typename B>
istream& operator >> (istream& o, pair<A, B> &a) {
    return o >> a.X >> a.Y;
}
template <typename A, typename B>
ostream& operator << (ostream& o, pair<A, B> a) {
    return o << a.X << ' ' << a.Y;
}
template <typename A>
ostream& operator << (ostream& o, vector <A> a) {
    for (auto i : a) o << i << ' ';
    return o;
}
const int mod = 1e9 + 7, abc = 864197532, Doludu = 123, N = 300001, K = 111;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a > b) swap(a, b);
        if (1ll * a * (c + 1) < b) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
    }
}