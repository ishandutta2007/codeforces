#pragma comment(linker, "/stack:200000000")
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

const double PI = 4 * atan(1);

#define sz(x) (int)(x).size()
#define ll long long
#define ld long double
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define pii pair <int, int>
#define vi vector<int>
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define vpi vector<pair<int, int>>
#define vpd vector<pair<double, double>>
#define pd pair<double, double>

#define f0r(i,a) for(int i=0;i<a;i++)
#define f1r(i,a,b) for(int i=a;i<b;i++)
#define trav(a, x) for (auto& a : x)

void fast_io(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
}
void io(string taskname){
    string fin = taskname + ".in";
    string fout = taskname + ".out";
    const char* FIN = fin.c_str();
    const char* FOUT = fout.c_str();
    freopen(FIN, "r", stdin);
    freopen(FOUT, "w", stdout);
    fast_io();
}
template<int SZ> struct Sieve {
	bitset<SZ> comp;
	vi pr;
	// int sp[SZ];

	Sieve() {
		for (int i = 2; i*i < SZ; ++i) if (!comp[i])
			for (int j = i*i; j < SZ; j += i) comp[j] = 1;
		f1r(i,2,SZ) if (!comp[i]) pr.pb(i);

		/*FOR(i,2,SZ) { // O(N) sieve
			if (sp[i] == 0) { sp[i] = i; pr.pb(i); }
			trav(p,pr) {
				if (p > sp[i] || i*p >= SZ) break;
				sp[i*p] = p;
			}
		}*/
	}
};
const int MX = 1e6 +5;
Sieve<MX> s;
vi p;

int four[5][2] = {{1, 2}, {1, 3}, {2, 3}, {2, 4}, {3, 4}};
int six[7][2] = {{1, 2}, {2, 3}, {3, 4}, {4, 5}, {5, 6}, {6, 1}, {1, 3}};
int eight[13][2] = {{1, 2}, {1, 3},{2, 3}, {1, 4}, {2, 4}, {1, 5}, {2, 5}, {1, 6}, {2, 6},  {1, 7}, {1, 8}, {5, 8}, {7, 8}};
int nine[11][2] = {{1, 2}, {2, 3}, {3, 4}, {4, 5}, {5, 1}, {1, 3}, {6, 7}, {7, 8}, {8,  9}, {6, 9}, {7, 9}};
int small(int x){
    for(int i: p){
        if(i>= x){
            return i;
        }
    }
    return -1;
}
int main(){
    fast_io();
    int n;
    cin >> n;
    for(auto x: s.pr) p.eb(x);
    if(n == 4){
        cout << 5 << endl;
        f0r(i, 5){
            cout << four[i][0] << " " <<four[i][1] << endl;
        }
        return 0;
    }
    if(n == 6){
        cout << 7 << endl;
        f0r(i, 7){
            cout << six[i][0] << " " <<six[i][1] << endl;
        }
        return 0;
    }
    if(n == 8){
        cout << 13 << endl;
        f0r(i, 13){
            cout << eight[i][0] << " " <<eight[i][1] << endl;
        }
        return 0;
    }
    if(n == 9){
        cout << 11 << endl;
        f0r(i, 11){
            cout << nine[i][0] << " " <<nine[i][1] << endl;
        }
        return 0;
    }
    if(n == 14){
            cout << 17 << endl;
        f0r(i, n){
            cout << (i%n) + 1 << " " << ((i + 1)%n) + 1 << endl;
        }
        cout << 1 << " " << 3 << endl;
        cout << 4 << " " << 6 << endl;
        cout << 8 << " " << 10 << endl;
        return 0;
    }
    int pr = small(n);
    cout << pr << endl;
    int gain = pr - n;
    int cur = 0;
    int times = 0;
    f0r(i, gain){
        f0r(j, 5){
            cout << four[j][0] + cur<< " " << four[j][1] + cur << endl;
            times++;
        }
        cur += 4;
    }
    int rest = n- cur;
    assert(rest>= 3);
    f0r(i, rest){
        cout << cur +1 + (i%rest) << " " << cur + 1 + ((i+1)%rest) << endl;
        times++;
    }
    assert(times == pr);
    return 0;
}