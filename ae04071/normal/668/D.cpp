#include <bits/stdc++.h>
using namespace std;

struct seg_tr{
    vector<int> ta,tr;
    int n;

    void init() {
        sort(ta.begin(),ta.end());
        ta.erase(unique(ta.begin(),ta.end()),ta.end());
        
        n=(int)ta.size();
        tr.resize(n+1,0);
    }
    void add(int cur,int v) {
        cur = lower_bound(ta.begin(),ta.end(),cur)-ta.begin()+1;
        while(cur<=n) tr[cur]+=v, cur+=cur&-cur;
    }
    int get(int cur) {
        cur = upper_bound(ta.begin(),ta.end(),cur)-ta.begin();
        
        int ret=0;
        while(cur) ret+=tr[cur], cur-=cur&-cur;
        return ret;
    }
};

vector<int> xa;
int ty[100001],ti[100001],va[100001],n;
seg_tr arr[100001];

int main() {
    scanf("%d",&n);
    for(int i=0;i<n;i++) {
        scanf("%d%d%d",ty+i,ti+i,va+i);
        if(ty[i]!=3) xa.push_back(va[i]);
    }
    sort(xa.begin(),xa.end());
    xa.erase(unique(xa.begin(),xa.end()),xa.end());
    for(int i=0;i<n;i++) if(ty[i]!=3) {
        int idx = lower_bound(xa.begin(),xa.end(),va[i])-xa.begin();
        arr[idx].ta.push_back(ti[i]);
    }
    for(int i=0;i<(int)xa.size();i++) arr[i].init();

    for(int i=0;i<n;i++) {
        int idx = lower_bound(xa.begin(),xa.end(),va[i])-xa.begin();
        if(ty[i]==1) {
            arr[idx].add(ti[i],1);
        } else if(ty[i]==2) {
            arr[idx].add(ti[i],-1);
        } else {
            if(idx==(int)xa.size() || xa[idx]!=va[i]) puts("0");
            else printf("%d\n",arr[idx].get(ti[i]));
        }
    }

    return 0;
}