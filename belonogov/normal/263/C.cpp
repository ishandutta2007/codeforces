#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <cstring>
#include <cassert>
#include <ctime>


using namespace std;
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

#ifdef DEBUG
    #define epr(...) fprintf(stderr, __VA_ARGS__)
#else
    #define epr ()
#endif 


typedef long long ll;
typedef vector < int > vi;

const int maxn = (int)2e5;
const int inf = (int)1e9;
vector < int > edge[maxn];
int use[maxn];
int a[maxn];
int n;


void solve(int x1, int x2, int x3, int x4, int x5){
    bool flag;
    int next;
    a[0] = x1;
    a[1] = x2;
    a[2] = x3;
    a[3] = x4;
    a[4] = x5;
    memset(use, 0, sizeof(use));
    for(int i = 0; i < 5; i++)
        use[a[i]] = 1;
//     for(int i = 0; i < 5; i++)
//         epr("%d ", a[i]);
//     epr("\n");
//     
    for(int i = 5; i < n; i++){
        next = -1;
        for(int j = 0; j < 4; j++)
            if (!use[edge[a[i - 2]][j]])
    next = edge[a[i - 2]][j];
        if (next == -1)
            return;
        a[i] = next;
        use[a[i]] = 1;
    }
    /// check 1
    for(int i = 0; i < n; i++){
        flag = 0;
        for(int j = 0; j < 4; j++)
            if (edge[a[i]][j] == a[(i + 1) % n])
    flag = 1;        
        if (!flag){
//             epr("%d\n", i);
            return;
        }

    }
//     epr("second\n");
    ///check 2 
    for(int i = 0; i < n; i++){
        flag = 0;
        for(int j = 0; j < 4; j++)
            if (edge[a[i]][j] == a[(i + 2) % n])
    flag = 1;        
        if (!flag){
//             epr("%d val %d\n", i, a[(i + 2) % n]);
//             epr("edge\n");
//             for(int j = 0; j < (int)edge[i].size(); j++)
//  epr("%d ", edge[i][j]);
//             epr("\n");
            return;
        }
    }
    
    
    for(int i = 0; i < n; i++)
        printf("%d ", a[i] + 1);
    printf("\n");
    exit(0);
    
}

int main(){
//     freopen("in", "r", stdin);
//     freopen("out", "w", stdout);
    int x1, x2, x3, x4, x, y;
    scanf("%d", &n);
    for(int i = 0; i < n * 2; i++){
        scanf("%d%d", &x, &y); x--; y--;
        edge[x].pb(y);
        edge[y].pb(x);
    }
    for(int i = 0; i < n; i++)
        if ((int)edge[i].size() != 4){
            printf("-1\n");
            return 0;
        }
    x1 = edge[0][0];
    x2 = edge[0][1];
    x3 = edge[0][2];
    x4 = edge[0][3];
    solve(x1, x2, 0, x3, x4);
    solve(x1, x2, 0, x4, x3);
    solve(x1, x3, 0, x2, x4);
    solve(x1, x3, 0, x4, x2);
    solve(x1, x4, 0, x2, x3);
    solve(x1, x4, 0, x3, x2);
    
    
    solve(x2, x1, 0, x3, x4);
    solve(x2, x1, 0, x4, x3);
    solve(x2, x3, 0, x1, x4);
    solve(x2, x3, 0, x4, x1);
    solve(x2, x4, 0, x1, x3);
    solve(x2, x4, 0, x3, x1);
    
    
    solve(x3, x1, 0, x2, x4);
    solve(x3, x1, 0, x4, x2);
    solve(x3, x2, 0, x1, x4);
    solve(x3, x2, 0, x4, x1);
    solve(x3, x4, 0, x1, x2);
    solve(x3, x4, 0, x2, x1);
    
    solve(x4, x1, 0, x2, x3);
    solve(x4, x1, 0, x3, x2);
    solve(x4, x2, 0, x1, x3);
    solve(x4, x2, 0, x3, x1);
    solve(x4, x3, 0, x1, x2);
    solve(x4, x3, 0, x2, x1);
    
    
    printf("-1\n");
//     assert(false);
//     epr("fail\n");
    
    return 0;
}