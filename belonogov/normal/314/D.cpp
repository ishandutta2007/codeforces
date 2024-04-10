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

const int maxn = 2e5 + 10;
const int inf = 2e9;

struct pnt{
    int x, y;
    pnt(){}
    pnt(int x, int y): x(x), y(y){};
    pnt turn90(){
        return pnt(- y, x);
    }
    void read(){
        scanf("%d%d", &x, &y);
     }
};

int mn[maxn];
int mx[maxn];
int leftmn, leftmx;
pnt p[maxn];

bool cmpXY(pnt A, pnt B){
    return A.x + A.y < B.x + B.y;
}

bool check(int m, int d){
    int realmn, realmx;
    realmn = min(leftmn, mn[m + 1]);
    realmx = max(leftmx, mx[m + 1]);
    return d >= realmx - realmn;
}

int main(){
   // freopen("input.txt", "r", stdin);
    //freopen("a.out", "w", stdout);
    int n, l, r, ans;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        p[i].read();

    ans = inf;
    for(int t = 0; t < 2; t++){
        sort(p, p + n, cmpXY);
        mn[n] = inf;
        mx[n] = -inf;
        for(int i = n - 1; i >= 0; i--){
            mn[i] = min(mn[i + 1], p[i].x - p[i].y);
            mx[i] = max(mx[i + 1], p[i].x - p[i].y);
        }
        leftmn = inf;
        leftmx = - inf;
        for(int i = 0; i < n; i++){
            l = i - 1;
            r = n;
            while(r - l > 1){
                int m = (l + r) / 2;
                if (check(m, p[m].x + p[m].y - p[i].x - p[i].y))
                    r = m;
                else
                    l = m;
            }
            if (r != n)
                ans = min(ans, p[r].x + p[r].y - p[i].x - p[i].y);
           // epr("ans %d\n", ans);
            leftmn = min(leftmn, p[i].x - p[i].y);
            leftmx = max(leftmx, p[i].x - p[i].y);
        }

        for(int i = 0; i < n; i++)
            p[i] = p[i].turn90();
     //   for(int i = 0; i < n; i++)
      //      epr("%d %d\n", p[i].x, p[i].y);
      //  epr("\n");
    }
  //  cout << ans << endl;
    cout << fixed << ans / 2.0 << endl;
    return 0;
}