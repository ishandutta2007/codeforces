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

const int INF = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int q;
    cin >> q;
    set <int> lightnings;
    long long sum = 0, add_sum = 0;
    set <int> spells;
    spells.insert(INF), spells.insert(0);
    int mn_good = INF;
    while (q --> 0) {
        int tp, d;
        cin >> tp >> d;
        if (tp == 0) {
            if (d > 0) {
                sum += d;
                spells.insert(d);
                if (d >= mn_good) {
                    add_sum -= mn_good;
                    mn_good = *spells.upper_bound(mn_good);
                    add_sum += d;
                }
            } else {
                d *= -1;
                sum -= d;
                spells.erase(d);
                if (d >= mn_good) {
                    add_sum -= d;
                    mn_good = *--spells.lower_bound(mn_good);
                    add_sum += mn_good;
                }
            }
        } else {
            if (d > 0) {
                sum += d;
                spells.insert(d);
                lightnings.insert(d);
                if (d >= mn_good) {
                    add_sum -= mn_good;
                    mn_good = *spells.upper_bound(mn_good);
                    add_sum += d;
                }
                mn_good = *--spells.lower_bound(mn_good);
                add_sum += mn_good;
            } else {
                d *= -1;
                sum -= d;
                spells.erase(d);
                lightnings.erase(d);
                if (d >= mn_good) {
                    add_sum -= d;
                    mn_good = *--spells.lower_bound(mn_good);
                    add_sum += mn_good;
                }
                add_sum -= mn_good;
                mn_good = *spells.upper_bound(mn_good);
            }
        }
        cerr << sum << " " << add_sum << " " << mn_good << "\n";
        if (lightnings.empty()) {
            cout << sum << "\n";
            continue;
        }
        if (*lightnings.begin() >= mn_good) {
            if (spells.lower_bound(mn_good) != spells.begin())
                cout << sum + add_sum - *lightnings.begin() + *--spells.lower_bound(mn_good);
            else
                cout << sum + add_sum - *lightnings.begin();
        }
        else
            cout << sum + add_sum;
        cout << "\n";
    }
    return 0;
}