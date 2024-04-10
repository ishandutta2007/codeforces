#include <bits/stdc++.h>
using namespace std;

int n,m,pa[1001],ret[1001];

int find(int cur) {
    return cur==pa[cur]?cur : pa[cur]=find(pa[cur]);
}
int main() {
    scanf("%d%d",&n,&m);

    vector<pair<int,int>> arr;
    for(int i=1;i<=n;i++) pa[i] = i;

    for(int i=0;i<m;i++) {
        int t,l,r;
        scanf("%d%d%d",&t,&l,&r);
        if(t==1){
            for(int i=l;i<=r;i++) pa[i] = find(l);
        }else arr.push_back({l,r});
    }

    int c=0;
    for(int i=1;i<=n;i++) if(i==find(i)) c++;
    for(int i=1;i<=n;i++) if(i==find(i)) ret[i]=c--;
    for(auto &v:arr) {
        int l=find(v.first),r=find(v.second);
        if(l==r) {
            puts("NO");
            return 0;
        }
    }
    puts("YES");
    for(int i=1;i<=n;i++) printf("%d ",ret[find(i)]);
    
    return 0;
}