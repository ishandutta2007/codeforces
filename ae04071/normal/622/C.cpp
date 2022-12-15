#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;

int arr[200001];
set<pii> pos[1000001];
int n,m;
int main() {
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) {
        scanf("%d",arr+i);
    }
    for(int i=1,j;i<=n;i=j) {
        for(j=i;j<=n && arr[i]==arr[j];j++);
        pos[arr[i]].insert({i,j-1});
    }

    while(m--) {
        int l,r,x;
        scanf("%d%d%d",&l,&r,&x);
        
        auto it=pos[x].upper_bound({l,n+1});
        if(it!=pos[x].begin()) {
            auto jt=it;
            jt--;
            if(jt->second >= r){
                puts("-1");
            } else{
                printf("%d\n",max(jt->second+1,l));
            }
        } else{
            printf("%d\n",l);
        }
    }
    return 0;
}