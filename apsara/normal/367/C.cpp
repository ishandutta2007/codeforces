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
const int V=100100;
struct Node
{
    int x,y;
}q[V];
bool cmp(Node x,Node y)
{
    return x.y>y.y;
}
int n,m;
int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        for(int i=0;i<m;i++)
        scanf("%d%d",&q[i].x,&q[i].y);
        sort(q,q+m,cmp);
        LL ret=0;
        for(int i=0;i<m;i++)
        {
            LL nd=(LL)(i+1)*i/2;
            if(i%2==1)
            nd+=i/2;
            if(nd>=n)break;
            ret+=q[i].y;
        }
        cout<<ret<<endl;
    }
    return 0;
}