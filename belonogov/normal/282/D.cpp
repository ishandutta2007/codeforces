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
#include <queue>

using namespace std;
#define pb push_back
#define mp make_pair
#define fr first
#define sc second

#ifdef DEBUG
    #define epr(...) fprintf(stderr, __VA_ARGS__)
#else
    #define epr 
#endif 

const int maxn = 310;
const int inf = (int)1e9;

int a2[maxn][maxn];

bool dfs2(int x, int y){
    int mn;
    if (a2[x][y] == -1){
        bool flag = 0;
        mn = min(x, y);
        for(int i = 1; i <= mn; i++)
            if (!dfs2(x - i, y - i))
    flag = 1;
        for(int i = 1; i <= x; i++)
            if (!dfs2(x - i, y))
    flag = 1;
        
        for(int i = 1; i <= y; i++)
            if (!dfs2(x, y - i))
    flag = 1;
      
        a2[x][y] = flag;            
    }
    return a2[x][y];
    
}

int main(){
//     freopen("in", "r", stdin);
//     freopen("out", "w", stdout);
    int n, x = 0;
    int a[10];
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        x = a[i] ^ x;
    }
//     cout << x << endl;
    if (n % 2 == 1){
        if (x) 
            cout << "BitLGM\n";
        else
            cout << "BitAryo\n";
        return 0;
    }
    memset(a2, -1, sizeof(a2));
    if (dfs2(a[0], a[1]))
        cout << "BitLGM\n";
    else
        cout << "BitAryo\n";


    return 0;
}