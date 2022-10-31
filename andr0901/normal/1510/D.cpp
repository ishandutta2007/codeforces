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

constexpr int M = 10;

vector<int> cnt;
vector<int> mx_power;
vector<vector<double>> pref;

constexpr int INF = 1e9;

int d;

double best;
vector<int> ans;

void go(int idx, int lst, vector<int> cur_cnt) {
    if (idx == M) {
        if (lst != d) {
            return;
        }
        bool is_empty = true;
        forn (i, 0, M) {
            if (cur_cnt[i]) {
                is_empty = false;
            }
        }
        if (is_empty) {
            return;
        }
        double prod = 0;
        forn (i, 0, M) {
            if (cur_cnt[i] == 0)
                continue;
            int blocks = (cnt[i] - cur_cnt[i]) / mx_power[i];
            int s = blocks * mx_power[i] + cur_cnt[i];
            if (i == 1)
                cerr << blocks << " " << s << "  ";
            prod += pref[i][s];
        }
        cerr << cur_cnt << ": " << prod << "\n";
        if (prod > best) {
            best = prod;
            ans = cur_cnt;
        }
        return;
    }
    forn (k, 0, min(cnt[idx] + 1, mx_power[idx] + 1)) {
        cur_cnt[idx] = k;
        go(idx + 1, lst, cur_cnt);
        lst = (lst * idx) % M;
    }
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    mx_power.resize(M);
    mx_power[0] = mx_power[1] = 1;
    forn (i, 2, M) {
        int cur = i;
        int cnt = 0;
        while (cnt == 0 || cur != i) {
            cur = (cur * i) % M;
            ++cnt;
        }
        mx_power[i] = cnt;
    }
    cerr << mx_power << "\n";
    int n;
    cin >> n >> d;
    vector<int> a(n);
    cin >> a;
    cnt.resize(M);
    vector<vector<int>> all_numbers(M);
    forn (i, 0, n) {
        cnt[a[i] % 10]++;
        all_numbers[a[i] % 10].pb(a[i]);
    }
    pref.resize(M);
    forn (i, 0, M) {
        sort(rall(all_numbers[i]));
        pref[i].resize(all_numbers[i].size() + 1);
        forn (j, 0, all_numbers[i].size())
            pref[i][j + 1] = pref[i][j] + log(all_numbers[i][j]);
    }
    best = -1;
    go(0, 1, vector<int>(M, 0));
    cerr << best << "\n" << ans << "\n";
    if (best < 0) {
        cout << "-1";
        return 0;
    }
    vector<int> real_ans;
    forn (i, 0, M) {
        if (ans[i] == 0)
            continue;
        int blocks = (cnt[i] - ans[i]) / mx_power[i];
        int s = blocks * mx_power[i] + ans[i];
        cerr << i << " " << blocks << " " << s << "\n";
        forn (j, 0, s) {
            real_ans.pb(all_numbers[i][j]);
        }
    }
    cout << real_ans.size() << "\n" << real_ans << "\n";
    return 0;
}