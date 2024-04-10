#include <bits/stdc++.h>
using namespace std;

bool check(int v) {
    for(int i=0;1<<i<=v;i++) if(!(v>>i&1)) return true;
    return false;
}
int main() {
    int n;
    scanf("%d",&n);
    vector<int> ans;
    
    int cnt=0;
    if(true) {
        while(check(n)) {
            int v=0,mx=-1;
            for(;1<<v<=n;v++) if(!(n>>v&1)) {
                mx=max(mx,v);
            }
            if(mx==-1) break;
            ans.push_back(mx+1);
            n ^= ((1<<(mx+1))-1);
            cnt++;
            if(!check(n)) break;
            n+=1;
            cnt++;
        }
    } else {
        while(check(n)) {
            for(int i=0;i<=1<<n;i++) if(n>>i&1) {
                ans.push_back(i);
                n ^= ((1<<(i))-1);
                printf("%d %d\n",i,n);
                break;
            }
            cnt++;
            if(!check(n)) break;
            cnt++;
            n+=1;
        }
    }
    printf("%d\n",cnt);
    for(auto &v:ans) printf("%d ",v);
    
    return 0;
}