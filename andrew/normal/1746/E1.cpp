#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#define fi first
#define se second
#define p_b push_back
#define pll pair<ll,ll>
#define pii pair<int,int>
#define m_p make_pair
#define all(x) x.begin(),x.end()
#define sqr(x) (x)*(x)
#define pw(x) (1ll << (x))
#define sz(x) (int)x.size()
#define fout(x) {cout << x << "\n"; return; }

using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef long double ld;
const int MAXN = 2e6;;
const int M = pw(16);
// const int N = 3e5;
const int inf = 1e9;
template <typename T> void vout(T s){cout << s << endl;exit(0);}

mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

string ask(vector <int> a, vector <int> b) {
    cout << "? " << sz(a) + sz(b);
    for (auto i : a) cout << " " << i;
    for (auto i : b) cout << " " << i;
    cout << endl;
    string s;
    cin >> s;
    return s;
}

string ask(vector <int> a) {
    cout << "? " << sz(a);
    for (auto i : a) cout << " " << i;
    cout << endl;
    string s;
    cin >> s;
    return s;
}

void solve(vector <int> v) {
    if (sz(v) < 4) {
        if (sz(v) == 1) {
            cout << "! " << v[0] << endl;
        }else if (sz(v) == 2) {
            cout << "! " << v[0] << endl;
            string t;
            cin >> t;
            if (t == ":(") {
                cout << "! " << v[1] << endl;
            }
        }else {
            string r1, r2, r3, r4;
            r1 = ask({v[0]});
            r2 = ask({v[1]});
            r3 = ask({v[1]});
            r4 = ask({v[0]});
            if (r2 == r3) {
                if (r2 == "YES") {
                    cout << "! " << v[1] << endl;
                    exit(0);
                }else {
                    v.erase(v.begin() + 1);
                    solve(v);
                }
            }else {

                if (r1 == r2 && r1 == "YES") {
                    v.erase(v.begin() + 2);
                    solve(v);
                    return;
                }

                if (r3 == r4 && r3 == "YES") {
                    v.erase(v.begin() + 2);
                    solve(v);
                    return;
                }

                if (r3 == "YES") {
                    swap(r1, r4);
                }

                if (r1 == "NO") {
                    v.erase(v.begin());                    
                }else {
                    v.erase(v.begin() + 1);
                }
                solve(v);
            }
        }
    }else {
        vector <int> a[4];
        for (int i = 0; i < sz(v); i++) {
            a[i % 4].p_b(v[i]);
        }
        string r1 = ask(a[0], a[2]), r2 = ask(a[0], a[1]);
        v.clear();
        if (r1 == r2) {            
            if (r1 == "NO") {
                for (int i = 1; i < 4; i++)
                    for (auto &j : a[i]) v.p_b(j);
            }else {
                for (int i = 0; i + 1 < 4; i++)
                    for (auto &j : a[i]) v.p_b(j);
            }
        }else {
            if (r1 == "YES") {
                for (auto &j : a[2]) v.p_b(j);
            }else {
                for (auto &j : a[1]) v.p_b(j);
            }
            for (auto &j : a[0]) v.p_b(j);
            for (auto &j : a[3]) v.p_b(j);                    
        }
        solve(v);
    }
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
 

    int n;
    cin >> n;

    vector <int> v;

    for (int i = 1; i <= n; i++) {
        v.p_b(i);
    }

    solve(v);

    return 0;
}