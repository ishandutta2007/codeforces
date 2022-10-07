#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <cmath>

#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define epr(...) fprintf(stderr, __VA_ARGS__)

using namespace std;

const int maxn = 1000;
const int inf = 1e9;

bool a[2][maxn];
int dp1[maxn];  /*****
                  ***/
int dp2[maxn];  /***
                  ***/
int dp3[maxn];  /***
                 **/
int dp4[maxn];  /***
                 ***/

int use[maxn];
int t = 0;

int mex(){
    for (int i = 0; ; i++)
        if (use[i] != t)
            return i;
}

void finish(bool flag){
    if (flag)
        cout << "WIN\n";
    else
        cout << "LOSE\n";
    exit(0);
}


int main(){
   // freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    int n, q, x, y;
    scanf("%d%d", &n, &q);
    for(int i = 0; i < q; i++){
        scanf("%d%d", &x, &y); x--; y--;
        a[y][x] = 1;
        if (x > 0)
            a[1 - y][x - 1] = 1;
        a[1 - y][x] = 1;
        if (x < n - 1)
            a[1 - y][x + 1] = 1;
    }
    a[0][n] = a[1][n] = 1;
  /*  for (int i = 0; i < n + 2; i++)
        epr("%d ", a[0][i]);
    epr("\n");
    for (int i = 0; i < n + 2; i++)
        epr("%d ", a[1][i]);
    epr("\n\n");
*/
    dp1[1] = 1;
    dp2[1] = 1;
    dp3[1] = 1;
    dp4[1] = 1;
    for (int len = 2; len <= n; len++){
        t++;
        for (int i = 0; i < len; i++)
            use[dp1[i] ^ dp1[len - 1 - i]] = t;
        for (int i = 0; i < len - 2; i++)
            use[dp2[i] ^ dp2[len - 3 - i]] = t;
        dp1[len] = mex();

        t++;
        for (int i = 0; i < len; i++)
            use[dp1[i] ^ dp2[len - i - 1]] = t;
        dp2[len] = mex();

        t++;
        use[dp2[len - 2]] = t;
        use[dp1[len - 1]] = t;
        for (int i = 1; i < len - 1; i++)
            use[dp3[i] ^ dp2[len - 1 - 1 - i]] = t;
        for (int i = 1; i < len; i++)
            use[dp3[i] ^ dp1[len - 1 - i]] = t;
        dp3[len] = mex();

        t++;
        for (int i = 0; i < len; i++)
            use[dp3[i] ^ dp3[len - 1 - i]] = t;
        dp4[len] = mex();
    }
 /*   for (int i = 0; i < n + 2; i++)
        epr("%d ", dp1[i]);
    epr("\n");
    for (int i = 0; i < n + 2; i++)
        epr("%d ", dp2[i]);
    epr("\n");
    for (int i = 0; i < n + 2; i++)
        epr("%d ", dp3[i]);
    epr("\n");
    for (int i = 0; i < n + 2; i++)
        epr("%d ", dp4[i]);
    epr("\n");
*/

    if (q == 0)
        finish(dp4[n] != 0);
    bool flag0 = 0;
    bool flag1 = 0;
    int ans = 0;
    int last = 0;
    for (int i = 0; i < n + 1; i++){
        if (last == -1 && a[0][i] == 1 && a[1][i] == 1)
            continue;
        if (last == -1){
         //   epr("first i: %d\n", i);
            flag0 = a[0][i];
            flag1 = a[1][i];
            last = i;
            continue;
        }
     //   epr("flag: %d %d\t\t\t%d\n", flag0, flag1, ans);
        if (a[0][i] == 1 || a[1][i] == 1){
         //   epr("\t\ta   : %d %d\n", a[0][i], a[1][i]);
            if (a[0][i] == a[1][i]){
                if (flag0 == flag1)
                    ans ^= dp4[i - last];
                else
                    ans ^= dp3[i - last];
            }
            else{
                if ((a[0][i] ^ a[1][i]) && (flag1 ^ flag0)){
                    if (a[1][i] == flag1)
                        ans ^= dp1[i - last + 1];
                    else
                        ans ^= dp2[i - last];
                }
                else
                    ans ^= dp3[i - last + 1];
            }
            last = -1;
        }
    }

    finish(ans);


    return 0;
}