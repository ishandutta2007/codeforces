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

const int maxn = 1e5;
const int inf = 1e9;

int a[maxn];


int main(){
//     freopen("in", "r", stdin);
//     freopen("out", "w", stdout);
    int n, sum = 0, cnt = 0, mn = inf;
    scanf("%d", &n);
    for(int i = 0; i < n * 2 - 1; i++){
    scanf("%d", &a[i]);
    sum += abs(a[i]);
    cnt += a[i] < 0;       
    mn = min(mn, abs(a[i]));
    }
    if (n % 2 == 0){
    if (cnt % 2 == 1)
        printf("%d\n", sum - mn * 2);
    else
        printf("%d\n", sum);
    }
    else{
    printf("%d\n", sum);
    }
    
    return 0;
}