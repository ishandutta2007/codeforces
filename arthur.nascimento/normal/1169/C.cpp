#include <bits/stdc++.h>
#define maxn 300300
#define ll long long
using namespace std;

int v[maxn];

main(){
    
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
        scanf("%d",v+i);
        
    int lo = 0, hi = m;
    while(lo != hi){
        int mid = (lo+hi)/2;
        int u = 0, ok = 1;
        for(int i=0;i<n;i++){
            if(v[i] <= u && u <= v[i]+mid) continue;
            if(v[i] <= u) ok = 0;
            if(u+m-v[i] <= mid) continue;
            u = v[i];
        }
        if(ok)
            hi = mid;
        else
            lo = mid+1;
    }
    printf("%d\n",hi);
}