#define _CRT_SECURE_NO_WARNINGS
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <math.h>
#include <assert.h>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <string>
#include <functional>
#include <vector>
#include <deque>
#include <utility>
#include <bitset>
#include <limits.h>
#include <unordered_map>
#include <unordered_set>
#include <time.h>
 
using namespace std;
typedef long long ll;
typedef unsigned long long llu;
typedef double lf;
typedef unsigned int uint;
typedef long double llf;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
#define N_ 200020
 
int N, M;
struct P{
    int x, y, c;
    P() {} P(int x,int y,int c){ this->x = x; this->y = y; this->c = c;}
    bool operator<(const P&t) const {
        return x != t.x ? x < t.x : y > t.y;
    }
    bool operator==(const P&t) const{
        return x == t.x && y == t.y;
    }
} D[N_+1], inp[N_+1];
int Hull[N_+1], hn;
 
inline llf dist(const P &a,const P &b){
    return sqrt((llf)(a.x-b.x)*(a.x-b.x) + (llf)(a.y-b.y)*(a.y-b.y));
}
inline ll ccw(const P &a,const P &b,const P&c){
    return (ll)a.x*b.y + (ll)b.x*c.y + (ll)c.x*a.y - (ll)b.x*a.y - (ll)c.x*b.y - (ll)a.x*c.y;
}
 
int main(){
#ifndef ONLINE_JUDGE
    freopen("566G.in", "r", stdin);
    freopen("566G.out", "w", stdout);
#endif
    scanf("%d%d",&N,&M);
    scanf("%*d%*d");
    for(int i=1; i<=N+M; i++){
        scanf("%d%d",&inp[i].x,&inp[i].y);
        inp[i].c = i;
    }
    int max_x = 0, max_y = 0;
    for(int i=1;i<=N+M;i++){
        if(inp[max_x].x < inp[i].x || (inp[max_x].x == inp[i].x && inp[max_x].y > inp[i].y))max_x = i;
        if(inp[max_y].y < inp[i].y || (inp[max_y].y == inp[i].y && inp[max_y].x > inp[i].x))max_y = i;
    }
    int SZ = 0;
    for(int i=1;i<=N+M;i++){
        if(inp[i].y > inp[max_x].y && inp[i].x > inp[max_y].x)D[++SZ] = inp[i];
        else if(inp[i].x == inp[max_x].x || inp[i].y == inp[max_y].y)D[++SZ] = inp[i];
    }
    std::sort(D+1, D+SZ+1);
    //for(int i=1;i<=SZ;i++)printf("%d %d %d\n",D[i].x,D[i].y,D[i].c);
    if(SZ == 1){
        if(D[1].c <= N)printf("Max");
        else printf("Min");
        return 0;
    }
    for(int i=1; i<=2; i++) Hull[i] = i; hn = 2;
    for(int i=3; i<=SZ; i++){
        while(hn >= 2 && ccw(D[Hull[hn-1]], D[Hull[hn]], D[i]) > 0) Hull[hn--] = 0;
        if(D[i] == D[Hull[hn]]){
            if(D[Hull[hn]].c > N && D[i].c <= N)Hull[hn] = i;
        }
        else Hull[++hn] = i;
    }
    //for(int i=1;i<=hn;i++)printf("%d %d %d\n",D[Hull[i]].x,D[Hull[i]].y,D[Hull[i]].c);
    bool ans = 0;
    for(int i=1;i<=hn;i++)if(D[Hull[i]].c <= N){ans = 1; break;}
    printf("%s", ans ? "Max" : "Min");
    return 0;
}