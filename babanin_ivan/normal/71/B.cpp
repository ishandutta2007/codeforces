#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <queue>
#include <memory.h>
#include <stack>

using namespace std;

#define pb push_back
#define mp make_pair
#define fir first
#define fi first
#define sec second
#define int64 long long       
#define ld long double

const int inf=2000000000;

int n,k;
ld t;

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    cin>>n>>k>>t;
    t=t/100;
    for (int i=1;i<=n+1;++i){
        for (int j=0;j<=k;++j){
            if (((i-1)*k+j)<=t*n*k && ((i-1)*k+j+1)>t*n*k && (i-1)*k+j<=n*k){
                for (int z=1;z<=i-1;++z)
                    printf("%d ",k);
                printf("%d ",j);
                for (int z=i+1;z<=n;++z)
                    printf("0 ");
                return 0;
            }
        }
    }
    return 0;
}