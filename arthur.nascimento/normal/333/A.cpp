#include <iostream>
#include <algorithm>
#include <cmath>
#include <assert.h>
#include <stdio.h>
#include <ctime>
#include <cstdlib>
#include <utility>
#include <string.h>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
 
#define INF (1<<30)
#define pii pair<int,int>
#define eps 1e-9
#define max3(a,b,c) max(max(a,b),c)


#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif
 
using namespace std;

main(){

    long long n;
    cin >> n;

    long long k = 1;
    for(long long i=3;i<=n;i*=3)
        if(n % i == 0)
            k = i;

    cout << 1 + (n/(3*k));
    }