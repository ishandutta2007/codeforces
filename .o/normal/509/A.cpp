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
#include <numeric>
#include <deque>
#include <utility>
#include <bitset>
#include <limits.h>
#include <iostream>

using namespace std;
typedef long long ll;
typedef unsigned long long llu;
typedef double lf;
typedef unsigned int uint;
typedef long double llf;
typedef pair<int, int> pii;


const int M_ = 100500;
const ll MOD = (ll)1e9 + 7;
/*The first row and the first column contain ones, that is: ai,1=a1,i=1 for all i=1,2,...,n.
 Each of the remaining numbers in the table is equal to the sum of the number above it and the number to the left of it. In other words, the remaining elements are defined by the formula ai,j=ai-1,j+ai,j-1.*/

int a[100][100],res;
int main() {
    //freopen("input.txt", "r", stdin);

    int n; scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= n; j++) {
    if(i == 1 || j == 1) a[i][j] = 1;
    else a[i][j] = a[i-1][j] + a[i][j-1];
    res=  max(res, a[i][j]);
    }
    }
    printf("%d", res);
    return 0;
}