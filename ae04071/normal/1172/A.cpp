#include <bits/stdc++.h>
#define fi first
#define se second
#define sz(x) ((int)(x).size())
using namespace std;
using lli = long long;
using pii = pair<int,int>;
using pli = pair<lli,int>;
using pll = pair<lli,lli>;
using pdd = pair<double,double>;

int n,arr[200001],brr[200001],has[200001],tmp[200001];

int pre() {
    if(has[1]) return -1;
    int s=0;
    for(;s<n;s++) if(brr[s]==1) {
        for(int j=s+1;j<n;j++) if(brr[j]!=j-s+1) return -1;

        for(int i=1;i<=n;i++) tmp[i] = has[i];
        
        int nd=n-s+1;
        for(int i=0;i<s;i++,nd++) {
            if(!tmp[nd]) return -1;
            tmp[brr[i]]=1;
        }
        return s;
    }
    return -1;
}
bool check(int t) {
    for(int i=1;i<=n;i++) tmp[i] = has[i];
    for(int i=0;i<t;i++) if(brr[i]!=0) tmp[brr[i]]=1;
    
    for(int i=1,j=t;j<n;i++,j++) {
        if(!tmp[i]) return false;
        if(brr[j]!=0) tmp[brr[j]]=1;
    }
    return true;
}
int main() {
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",arr+i);
    for(int i=0;i<n;i++) scanf("%d",brr+i);
    for(int i=0;i<n;i++) has[arr[i]]=1;

    int v=pre();
    if(v!=-1) {
        printf("%d\n",v);
        return 0;
    }
    
    int lo=-1,up=n;
    if(!has[1]) {
        for(lo=0;lo<n && brr[lo]!=1;lo++);
    }
    while(up-lo>1) {
        int md=(lo+up)>>1;
        if(check(md)) up=md;
        else lo=md;
    }
    printf("%d\n",up+n);
    
    return 0;
}