#include <bits/stdc++.h>
#define maxn 400400
#define pii pair<int,int>
#define pb push_back
#define inf 1e9
#define mod 998244353
#define fill rtgrtg
typedef long long ll;
using namespace std;

int qtd[maxn];
int v[maxn];

int fill[maxn];
int cur[maxn];

int ans[maxn];


int main() {
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",v+i);
        v[i] = n-v[i];
        qtd[v[i]]++;
    }

    for(int i=0;i<n;i++)
        if(qtd[v[i]] % v[i] ){
            printf("Impossible\n");
            return 0;
        }
    printf("Possible\n");
    int aa = 1;
    for(int i=0;i<n;i++){
        
        if(fill[v[i]] == 0){
            cur[v[i]] = aa;
            aa++;
        }
        ans[i] = cur[v[i]];
        fill[v[i]]++;
        
        
        if(fill[v[i]] == v[i]) fill[v[i]] = 0;
           
    }
    for(int i=0;i<n;i++) printf("%d ",ans[i]);
    
}