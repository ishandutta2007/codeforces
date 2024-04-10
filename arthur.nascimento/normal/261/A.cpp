#include <stdio.h>
#include <algorithm>
using namespace std;

int v[100100];

bool comp(int a,int b){
    return b<a;}

main(){
    
    int n,m,x,best=999999;
    scanf("%d",&m);
    
    for(int i=0;i<m;i++){
        scanf("%d",&x);
        best = min(best,x);}
        
    scanf("%d",&n);
    
    for(int i=0;i<n;i++)
        scanf("%d",v+i);
        
    sort(v,v+n,comp);
    
    
    int tipo=0,falta=best;
    
    int ans=0;
    
    for(int i=0;i<n;i++){
        
        
        
        if(tipo==0)ans += v[i];
        
        falta--;
        
        if(falta==0){
            if(tipo==0)falta=2; 
            else falta = best;
            tipo^=1;
        }
        
        
        
    }
    
    printf("%d",ans);}