#include <bits/stdc++.h>
#define sz(x) ((int)(x).size())
using namespace std;
using pii=pair<int,int>;

int n,arr[200000];
bool check(int v) {
    vector<int> a;
    for(int i=0;i<n;i++) {
        if(arr[i] < (1<<v)) a.push_back(arr[i]);
    }
    if(sz(a)<v) return false;

    for(int t=v-1,s=0;t>=0;t--,s++) {
        int idx=-1;
        for(int i=s;i<sz(a);i++) if(a[i]>>t&1) {
            idx=i;
            break;
        }
        if(idx==-1) return false;
        swap(a[s],a[idx]);
        for(int i=s+1;i<sz(a);i++) if(a[i]>>t&1) a[i]^=a[s];
    }
    return true;
}
int pr;
void dfs(int idx,vector<pii> &a) {
    if(idx!=0) {
        dfs(idx-1,a);
    }
    pr^=a[idx].second;
    printf(" %d",pr);
    if(idx!=0) dfs(idx-1,a);
}
void trace(int v) {
    vector<pii> a;
    for(int i=0;i<n;i++) {
        if(arr[i] < (1<<v)) a.push_back(pii(arr[i],arr[i]));
    }

    for(int t=v-1,s=0;t>=0;t--,s++) {
        int idx=-1;
        for(int i=s;i<sz(a);i++) if(a[i].first>>t&1) {
            idx=i;
            break;
        }
        swap(a[s],a[idx]);
        for(int i=s+1;i<sz(a);i++) if(a[i].first>>t&1) a[i].first^=a[s].first;
    }
    
    printf("0");
    
    if(v!=0) dfs(v-1,a);
}
int main() {
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",arr+i);

    int ans=0;
    for(int x=0;x<=20;x++) {
        if(check(x)) {
            ans=x;
        }
    }

    printf("%d\n",ans);
    if(ans==0) printf("0\n");
    else trace(ans);
    
    return 0;
}