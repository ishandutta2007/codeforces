#include <bits/stdc++.h>
#define maxn 400400
#define ll long long
#define pb push_back
#define pii pair<int,int>
#define mod 1000000007 
#define debug(args...) printf(args)
using namespace std;

int v[maxn];

int main(){
    
    int nt;
    scanf("%d",&nt);
    
    while(nt--){
        
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            scanf("%d",v+i);
            
        if(v[0]%2 == 0)
            printf("1 1\n");
        else if(n > 1 && v[1]%2 == 0)
            printf("1 2\n");
        else if(n > 1)
            printf("2 1 2\n");
        else printf("-1\n");
        
    }
    
}