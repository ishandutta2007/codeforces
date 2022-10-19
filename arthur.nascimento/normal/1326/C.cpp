#include <bits/stdc++.h>
#define maxn 400400
#define ll long long
#define pb push_back
#define pii pair<int,int>
#define mod 998244353  
#define debug(args...) printf(args)
using namespace std;

int v[maxn];

int main(){
    
    int n,k;
    scanf("%d%d",&n,&k);
    
    ll mx = 0, qt = 1;
    
    for(int i=0;i<n;i++){
        scanf("%d",v+i);
        if(v[i] > n-k) {mx += v[i]; v[i] = 1;}
        else v[i] = 0;
    }
    
    int u = 0;
    while(v[u] == 0) u++;
    
    int A = 0;
    for(;u<n;u++) {
        if(v[u] == 0){
            A++;
            continue;
        }
        else {
            qt *= (A+1);
            qt %= mod;
            A = 0;
        }
    }
    printf("%lld %lld\n",mx,qt);
}