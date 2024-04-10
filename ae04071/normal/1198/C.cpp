#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;

int n,m,chk[300001];
vector<int> ans;

int main() {
    int test;
    scanf("%d",&test);
    while(test--) {
        for(int i=1;i<=3*n;i++) chk[i] = 0;
        ans.clear();

        scanf("%d%d",&n,&m);
        for(int i=0,u,v;i<m;i++) {
            scanf("%d%d",&u,&v);
            if(chk[u]+chk[v]==0) {
                chk[u]=chk[v]=1;
                ans.push_back(i+1);
            }
        }
        if(ans.size()>=n) {
            puts("Matching");
            for(int i=0;i<n;i++) printf("%d ",ans[i]);
            puts("");
        } else {
            puts("IndSet");
            int cnt=n;
            for(int i=1;i<=3*n && cnt;i++) if(!chk[i]) {
                cnt--;
                printf("%d ",i);
            }
            puts("");
        }
    }
    return 0;
}