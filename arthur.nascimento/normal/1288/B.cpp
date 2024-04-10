#include <bits/stdc++.h>
#define maxn 400400
#define pb push_back
#define ll long long
#define pii pair<int,int>
#define debug 
#define mk make_pair
#define pii pair<int,int>
#define mod 1000000007 
using namespace std;

int has[256];
int v[maxn][8];

int mask[maxn];

main(){
    
    int nt;
    scanf("%d",&nt);
    while(nt--){
        ll a,b;
        scanf("%lld%lld",&a,&b);
        int u = 0, num = 9;
        while(num <= b){
            u++;
            num = 10*num+9;
        }
        printf("%lld\n",a*u);
    }
}