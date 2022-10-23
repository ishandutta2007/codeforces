#include<iostream>
#include <vector>
using namespace std;

struct DSU {
    vector<int> p,r;
    int n;
    int components;
    DSU(int _):n(_),components(_) {
        p.resize(n+1);
        r.resize(n+1);
        for(int i=0;i<=_;++i)
            p[i]=i,r[i]=0;
    }
    int parent(int i) {
        return p[i]=(p[i]==i)?i:parent(p[i]);
    }
    void merge(int x,int y) {
        x=parent(x);
        y=parent(y);
        if(x==y)
            return ;
        if(r[x]>r[y])
            p[y]=x;
        else
            p[x]=y;
        if(r[x]==r[y])
            ++r[y];
        --components;
    }
};

int main() {
    int n,m;
    scanf("%d %d",&n,&m);
    DSU dsu(n);
    while(m--)
    {
        int x,y;
        cin >> x >> y;
        dsu.merge(x,y);
    }

    printf("%lld\n", 1LL<<(dsu.n-dsu.components));
}