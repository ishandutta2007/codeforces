#include <bits/stdc++.h>
#define mp make_pair
#define fi first
#define se second
#define sz(x) ((int)(x).size())
using namespace std;
typedef long long lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
typedef pair<lli,int> pli;

int main(){
    int test;
    scanf("%d",&test);
    while(test--){
        lli d;
        double a,b;
        scanf("%lld",&d);
        if(d*d-4*d<0){
            puts("N"); continue;
        }
        b=(d+sqrt(d*d-4*d))/2;
        a=d-b;
        printf("Y ");
        printf("%.9lf %.9lf\n",a,b);
    }

    return 0;
}