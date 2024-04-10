#include <bits/stdc++.h>
#define fi first
#define se second
#define sz(x) ((int)(x).size())
#define all(x) x.begin(),x.end()
using namespace std;
using lli = long long;
using pii = pair<int,int>;
using pll = pair<lli,lli>;
using pli = pair<lli,int>;
using pdd = pair<double,double>;

int n,arr[300000],m;

bool check(int d) {
    int mx=0;
    for(int i=0;i<n;i++) {
        if(arr[i]+d>=m) {
            if(mx<=(arr[i]+d)%m);
            else {
                mx = max(mx,arr[i]);
            }
        } else {
            if(mx > arr[i]+d) return false;
            mx=max(mx,arr[i]);
        }
    }
    return true;
}
int main() {
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++) scanf("%d",arr+i);

    int lo=-1,up=m;
    while(up-lo>1) {
        int md=(lo+up)>>1;
        if(check(md)) up=md;
        else lo=md;
    }
    printf("%d\n",up);
    
    return 0;
}