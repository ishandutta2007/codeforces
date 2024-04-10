#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cassert>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <set>
#include <map>
#include <vector>
#include <queue>

using namespace std;

#define fr first
#define sc second
#define mp make_pair
#define pb push_back

#define epr(...) fprintf(stderr, __VA_ARGS__)

const int maxn = 2000;
const int inf = 1e9;

// int a[maxn][maxn];


int main(){
//     freopen("in", "r", stdin);
//     freopen("out", "w", stdout);
    long long x, y, m;
    long long cnt;
    cin >> x >> y >> m;
    if (x >= m || y >= m){ 
    printf("0\n");
    return 0;
    }
    if (x < 1 && y < 1){
    printf("-1\n");
    return 0;
    }
   
    cnt = 0;
    if (x < y) swap(x, y);
    if (y < 0){
    long long k = -y / x;
    y += k * x;
    cnt = k;
    }
    
    
    for(;;cnt++){
    if (x >= m || y >= m){
        cout << cnt << endl;
        return 0;
    }
    if (y > x) swap(x, y);
    y = (x + y);
    }
    
    
    return 0;
}