#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define test(x) cout << "Line(" << __LINE__ << ") " #x << ' ' << x << endl
#define printv(x) {\
	for (auto i : x) cout << i << ' ';\
	cout << endl;\
}
#define pii pair <int, int>
#define pll pair <lli, lli>
#define X first
#define Y second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
template<typename A, typename B>
ostream& operator << (ostream& o, pair<A, B> a){
    return o << a.X << ' ' << a.Y;
}
template<typename A, typename B>
istream& operator >> (istream& o, pair<A, B> &a){
    return o >> a.X >> a.Y;
}
const int mod = 1e9 + 7, abc = 864197532, Doludu = 123, N = 1001, logN = 18;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, q, x;
    cin >> n >> q;
    vector <int> id(50, -1);
    for (int i = 0; i < n; ++i) {
        cin >> x, --x;
        if (id[x] == -1) id[x] = i;
    }
    while (q--) {
        cin >> x, --x;
        cout << id[x] + 1 << endl;
        for (int i = 0; i < 50; ++i) if (id[i] < id[x]) id[i]++;
        id[x] = 0;
    }
}