#include <algorithm>
#include <cstdio>
#define zs(x) ((x)&(-x))

using namespace std;

const int N=200005;

int a[N], aib[N];
int n;

void update(int i, int val)
{
    for(;i<N;i+=zs(i)) aib[i]=max(aib[i], val);
}

int query(int i)
{
    int ret=0;
    for(;i>0;i-=zs(i)) ret=max(ret, aib[i]);
    return ret;
}

int main()
{
    //freopen("input", "r", stdin);
    //freopen("output", "w", stdout);
    int i, sol=0, s;
    scanf("%d", &n);
    for(i=1;i<=n;i++) scanf("%d", &a[i]);
    for(i=1;i<=n;i++)
    {
        s=query(a[i]-1);
        update(a[i], s+1);
        sol=max(sol, s);
    }
    printf("%d", sol+1);
}