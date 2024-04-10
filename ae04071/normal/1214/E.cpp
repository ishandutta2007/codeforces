#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
using pii = pair<int,int>;

int n;
pii arr[100000];
int que[200001],f,mx;

int main() {
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&arr[i].fi),arr[i].se = i;
    sort(arr,arr+n,greater<pii>());

    for(;f<n;f++) que[f] = 2*arr[f].se;
    
    vector<pii> ret;
    for(int i=1;i<n;i++) ret.push_back({que[i-1],que[i]});
    
    int cd = n-1;
    mx = f;
    for(int i=0;i<n;i++) {
        while(cd >= arr[i].fi) cd--, f--;
        ret.push_back({que[f-1], 2*arr[i].se+1});
        
        if(f==mx) {
            que[f] = 2*arr[i].se+1;
            mx++;
        }
        f++;
    }
    for(auto &e:ret) printf("%d %d\n",e.fi+1,e.se+1);
    
    return 0;
}