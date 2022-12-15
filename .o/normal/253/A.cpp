#include<stdio.h>

int n, m;

int main(){
#ifdef ABCDTEST
#else
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    
    int i;
    
    scanf("%d%d",&n,&m);
    
    if(n < m){
        for(i = 0; i < n; i++) printf("GB");
        for(i = n; i < m; i++) printf("G");
    }else if(n == m){
        for(i = 0; i < n; i++) printf("GB");
    }else{
        for(i = 0; i < m; i++) printf("BG");
        for(i = m; i < n; i++) printf("B");
    }
    return 0;
}