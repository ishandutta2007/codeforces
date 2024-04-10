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

int get(int x) {
    int ans = 0;
    while (x) {
        ans += x % 10;
        x /= 10;
    }
    return ans;
}

const int N = 150;

vector <int> ans_one = {-1, 0, -1, 1, -1, 2, -1, 3, -1, 4, 9, 5, 19, 6, 29, 7, 39, 8, 49, 18, 59, 28, 69, 38, 79, 48, 89, 58, 189, 68, 289, 78, 389, 88, 489, 98, 589, 198, 689, 298, 789, 398, 889, 498, 989, 598, 1989, 698, 2989, 798, 3989, 898, 4989, 998, 5989, 1998, 6989, 2998, 7989, 3998, 8989, 4998, 9989, 5998, 19989, 6998, 29989, 7998, 39989, 8998, 49989, 9998, 59989, 19998, 69989, 29998, 79989, 39998, 89989, 49998, 99989, 59998, 199989, 69998, 299989, 79998, 399989, 89998, 499989, 99998, 599989, 199998, 699989, 299998, 799989, 399998, 899989, 499998, 999989, 599998, 1999989, 699998, 2999989, 799998, 3999989, 899998, 4999989, 999998, 5999989, 1999998, 6999989, 2999998, 7999989, 3999998, 8999989, 4999998, 9999989, 5999998, 19999989, 6999998, 29999989, 7999998, 39999989, 8999998, 49999989, 9999998, 59999989, 19999998, 69999989, 29999998, 79999989, 39999998, 89999989, 49999998, 99999989, 59999998, 199999989, 69999998, 299999989, 79999998, 399999989, 89999998, 499999989, 99999998, 599999989, 199999998, 699999989, 299999998, 799999989, 399999998, 899999989};

vector <vector <int>> ans;

vector <int> s;

void solve() {
    int n, k;
    cin >> n >> k;
    if (k == 0) {
        cerr << ans[n][k] << " "; 
        if (n % 9)
            cout << n % 9;
        n -= n % 9;
        cout << string(n / 9, '9') << "\n";
        return;
    }
    if (k == 1) {
        cout << ans_one[n] << "\n";
        return;
    }
    cout << ans[n][k] << "\n";
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    /*ans_one.resize(N + 1, -1);
    int prev = 0;
    forn (i, 1, 1e9) {
        int cur = get(i);
        if (prev + cur <= N && 
            ans_one[prev + cur] == -1) {
            ans_one[prev + cur] = i - 1;
        }
        prev = cur;
    }
    cout << ans_one;
    return 0;*/
    s.resize(1e7);
    forn (i, 0, sz(s))
        s[i] = get(i);
    ans.resize(N + 1, vector <int> (10, -1));
    forn (i, 0, sz(s)) {
        int cur = 0;
        forn (j, 0, 10) {
            if (i + j >= sz(s))
                break;
            cur += s[i + j];
            if (cur > N)
                continue;
            if (ans[cur][j] == -1)
                ans[cur][j] = i;
        }
    }
    forn (j, 0, 10) {
        forn (i, 0, N)
            cerr << ans[i][j] << " ";
        cerr << "\n---\n";
    }
    int t;
    cin >> t;
    while (t --> 0)
        solve();
    return 0;
}