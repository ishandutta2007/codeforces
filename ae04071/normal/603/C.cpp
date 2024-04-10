#include <bits/stdc++.h>
using namespace std;

int n,k;
map<int,int> tr;

int DP(int v) {
    if(v==0 || v==2) return 0;
    else if(v==1 || v==3) return 1;
    else if(v==4 || v==6) return 2;
    else if(v%2==1) return 0;
    
    if(tr.count(v)) return tr[v];
    int ret = DP(v/2);
    if(ret==2 || ret==0) tr[v]=1;
    else tr[v]=2;
    return tr[v];
}
int main() {
    scanf("%d%d",&n,&k);

    int ans=0;
    for(int i=0;i<n;i++) {
        int v;
        scanf("%d",&v);
        if(k%2==0) {
            if(v==2) ans^=2;
            else if(v==1 || v%2==0) ans^=1;
        } else {
            ans ^= DP(v);
        }
    }
    puts(ans ? "Kevin" : "Nicky");
    
    return 0;
}