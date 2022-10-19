#include <iostream>
#include <vector>
#include <algorithm>

#define M 100100

using namespace std;

long n, a[M], b[M], s[2*M],q=0;
vector<long> g[2*M];
bool u[2*M];

void read(void){
    cin>>n;
    for (long i=0; i<n;++i){
        cin>>a[i]>>b[i];
        s[q++]=a[i];
        s[q++]=b[i];
    }
}

long num(long x){
    long l=0, r=q-1, m;
    while (l<r){
        m=(l+r)/2;
        if (s[m]<x)
        l=m+1;
        else
        r=m;
    }
    return l;
}

void make(void){
    for (long i=0; i<n; ++i){
        g[num(a[i])].push_back(num(b[i]));
        g[num(b[i])].push_back(num(a[i]));
    }
}

void dfs(long v){
    u[v]=1;
    cout<<s[v]<<" ";
    for (long i=0; i<g[v].size(); ++i)
    if (!u[g[v][i]])
    dfs(g[v][i]);
}


int main()
{
    read();
    sort(s,s+q);
    make();
    for (long i=0; i<q; ++i)
    if (g[i].size()==1){
        dfs(i);
        break;
    }
    return 0;
}