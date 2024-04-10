#include <bits/stdc++.h>
#define maxn 300300
#define ll long long
using namespace std;

int v[maxn];

int nxt[20][maxn];

int last[20];

int main() {
    
    int n,q;
    scanf("%d%d",&n,&q);
    
    for(int i=0;i<n;i++)
        scanf("%d",v+i);
        
    for(int i=0;i<20;i++)
        last[i] = n;
        
    for(int i=0;i<20;i++)
        for(int j=0;j<=n;j++)
            nxt[i][j] = n;
        
    for(int i=n-1;i>=0;i--){
        
        for(int j=0;j<20;j++)
            if(v[i] & (1<<j))
                for(int k=0;k<20;k++)
                    if((v[i] & (1<<k)) == 0)
                        nxt[k][i] = min(nxt[k][i], nxt[k][last[j]]);
        
        for(int j=0;j<20;j++)
            if(v[i] & (1<<j))
                last[j] = i, nxt[j][i] = i;
    
    }
    
    while(q--){
        
        int a,b;
        scanf("%d%d",&a,&b), a--, b--;
        
        int ans = 0;
        
        for(int i=0;i<20;i++)
            if(v[b] & (1<<i))
                if(nxt[i][a] <= b)
                    ans = 1;
         
        if(ans)
            printf("Shi\n");
        else
            printf("Fou\n");
    }
    
}