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

const int maxn = -1;
const int inf = 1e9;


int main(){
//     freopen("in", "r", stdin);
//     freopen("out", "w", stdout);
    int n, k;
    scanf("%d%d", &n, &k);
    if (n * (n - 1) / 2 > k){
        for (int i = 0; i < n; i++)
            printf("%d %d\n", 0, i);
    }
    else
        printf("no solution\n");    
 
    return 0;
}