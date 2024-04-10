#include <bits/stdc++.h>

using namespace std;

const int N=150005;
vector<int> p(N);

int find_set(int a)
{
    if(a==p[a]) return a;
    else return p[a]=find_set(p[a]);
}

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) p[i]=i;
    vector<int> dsu_sz(n+1,1);
    vector<int> dsu_last(n+1,-1);
    vector<int> v(2*n-2);
    vector<int> sz(2*n-2,0);
    vector<int> last(2*n-2,0);
    for(int i=0;i<2*n-2;i+=2)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        tie(v[i],v[i+1])={a,b};
        a=find_set(a);
        b=find_set(b);
        sz[i]=dsu_sz[a];
        sz[i+1]=dsu_sz[b];
        last[i]=dsu_last[a];
        last[i+1]=dsu_last[b];
        if(dsu_sz[a]<dsu_sz[b]) swap(a,b);
        p[b]=a;
        dsu_sz[a]+=dsu_sz[b];
        dsu_last[a]=i/2;
    }
    vector<int> res(n+1,0);
    function<void(int,int,int,int)> solve=[&](int l,int r,int idx,int x)->void
    {
        if(idx==-1) res[l]=x;
        else
        {
            int a=2*idx;
            int b=2*idx+1;
            solve(l,l+sz[a]-1,last[a],v[a]);
            solve(l+sz[a],r,last[b],v[b]);
        }
    };
    solve(1,n,n-2,0);
    for(int i=1;i<=n;i++) printf("%d%c",res[i]," \n"[i==n]);
    return 0;
}