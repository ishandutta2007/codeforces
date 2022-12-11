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

int w[maxn], h[maxn];

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

    int n;
    cin >> n;
    int ans = mod;
    for(int i = 0; i < n; i++) {
        scanf("%d%d", &w[i], &h[i]);
        if(w[i] > h[i]) {
            swap(w[i], h[i]);
        }
    }
    for(int i = 0; i <= 1000; i++) {
        bool ok = 1;
        int S = 0;
        for(int f = 0; f < n; f++) {
            if(w[f] > i) {
                ok = 0;
                break;
            }
            if(h[f] <= i) {
                S += w[f];
            } else {
                S += h[f];
            }
        }
        if(ok) {
            ans = min(ans, S * i);
        }
    }

    cout << ans;

    return(0);
}

// by Kim Andrey