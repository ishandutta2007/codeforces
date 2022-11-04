#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <string>
#include <queue>
#include <cstdlib>
#include <map>
#include <set>
#include <ctime>
#include <bitset>
#define M 333

using namespace std;

int n, t, lst, Ans[M], S[M];

int ask(int x, int y) {
    printf("? %d %d\n", x, y);
    fflush(stdout);
    /*if(rand() & 1) {
        for(int i = 1; i <= y; i++) S[i] ^= 1;
        int xx = 0;
        for(int i = 1; i <= n; i++) xx += S[i];
        return xx;
    } else {
        for(int i = x; i <= n; i++) S[i] ^= 1;
        int xx = 0;
        for(int i = 1; i <= n; i++) xx += S[i];
        return xx;
    }*/
    int xx;
    scanf("%d", &xx);
    return xx;
}

int Do(int x, int y, int b) {
    int a1, a2, _0 = 0, _1 = 0, ans = -1, A0 = n - x + 1, A1 = y;
    while(1) {
        a1 = t;
        a2 = ask(x, y);
        if((A0 % 2) ^ ((a1 + a2) % 2)) {
            _1 ^= 1;
            if(b == 1 && !_0) {
                ans = (A1 + (a2 - a1)) / 2;
                if(_1) ans = A1 - ans;
            }
        } else {
            _0 ^= 1;
            if(b == 0 && !_1) {
                ans = (A0 + (a2 - a1)) / 2;
                if(_0) ans = A0 - ans;
            }
        }
        t = a2;
        if(ans != -1 && !_0 && !_1) return ans;
    }
}

signed main() {
    //scanf("%d", &n);
    //srand(21498712);
    //for(int i = 1; i <= n; i++) S[i] = rand() & 1, t += S[i];
    scanf("%d%d", &n, &t);
    if(n == 1) {
        printf("! %d\n", t);
        fflush(stdout);
        return 0;
    }
    if(n % 2 == 1) {
        for(int i = 1; i < n; i++) Ans[i + 1] = Do(i, i + 1, 1);
        Ans[1] = t - Do(2, n, 0);
    } else {
        for(int i = 1; i <= n; i++) Ans[i] = Do(i, i, 1);
    }
    printf("! ");
    for(int i = 1; i <= n; i++) printf("%d", Ans[i] - Ans[i - 1]);
    fflush(stdout);
    return 0;
}