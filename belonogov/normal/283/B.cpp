#include <iostream>
#include <cstdio>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <cstring>
#include <ctime>
#include <cassert>
#include <cmath>

using namespace std;

#define mp make_pair
#define pb push_back
#define fr first
#define sc second
#define epr(...) fprintf(stderr, __VA_ARGS__)


const int maxn = 2e5 + 10;

long long a[maxn];
pair < long long, bool > b[maxn][2];
long long n;

pair < long long, bool > go(int v, int kof){
    pair < long long, bool > res;
   // epr("v kof %d %d\n", v, kof);
    if (b[v][kof].fr == -1){
        b[v][kof].fr = -2;
        int d = (kof == 0) ? - a[v] : a[v];
        if (v + d < 0 || v + d >= n)
            b[v][kof] = mp(a[v], 0);
        else{
            res = go(v + d, kof ^ 1);
            if (res.fr == -2)
                b[v][kof] = res;
            else
                b[v][kof] = mp(res.fr + a[v], res.sc);
        }
    }
    return b[v][kof];
}

int main(){
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    pair < long long, bool > res;
    cin >> n;
    for(int i = 1; i < n; i++)
        cin >> a[i];

    for(int i = 0; i < n; i++)
        b[i][0] = b[i][1] = mp(-1, 0);

    b[0][1] = mp(-2, 0);
    b[0][0] = mp(0, 1);
    for(int i = 1; i < n; i++){
         res = go(i, 0);
         assert(res.sc == 0);
        if (res.fr == -2)
            printf("-1\n");
        else
            cout << res.fr + i + (i * res.sc)  << "\n";
            //printf("%d\n", res + i);
    }




    return 0;

}