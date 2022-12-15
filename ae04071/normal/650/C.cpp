#include <bits/stdc++.h>
using namespace std;

int n,m,mr[1000000],mc[1000000];
vector<vector<int>> ans;
int pa[1000000],pr[1000000],vp[1000000],mp[1000000];
struct td{
    int v,i,j;
    bool operator<(const td &rhs)const {
        if(v!=rhs.v) return v<rhs.v;
        else if(i!=rhs.i) return i<rhs.i;
        else return j<rhs.j;
    }
    int get() {
        return i*m+j;
    }
}arr[1000000];
int find(int cur) {
    return cur==pa[cur] ? cur : pa[cur] = find(pa[cur]);
}
void merge(int u,int v) {
    u=find(u);v=find(v);
    pa[v]=u; mp[u]=max(mp[u],mp[v]);
}

int main() {
    scanf("%d%d",&n,&m);
    ans.resize(n,vector<int>(m,0));

    for(int i=0;i<n;i++) for(int j=0;j<m;j++) {
        int v;
        scanf("%d",&v);
        arr[i*m+j] = {v,i,j};
    }
    sort(arr,arr+n*m);
    for(int i=0;i<n*m;i++) pa[i] = i;

    for(int i=0,j=0;i<n*m;i=j) {
        int tar=arr[i].v;
        for(j=i;j<n*m && tar==arr[j].v;j++) {
            int v = max(mr[arr[j].i], mc[arr[j].j])+1,idx = arr[j].get();
            mp[idx] = v;
            if(j!=i && arr[j-1].i==arr[j].i) merge(arr[j-1].get(), idx);
            if(vp[arr[j].j]==tar) merge(pr[arr[j].j],idx);
            
            pr[arr[j].j] = idx;
            vp[arr[j].j] = tar;
        }
        for(j=i;j<n*m && tar==arr[j].v;j++) {
            int v=mp[find(arr[j].get())];
            ans[arr[j].i][arr[j].j] = v;
            mr[arr[j].i] = max(mr[arr[j].i],v);
            mc[arr[j].j] = max(mc[arr[j].j],v);
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) printf("%d ",ans[i][j]);
        puts("");
    }
    

    return 0;
}