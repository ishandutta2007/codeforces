//#pragma GCC optimize("Ofast")
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

#ifdef DEBUG
#else
    #define cerr if (false) cerr
#endif

template <typename T> istream& operator>>(istream& in, vector <T>& a) {for (auto& i : a) in >> i; return in;}
template <typename T> ostream& operator<<(ostream& out, vector <T>& a)  {for (auto& i : a) out << i << " "; return out;}
template <typename T, typename U> void chkmin(T& a, U b) {if (a > b) a = b;}
template <typename T, typename U> void chkmax(T& a, U b) {if (a < b) a = b;}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    map<int, long long> ans;
    forn (mask, 0, 1 << 10) {
        string s;
        int sum = 0;
        forn (i, 0, 10)
            if ((mask >> i) & 1) {
                s += (i + '0');
                sum += i;
            }
        if (s[0] == '0' && s.size() > 1)
            swap(s[0], s[1]);
        reverse(all(s));
        cerr << s << " ";
        long long t = 0;
        while (s.size()) {
            t *= 10;
            t += (s.back() - '0');
            s.pop_back();
        }
        cerr << t << "\n";
        if (ans.find(sum) != ans.end())
            chkmin(ans[sum], t);
        else
            ans[sum] = t;
    }
    int t;
    cin >> t;
    while (t --> 0) {
        int x;
        cin >> x;
        if (ans.find(x) == ans.end()) {
            cout << "-1";
        } else {
            cout << ans[x];
        }
        cout << "\n";
    }
    return 0;
}