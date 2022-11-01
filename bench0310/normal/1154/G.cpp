#include <bits/stdc++.h>

using namespace std;
const int N=10000005;

int p[N][2];
int id[N];

int main()
{
    int n;
    scanf("%d",&n);
    vector<int> v(n+1);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&v[i]);
        if(id[v[i]]<2) p[v[i]][id[v[i]]++]=i;
    }
    int a,b;
    long long res=1000000000000000;
    for(int o=1;o<N;o++)
    {
        int c=0,d=0;
        for(int i=o;i<N;i+=o)
        {
            for(int j=0;j<2;j++)
            {
                if(p[i][j])
                {
                    if(c==0) c=p[i][j];
                    else if(d==0) d=p[i][j];
                }
            }
            if(d) break;
        }
        if(d==0) continue;
        long long lcm=(long long)v[c]*v[d]/(long long)o;
        if(lcm<res)
        {
            res=lcm;
            a=c;
            b=d;
        }
    }
    if(a>b) swap(a,b);
    printf("%d %d\n",a,b);
    return 0;
}