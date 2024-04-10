#include <bits/stdc++.h>
#define maxn 400400
#define ll long long
#define pb push_back
#define pii pair<int,int>
#define mod 1000000007 
#define debug(args...) printf(args)
using namespace std;
#define llu ll
ll v[maxn];
int foi[maxn];
int ans;
 
map<int,int> mp;
 
void tenta(int n,ll pr){
    if(mp[pr]) return;
    mp[pr] = 1;
    
    ll tt = 0;
    for(int i=0;i<n && tt < n;i++){
        ll dif = (v[i]%pr);
        if(v[i] < pr)
            tt += pr-v[i];
        else tt += min(dif,pr-dif);
    }
    if(tt > n) return;
    ans = min(ans,(int)tt);
    //if(ans == 3) printf("!%lld\n",pr);
}
 
void go(int n,ll num){
    
    for(ll i=2;i*i<=num;i++)
        if(num%i == 0){
            while(num%i == 0) num /= i;
            tenta(n,i);
        }
    if(num > 1) tenta(n,num);
    
}
 
char ch;
void rd(ll &x){
    x = 0;
    while((ch=_getchar_nolock()) >= '0') x = 10*x + ch-'0';
}
 
void rdi(int &x){
    x = 0;
    while((ch=_getchar_nolock()) >= '0') x = 10*x + ch-'0';
}
 
main(){
    int n;
    rdi(n);
    ans = n;
    for(int i=0;i<n;i++)
        rd(v[i]);
    srand(0);
    while(clock() < 2 * CLOCKS_PER_SEC){
        int id = (rand()<<16)+rand();
        id %= n;
        if(foi[id]) continue;
        foi[id] = 1;
        for(int i=-1;i<=1;i++)
            go(n,v[id]+i);
    }
    printf("%d\n",ans);
}