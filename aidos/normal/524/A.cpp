#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <fstream>
#include <cassert>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <stack>
#include <functional>
#include <numeric>
#include <ctime>
#include <cstdlib>
#include <sstream>

using namespace std;

#define f first
#define s second
#define mp make_pair
#define pb push_back
#define pii pair<int, int>
#define pll pair<long long, long long>
#define y1 stupid_y1
#define ll long long
#define forit(it, s) for(__typeof(s.begin()) it = s.begin(); it != s.end(); it++)
#define all(a) a.begin(), a.end()
#define sqr(x) ((x)*(x))
#define sz(a) (int)a.size()
#define file "a"

const int inf = (int)1e9;
const double eps = 1e-9;
const double pi = acos(-1.0);

int m, k;
map < int, vector < int > > g;

bool found(vector < int > &v, int x){
    int ind = lower_bound(all(v), x) - v.begin();
    return ind != sz(v) && v[ind] == x;
}

int main () {
    #ifdef LOCAL
    freopen(file".in", "r", stdin);
    freopen(file".out", "w", stdout);
    #endif

    scanf("%d%d", &m, &k);

    for (int i=0;i<m;i++){
        int a, b;
        scanf("%d%d", &a, &b);
        g[a].pb(b);
        g[b].pb(a);
    }

    forit(it, g){
        vector < int > &v = it->s;
        sort(all(v));
    }

    forit(it, g){
        int id = it->first;
        vector < int > ans;
        forit(it2, g){
            int id2 = it2->first;
            if ( id2 == id) continue;
            if ( found(it->s, id2) ) continue;
            vector < int > &v = it2->s;
            int cnt = 0;
            forit(it3, v){
                int to = *it3;
                if ( found(it->s, to) ) cnt++;
            }   

            int len = sz(it->s);

            double per = cnt*100.0/len;
            if ( per < k ) continue;
            ans.pb(id2);        
        }

        cout <<id<<": "<<ans.size();
        for (int i=0;i<ans.size();i++){
            cout <<" "<<ans[i];
        }
        cout <<endl;
    }



    #ifdef LOCAL
    cerr << (double)clock() * 1.0 / CLOCKS_PER_SEC << endl;
    #endif

    return 0;
}