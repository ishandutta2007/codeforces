#include <bits/stdc++.h>

using namespace std;

struct elem {
    int x,idx,whos;
    elem(){}
    elem(int _x, int _idx, int _whos):x(_x),idx(_idx),whos(_whos){}
    bool operator < (const elem &w) const {
        return x < w.x || x==w.x && whos<=w.whos;
    }
};

int main() {
    int n,m;
    cin>>n>>m;
    vector<elem> b(n+m);
    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        b[i]=elem(x,i,0);
    }
    for(int i=0; i<m; i++){
        int x;
        cin>>x;
        b[i+n]=elem(x,i,1);
    }
    stable_sort(b.begin(),b.end());
    vector<int> ans(m,0);
    int cnt=0;
    for(int i=0; i<n+m; i++)
        if(b[i].whos)
            ans[b[i].idx]=cnt;
        else
            cnt++;
    for(int i=0; i<m; i++)
        cout<<ans[i]<<' ';
}