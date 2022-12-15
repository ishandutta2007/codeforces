#include <bits/stdc++.h>
#define fi first
#define se second
#define sz(x) ((int)x.size())
using namespace std;
typedef long long lli;
typedef pair<lli,int> pli;
typedef pair<int,int> pii;

int n,m,l;
lli a[100001];
set<pii> tr;

void ins(int idx){
    int l=idx,r=idx;
    auto it=tr.lower_bound(pii(idx,idx));
    if(it!=tr.end() && it->fi == idx+1) {
        r=it->se;
        tr.erase(it);

    }
    it=tr.lower_bound(pii(idx,idx));
    if(it!=tr.begin()) {
        it--;
        if(it->se==idx-1){
            l=it->fi;
            tr.erase(it);

        }
    }
    tr.insert(pii(l,r));
}
int main(){
    scanf("%d%d%d",&n,&m,&l);
    for(int i=1;i<=n;i++){
        scanf("%lld",a+i);
        if(a[i]>l) ins(i);
    }

    while(m--){
        int t,b,c;
        scanf("%d",&t);
        if(t==0) {
            printf("%d\n",sz(tr));
        } else{
            scanf("%d%d",&b,&c);
            if(a[b]<=l){
                a[b]+=c;
                if(a[b]>l){
                    ins(b);
                }
            }
        }
    }

    return 0;
}