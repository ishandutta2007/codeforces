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
const int V=150100;
const LL ooo=1000000000;
const LL oo=ooo*ooo;
LL val[V],tr[V];
int AB(int x){if(x<0)return -x;return x;}
int N;
void update(int k, LL v)
{
    while(k<=N)
    {
        tr[k]=max(tr[k],v);
        k+=k&-k;
    }
}
LL read(int k)
{
    LL ret=-oo;
    while(k)
    {
        ret=max(ret,tr[k]);
        k-=k&-k;
    }
    return ret;
}
int n,m,d,a,b,t;
int main()
{
    while(~scanf("%d%d%d",&n,&m,&d))
    {
        memset(val,0,sizeof(val));
        memset(tr,0,sizeof(tr));
        int tm=1;
        N=n;
        while(m--)
        {
            scanf("%d%d%d",&a,&b,&t);
            LL ds=(LL)d*(t-tm);
            int p=n;
            for(int i=n;i>0;i--)
            tr[i]=-oo;
            for(int i=n;i>0;i--)
            {
                int l=max(1LL,i-ds);
                int r=min((LL)n,i+ds);
                while(p>=l)
                {
                    update(p,val[p]);
                    p--;
                }
                val[i]=read(r)+b-AB(a-i);
            }
            tm=t;
        }
        LL ret=-oo;
        for(int i=1;i<=n;i++)ret=max(ret,val[i]);
        cout<<ret<<endl;
    }
    return 0;
}