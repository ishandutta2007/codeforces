#include <cstdio>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;
int n;
vector<pair<int,int> > v;
int ans[200003];
int vis[200003];
int x=0;
int find_idx(int k){
    int l=0,r=n,m;
    if(v[n-1].first < k) return n;
    while(r-l>1){
        m=(l+r)/2;
        if(v[m].first < k) l = m;
        else r = m;
    }
    return r;
}
int main(){
    int m,d;
    scanf("%d%d%d",&n,&m,&d);
    for(int i=0;i<n;i++){
        int a;
        scanf("%d",&a);
        v.push_back(make_pair(a,i));
    }
    sort(v.begin(),v.end());
    for(int i=0;i<n;i++){
        for(;vis[i] && i < n;i++);
        if(i==n) break;
        x++;
        vis[i]=1;
        ans[v[i].second]=x;
        int tmp=i;
        while((tmp = find_idx(v[tmp].first+d+1)) != n){
            for(;vis[tmp] && tmp < n; tmp++);
            if(tmp==n) break;
            vis[tmp]=1;
            ans[v[tmp].second]=x;
        }
    }
    printf("%d\n",x);
    for(int i=0;i<n;i++) printf("%d ",ans[i]);
}