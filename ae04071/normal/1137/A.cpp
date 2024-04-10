#include <bits/stdc++.h>
using namespace std;

int n,m,arr[1000][1000],ans[1000][1000];
vector<int> ra[1000],ca[1000];

int main() {
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) {
        scanf("%d",&arr[i][j]),ra[i].push_back(arr[i][j]),ca[j].push_back(arr[i][j]);
    }

    for(int i=0;i<n;i++) {
        sort(ra[i].begin(),ra[i].end());
        ra[i].erase(unique(ra[i].begin(),ra[i].end()),ra[i].end());
    }
    for(int i=0;i<m;i++) {
        sort(ca[i].begin(),ca[i].end());
        ca[i].erase(unique(ca[i].begin(),ca[i].end()),ca[i].end());
    }
    
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            auto ri=lower_bound(ra[i].begin(),ra[i].end(),arr[i][j]);
            auto ci=lower_bound(ca[j].begin(),ca[j].end(),arr[i][j]);
            
            int v=max(ri-ra[i].begin(),ci-ca[j].begin());
            v = max(ra[i].end()-ri, ca[j].end()-ci)+v;
            printf("%d ",v);
        }
        puts("");
    }

    return 0;
}