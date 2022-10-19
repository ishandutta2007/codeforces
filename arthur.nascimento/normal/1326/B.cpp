#include <bits/stdc++.h>
#define maxn 400400
#define ll long long
#define pb push_back
#define pii pair<int,int>
#define mod 1000000007 
#define debug(args...) printf(args)
using namespace std;

int v[maxn];

int main(){
    
    int n;
    scanf("%d",&n);
    ll mx =0 ;
    for(int i=0;i<n;i++){
        ll a;
        scanf("%lld",&a);
        printf("%lld ",a+mx);
        mx = max(mx,a+mx);
    }
    printf("\n");
    
}