#include <cstdio>
#include <algorithm>

using namespace std;

int v[110],v1[110],l[110],r[110];

int main() 
{
    //freopen("file.in", "r", stdin);
    //freopen("file.out", "w", stdout);
    int n,nr=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&l[i],&r[i]);
        if(l[i]==0) v[++nr]=i;
    }
    for(int i=1;i<=nr;i++)
    {
        int nod=v[i];
        for(;r[nod];nod=r[nod]);
        v1[i]=nod;
    }
    for(int i=1;i<nr;i++) 
    {
        r[v1[i]]=v[i+1];
        l[v[i+1]]=v1[i];
    }
    for(int i=1;i<=n;i++) printf("%d %d\n",l[i],r[i]);
    return 0;
}