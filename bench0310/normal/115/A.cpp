#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N=2005;
vector<int> v[N];
int res=0;

void dfs(int a,int d=1)
{
    res=max(res,d);
    for(int to:v[a]) dfs(to,d+1);
}

int main()
{
    int n;
    scanf("%d",&n);
    vector<int> a;
    for(int i=1;i<=n;i++)
    {
        int p;
        scanf("%d",&p);
        if(p==-1) a.push_back(i);
        else v[p].push_back(i);
    }
    for(int x:a) dfs(x);
    printf("%d\n",res);
    return 0;
}