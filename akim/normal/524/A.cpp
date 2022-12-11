#include <algorithm>
#include <iostream>
#include <sstream>
#include <utility>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <fstream>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <ctime>
#include <stack>
#include <map>
#include <set>

using namespace std;

#define pb push_back
#define ppb pop_back
#define mp make_pair
#define fs first
#define sc second
#define abs(a) ((a)<0?-(a):(a))
#define sqr(a) ((a)*(a))

typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;


const double eps = 1e-9;
const int mod = (int)1e+9 + 7;
const double pi = acos(-1.);
const int maxn = 220;

int matrix[maxn][maxn];
map<int, int> ma;
pair<int, int> idx[maxn];
int cnt[maxn];
int n;
vector<int> ans[maxn];

int main() {

    #ifdef SOL
    {
//      freopen("input.txt","r",stdin);
//      freopen("output.txt","w",stdout);
    }
    #else
    srand(time(0));
    const string file = "";
    if(!file.empty()) {
        freopen((file + ".in").c_str(),"r",stdin);
        freopen((file + ".out").c_str(),"w",stdout);
    }
    #endif

    int m;
    double k;
    cin >> m >> k;
    k /= 100.;
    for(int i = 0; i < m; i++) {
        int u, v, uu, vv;
        cin >> u >> v;
        if(ma.count(u) == 0) {
            ma[u] = n;
            idx[n] = mp(u, n);
            n++;
        }
        uu = ma[u];
        if(ma.count(v) == 0) {
            ma[v] = n;
            idx[n] = mp(v, n);
            n++;
        }
        vv = ma[v];
        cnt[uu]++;
        cnt[vv]++;
        matrix[uu][vv] = 1;
        matrix[vv][uu] = 1;
    }

    for(int i = 0; i < n; i++) {
        for(int f = 0; f < n; f++) {
            if(i != f && matrix[i][f] == 0) {
                int obw = 0;
                for(int g = 0; g < n; g++) {
                    if(matrix[i][g] && matrix[f][g]) {
                        obw++;
                    }
                }
                if((cnt[i] * 1.) * k - eps <= (obw * 1.)) {
                    ans[i].pb(idx[f].fs);
                }
            }
        }
    }

    sort(&idx[0], &idx[n]);
    for(int i = 0; i < n; i++) {
        cout << idx[i].fs << ": ";
        int k = idx[i].sc;
        cout << ans[k].size() << " ";
        sort(ans[k].begin(), ans[k].end());
        for(int f = 0; f < (int)ans[k].size(); f++) {
            cout << ans[k][f] << " ";
        }
        cout << endl;
    }

    return(0);
}

// by Kim Andrey