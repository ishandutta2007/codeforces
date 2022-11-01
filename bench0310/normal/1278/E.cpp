#include <bits/stdc++.h>

using namespace std;

const int N=500005;
vector<int> v[N];
vector<int> l(N),r(N);
int idx=2;

void dfs(int a,int p=-1)
{
    for(int to:v[a]) if(to!=p) l[to]=idx++;
    reverse(v[a].begin(),v[a].end());
    r[a]=idx++;
    for(int to:v[a]) if(to!=p) dfs(to,a);
}

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n-1;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    l[1]=1;
    dfs(1);
    for(int i=1;i<=n;i++) printf("%d %d\n",l[i],r[i]);
    return 0;
}