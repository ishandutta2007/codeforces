#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N=100005;
vector<int> v[N];
vector<int> d(N,0);
vector<bool> c(2,0);
int two;

void dfs(int a,int depth,int p=-1)
{
    int cnt=0;
    if(d[a]==1) c[depth%2]=1;
    for(int to:v[a])
    {
        if(to==p) continue;
        dfs(to,depth+1,a);
        cnt+=(d[to]==1);
    }
    if(cnt>0) two-=(cnt-1);
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
        d[a]++;
        d[b]++;
    }
    int root=1;
    for(int i=1;i<=n;i++) if(d[i]>1) root=i;
    two=n-1;
    dfs(root,0);
    int one=1;
    if(c[0]&&c[1]) one=3;
    printf("%d %d\n",one,two);
    return 0;
}