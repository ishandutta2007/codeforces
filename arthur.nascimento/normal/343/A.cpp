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

#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

using namespace std;

long long gcd(long long a,long long b){
     return (b==1) ? a : gcd(b,a%b) + a/b;}

main(){
       
       long long a,b;
       cin >> a >> b;
       
       cout << gcd(a,b) << endl;
       
       }