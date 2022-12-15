#include <bits/stdc++.h>
using namespace std;

int n,m;

int get(int v) {
    if(v==1) return 1;
    v--;

    int cnt=0;
    while(v) {
        cnt++; v/=7;
    }
    return cnt;
}

int main() {
    scanf("%d%d",&n,&m);
    
    int nc=0,mc=0;
    nc = get(n); mc = get(m);

    if(nc+mc>7) {
        puts("0");
        return 0;
    }

    int a[7]={0,1,2,3,4,5,6},ans=0;

    set<pair<int,int>> tr;
    do{
        int av=0,bv=0;
        for(int i=0;i<nc;i++) av = av * 7 + a[i];
        for(int i=nc;i<nc+mc;i++) bv = bv * 7 + a[i];

        if(av<n && bv<m && tr.find({av,bv})==tr.end()) {
            ans++;
            tr.insert({av,bv});
        }
    }while(next_permutation(a,a+7));

    printf("%d\n",ans);
    
    return 0;
}