#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;

int n,m;
struct edge{
    int c,t,i;
    bool operator<(const edge &rhs)const {
        return c==rhs.c ? t>rhs.t : c<rhs.c;
    }
}arr[100000];
pii ans[100001];

int main() {
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++) scanf("%d%d",&arr[i].c,&arr[i].t),arr[i].i=i;
    sort(arr,arr+m);

    int mx=1,a=2,b=3;
    for(int i=0;i<m;i++) {
        if(arr[i].t==1) {
            mx++;
            ans[arr[i].i]=pii(1,mx);
        }
        else {
            if(b>mx) {
                puts("-1");
                return 0;
            }
            ans[arr[i].i]=pii(a,b);
            a++;
            if(a==b) {
                a=2; b++;
            }
        }
    }
    for(int i=0;i<m;i++) printf("%d %d\n",ans[i].first,ans[i].second);
    return 0;
}