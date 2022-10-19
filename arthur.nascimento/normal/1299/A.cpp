#include <bits/stdc++.h>
#define maxn 400400
#define ll long long
#define pb push_back
#define pii pair<int,int>
#define mod 1000000007 
#define debug(args...) printf(args)
using namespace std;

int v[maxn];
int cnt[33];

main(){
    
    int n;
    scanf("%d",&n);
    
    for(int i=0;i<n;i++){
        scanf("%d",v+i);
        for(int j=0;j<32;j++)
            if(v[i] & (1<<j)) cnt[j]++;
    }
    
    int ans = 0, pos = 0;
    
    for(int i=0;i<n;i++){
        
        int num = v[i];
        for(int j=0;j<32;j++)
            if(v[i] & (1<<j))
                if(cnt[j] > 1)
                    num -= (1<<j);
                    
        if(num > ans){
            ans = num;
            pos = i;
        }
        
    }
    
   // printf("%d\n",ans);
    swap(v[0],v[pos]);
    for(int i=0;i<n;i++)
        printf("%d ",v[i]);
    printf("\n");
}