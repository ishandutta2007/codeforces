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

    int n, m;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
         scanf("%d%d", &w[i], &h[i]);
    }
    m = n >> 1;
    int ans = mod;
    for(int f = 0; f <= 1000; f++) {
        int sw = 0;
        bool ok = 1;
        int mm = m;
        priority_queue<int> q;
        for(int i = 0; i < n; i++) {
            if(h[i] > f && w[i] > f) {
                ok = 0;
                break;
            }
            if(h[i] > f) {
                sw += h[i];
                mm--;
            } else
            if(w[i] > f) {
                sw += w[i];
            } else
            if(h[i] < w[i]) {
                q.push(w[i] - h[i]);
                sw += w[i];
            } else {
                sw += w[i];
            }
        }
        if(ok == 0 || mm < 0) continue;
        while(mm > 0 && !q.empty()) {
            sw -= q.top(); q.pop();
            mm--;
        }
        ans = min(ans, sw * f);
//      cout << f << " "<< sw * f << "\n";
    }
    cout << ans;

    return(0);
}

// by Kim Andrey