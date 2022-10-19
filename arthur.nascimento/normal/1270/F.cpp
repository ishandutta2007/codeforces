#include <bits/stdc++.h>
#define maxn 400400
#define pb push_back
#define ll long long
#define debug 
#define pii pair<int,int>
using namespace std;
#define sq 100

char str[maxn];
int nxt[maxn];
int v[maxn];

int main() {
    scanf(" %s",str);
    int n = strlen(str);
    for(int i=0;i<n;i++)
        v[i] = (str[i] == '1');
    ll ans = 0;
    for(int i=1;i<=sq;i++){
        ll S = 0;
        vector<ll> vv;
        for(int j=0;j<n;j++){
            vv.pb(S);
            if(v[j] == 1) S += (i-1);
            else S--;
        }
        vv.pb(S);
        sort(vv.begin(),vv.end());
        ll cur = 1;
        for(int j=1;j<vv.size();j++){
            if(vv[j] == vv[j-1]) cur++;
            else {
                ans += (cur*cur-cur)/2;
                cur = 1;
            }
        }
        ans += (cur*cur-cur)/2;
    }
    nxt[n] = n;
    for(int i=n-1;i>=0;i--){
        if(v[i]) nxt[i] = i;
        else nxt[i] = nxt[i+1];
    }
    for(int ini=0;ini<n;ini++){
        int last = nxt[ini];
        if(last == n) break;
        int qtd = 1;
        while(1){
            
            int prox = nxt[last+1];
            
            int Fi = ini + (sq+1) * qtd;
            
            if(Fi <= last){
                int add = last-Fi+1;
                int dv = add/qtd;
                if(add%qtd) dv++;
                Fi += dv * qtd;
            }
            
            if(Fi <= prox){
                int jmp = prox-Fi;
                ans += 1 + (jmp/qtd);
            }
            
            
            if(prox >= n) break;
            if(Fi >= n) break;
            
            last = prox;
            qtd++;
            
        }
    }
    printf("%lld\n",ans);
}