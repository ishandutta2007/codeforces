#include <iostream>
#include <iomanip>
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

#define inf (999999999999LL)
#define pii pair<int,int>
#define pip pair<int,pii>
#define pll pair<long long,long long>
#define eps 1e-8

#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

#define pb push_back
#define maxn 5050
#define mod 1000000007

using namespace std;

main(){
        
        int n;
        scanf("%d",&n);
        set<int> S;
        while(n--){
                int u;
                scanf("%d",&u);
                while(u%2==0)u/=2;
                while(u%3==0)u/=3;
                S.insert(u);
        }
        printf("%s\n",(S.size()==1)?"Yes":"No");
     }