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

const int maxn = -1;
const int inf = (int)1e9;



int main(){
//     freopen("in", "r", stdin);
//     freopen("out", "w", stdout);
    int sum1 = 0, sum2 = 0, n, x, y;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d%d", &x, &y);
        if (sum1 + x - sum2 <= 500){
            sum1 += x;
            printf("A");
            continue;
        }        
        sum2 += y;
        printf("G");
    }
    
    
    
    return 0;
}