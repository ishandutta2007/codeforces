#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;

int n,cnt[100001];;
int main() {
    scanf("%d",&n);
    
    int ans=1;
    set<pii> tr;
    for(int i=0;i<n;i++) {
        int v;
        scanf("%d",&v);
        
        int c=cnt[v];
        auto it=tr.find({c,v});
        if(it==tr.end()) tr.insert({1,v});
        else {
            tr.insert({c+1,v});
            tr.erase(it);
        }
        cnt[v]++;
        if(tr.size()==1 || (prev(tr.end())->first==tr.begin()->first+1 &&
                 (prev(prev(tr.end()))->first==tr.begin()->first)) ||
                (tr.begin()->first==1 && next(tr.begin())->first==prev(tr.end())->first) ) {
            ans=i+1;
        }
    }
    printf("%d\n",ans);
    
    return 0;
}