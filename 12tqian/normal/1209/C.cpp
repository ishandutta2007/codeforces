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
template<class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

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

template<typename A, typename B> ostream& operator <<(ostream &cout, pair< A, B> const &p) {return cout << "(" << p.f << ", " << p.s << ")"; }
template<typename A> ostream& operator <<(ostream &cout, vector<A> const &v){
    cout <<"["; for(int i = 0; i<v.size(); i++) {if(i) cout <<", "; cout << v[i];} return cout << "]";
}
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
const int INF = 1e9;
int main(){
    fast_io();
    int cases;
    cin >> cases;
    while(cases--){
        int n;
        cin >> n;
        vi d;
        d.resize(n);
        string temp;
        getline(cin, temp);
        string line;
        getline(cin, line);
        if(n == 1){
            cout << "1" << endl;
            continue;
        }
        f0r(i, n){
            d[i] = line[i] - '0';
        }
        bool ok = true;
        f0r(t, 10){
            vi ans;
            ans.resize(n);
            vi v1;
            vi loc;
            vi v2;
            int a1 = -1;
            int a2 = n;
            bool isTrue = false;
            f0r(i, n){
                if(d[i]<t){
                    ans[i] = 1;
                    v1.eb(d[i]);
                    a1 = max(a1, i);
                    if(sz(v1)>1 && v1[sz(v1)-1] < v1[sz(v1)-2]){
                        isTrue = true;
                        break;
                    }
                }
                else if(d[i]>t){
                    ans[i] = 2;
                    v2.eb(d[i]);
                    a2 = min(a2, i);
                    if(sz(v2)>1 && v2[sz(v2)-1] < v2[sz(v2)-2]){
                        isTrue = true;
                        break;
                    }
                }
                else{
                    loc.eb(i);
                }
            }
            if(isTrue) continue;
            for(int i: loc){
                if(i<a1 && i>a2){
                    isTrue = true;
                    break;
                }
                if(i>a1){
                    ans[i] = 1;
                }
                else{
                    ans[i] = 2;
                }
            }
            if(isTrue) continue;
            string s;
            f0r(i, n){
                s += ('0' + ans[i]);
            }
            cout << s << endl;
            ok = false;
            break;

        }
        if(ok){
            cout << "-" << endl;
        }
    }

    return 0;
}