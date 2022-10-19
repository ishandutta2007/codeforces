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
    
    int n,m;
    scanf("%d%d",&n,&m);
    
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            scanf("%d",&v[i][j]);
    
    int lo = 0, hi = mod;
    int x,y;
    while(1){
        int mid = (lo+hi+1)/2;
        for(int i=0;i<256;i++) has[i] = -1;
        for(int i=0;i<n;i++){
            mask[i] = 0;
            for(int j=0;j<m;j++)
                if(v[i][j] >= mid)
                    mask[i] |= (1<<j);
            has[mask[i]] = i;
            if(lo == hi) debug("i %d mask %d\n",i,mask[i]);
        }
        
        for(int i=255;i>=0;i--)
            for(int j=0;j<8;j++)
                has[i] = max(has[i],has[i|(1<<j)]);
        
        int ok = 0;
        for(int i=0;i<n;i++){
            int need = ((1<<m)-1) - mask[i];
            if(has[need]+1){
                ok = 1;
                x = i;
                y = has[need];
            }
        }
        
        if(lo == hi) break;
        if(ok) lo = mid;
        else hi = mid-1;
    }
    printf("%d %d\n",x+1,y+1,lo);
}