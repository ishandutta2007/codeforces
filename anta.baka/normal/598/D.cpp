#include <bits/stdc++.h>

using namespace std;

struct dsu {
    int n;
    vector<int> par;
    vector<int> Size;
    dsu(vector<int> &a) {
        n = a.size();
        par.resize(n);
        Size.resize(n);
        for(int i = 0; i < n; i++) {
            par[i] = i;
            Size[i] = a[i];
        }
    }
    inline int find(int p) {
        if(par[p] == p)
            return p;
        return par[p] = find(par[p]);
    }
    inline void uni(int u, int v) {
        u = find(u);
        v = find(v);
        if(u != v) {
            if(Size[u] < Size[v])
                swap(u, v);
            par[v] = u;
            Size[u] += Size[v];
        }
    }
};

const int dx[] = {0,0,-1,1};
const int dy[] = {-1,1,0,0};

char a[1000][1000];

int main() {
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin>>a[i][j];
    vector<int> f(n*m,0);
    for(int i=1; i<n-1; i++)
        for(int j=1; j<m-1; j++)
            for(int w=0; w<4; w++) {
                int ii = i+dx[w];
                int jj = j+dy[w];
                if(a[ii][jj]=='*')
                    f[i*m+j]++;
            }
    dsu _(f);
    for(int i=1; i<n-1; i++)
        for(int j=1; j<m-1; j++)
            if(a[i][j]=='.')
                for(int w=0; w<4; w++) {
                    int ii = i+dx[w];
                    int jj = j+dy[w];
                    if(a[ii][jj]=='.')
                        _.uni(i*m+j,ii*m+jj);
                }
    for(int i=0; i<k; i++) {
        int p,q;
        cin>>p>>q;
        --p;--q;
        cout<<_.Size[_.find(p*m+q)]<<"\n";
    }
}