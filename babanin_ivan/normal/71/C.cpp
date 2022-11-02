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

int a[200000];
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    int n;
    scanf("%d",&n);
    for (int i=0;i<n;++i)
        scanf("%d",&a[i]);
    for (int i=0;i<n;++i)
        if (a[i]){
            for (int jump=1;jump<=n/2+1;++jump)
                if (n % jump==0 && n/jump>2){
                    int tek=i;
                    int j=0;
                    while (!(tek==i && j>0) && tek>=i && a[tek]){
                        tek=(tek+jump)%n;
                        ++j;
                    }
                    if (tek==i && j){
                        printf("YES\n");
                        return 0;
                    }
                }
        }
    printf("NO\n");
    return 0;
}