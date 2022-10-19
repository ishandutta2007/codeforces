#include <bits/stdc++.h>
#define maxn 1010
#define ll long long
#define debug printf
using namespace std;

ll S[maxn];
ll S2[maxn];

int mrk[maxn];

int main() {
    
    int n,t;
    scanf("%d%d",&n,&t);
    
    for(int i=0;i<t;i++){
        int u = n, a;
        while(u--){
            scanf("%d",&a);
            S[i] += a;
            S2[i] += (ll) a*a;
        }
    }
    
    for(int i=0;i<t-2;i++){
        if(2*S[i+1] != S[i] + S[i+2])
            mrk[i]++, mrk[i+1]++, mrk[i+2]++;
        
    }
            
    int p = 0;
    while(mrk[p] < 3 && p < t) p++;
    if(p == t && mrk[1] == 2) p = 1;
    if(p == t && mrk[t-2] == 2) p = t-2;
    if(p == t && mrk[0] == 1) p = 0;
    if(p == t && mrk[t-1] == 1) p = t-1;
    
    int rev = 0;
    if(p <= 2){
        reverse(S,S+t);
        reverse(S2,S2+t);
        rev = 1;
        p = t - p - 1;
    }
    
    /*
    xi^2

    xi^2 + 2*xi*vi + vi^2

    xi^2 + 4*xi*vi + 4*vi^2
    
    */
    
    ll sv = S[1] - S[0];
    ll s2v = (S2[2] - 2*S2[1] + S2[0]) / 2;
    
    ll S_ = S[p-1] + sv;
    ll S2_ = 2*S2[p-1] - S2[p-2] + 2 * s2v;
    
    /*
    
    x - y = S_ - S[p]
    x^2 - y^2 = S2_ - S2[p]
    
    */
    
    ll ss = (S2_ - S2[p]) / (S_ - S[p]);
    
    ll x = (S_ - S[p] + ss) / 2;
    
    if(rev) p = t - p - 1;
    
    printf("%d %lld\n",p,x);
    
    
}