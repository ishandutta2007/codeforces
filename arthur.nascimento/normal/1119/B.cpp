#include <bits/stdc++.h>
#define maxn 300300
#define ll long long
using namespace std;
int v[maxn];
int main() {
    int n,h;
    scanf("%d%d",&n,&h);
    for(int i=0;i<n;i++)
     scanf("%d",v+i);
     
    int ans = 0;
    
    for(int i=0;i<n;i++){
            
            sort(v,v+i+1);
            reverse(v,v+i+1);
            
            ll hh = 0;
            
            for(int j=0;j<=i;j+=2)
                hh += v[j];
           
            
            if(hh <= h) ans = i+1;
            
          //  printf("%d %d\n",i,hh);
        
    }
    
    printf("%d\n",ans);
}