#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<iostream>
#include<vector>
#include<string>
using namespace std;
typedef long long LL;
const int V=300100;
struct Node
{
    int x,id;
}q[V];
bool cmp(Node x,Node y)
{
    return x.x<y.x;
}
int ret[V],n;
int main()
{
    while(~scanf("%d",&n))
    {
        for(int i=0;i<n;i++)
        {
            scanf("%d",&q[i].x);
            q[i].id=i;
        }
        sort(q,q+n,cmp);
        int now=0;
        for(int i=0;i<n;i++)
        {
            now=max(now+1,q[i].x);
            ret[q[i].id]=now;
        }
        for(int i=0;i<n;i++)printf("%d ",ret[i]);puts("");
    }
}