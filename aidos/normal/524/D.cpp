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

int n, M, T;
int a[20020];
int ans[20020];

int main () {
    #ifdef LOCAL
    freopen(file".in", "r", stdin);
    freopen(file".out", "w", stdout);
    #endif

    scanf("%d%d%d\n", &n, &M, &T);

    for (int i=0;i<n;i++){
        int hh, mm, ss;
        scanf("%d:%d:%d\n", &hh, &mm, &ss);
        a[i] = hh*60*60 + mm*60 + ss;   
    }                     
    
    multiset < pii > S;
    map < int, int > adam;
    int R = 1;
    int cur = 0;          
    bool ok = false;
    for (int i=0;i<n;i++){
        int prev = a[i] - T;
        while (!S.empty()){
            int timer = (*(S.begin())).f;
            int id = (*(S.begin())).s;
            if ( timer <= prev ){
                adam[id]--;
                if ( adam[id] == 0 ) cur--;
                S.erase(S.begin());
            }
            else break;
        }

        if ( cur + 1 <= M ){
            ok |= (cur+1 == M);
            ans[i] = R;
            adam[R]++;
            cur++;
            S.insert(mp(a[i], R));
            R++;
        }                                                     
        else {
            multiset<pii> ::iterator it = --(S.end());
            pii temp = *it;
            int timer = temp.f;
            int id = temp.s;
            ans[i] = id;
            adam[id]++;
            S.insert(mp(a[i], id));     
        }
    }

    if ( !ok ){
        cout <<"No solution"<<endl;
        return 0;
    }


    cout <<R-1<<endl;
    for (int i=0;i<n;i++){
        cout <<ans[i]<<endl;        
    }


    #ifdef LOCAL
    cerr << (double)clock() * 1.0 / CLOCKS_PER_SEC << endl;
    #endif

    return 0;
}