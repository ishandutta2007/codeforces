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
const int maxn = 100100;

int tim[maxn];
int ans[maxn];
vector<int> vc;

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

    int n, m, t;
    cin >> n >> m >> t;
    for(int i = 0; i < n; i++) {
        int h, m, s;
        scanf("%d:%d:%d", &h, &m, &s);
        tim[i] = h * 60 * 60 + m * 60 + s;
    }
    int opened = 0, f = 0;
    bool ok = 0;
    for(int i = 0; i <= 86400; i++) {
        while(opened > 0 && i - t == vc[vc.size() - opened]) {
            opened--;
        }
        while(f < n && tim[f] == i) {
            if(opened == m) {
                vc.back() = i;
                ans[f] = ans[f - 1];
            } else {
                vc.pb(i);
                opened++;
                if(opened == m) ok = 1;
                ans[f] = (f >= 0 ? ans[f - 1] : 0) + 1;
            }
            f++;
        }
    }

    if(ok) {
        cout << vc.size() << endl;
        for(int i = 0; i < n; i++) {
            printf("%d\n", ans[i]);
        }
    } else {
        cout << "No solution";
    }

    return(0);
}

// by Kim Andrey