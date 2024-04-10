#include"bits/stdc++.h"
using namespace std;
int check(int a,int b,int c,int d,int &p,int &q,int &l)
{
    if(a<0||b<0||c<0||d<0)return 0;
    p=a;
    b-=a;
    if(b<0)return 0;
    q=b;
    c-=b;
    if(c<0)return 0;
    l=c;
    d-=c;
    if(d)return 0;
    return 1;
}
int ans[100005],nn;
int main()
{
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    for(int i=1;i<=4;i++)for(int j=i;j<=4;j++)
    {
        int a0=a,b0=b,c0=c,d0=d;
        if(i<=1&&1<=j)a0--;
        if(i<=2&&2<=j)b0--;
        if(i<=3&&3<=j)c0--;
        if(i<=4&&4<=j)d0--;
        int p,q,l;
        if(check(a0,b0,c0,d0,p,q,l))
        {
            if(p>0&&max(1,i)>min(2,j))continue;
            if(q>0&&max(2,i)>min(3,j))continue;
            if(l>0&&max(3,i)>min(4,j))continue;
            cout<<"YES"<<endl;
            for(int k=i;k<=j;k++)
            {
                ans[nn++]=k;
                if(k==1)
                {
                    while(p--)
                    {
                        ans[nn++]=2;
                        ans[nn++]=1;
                    }
                    p++;
                }
                if(k==2)
                {
                    while(p--)
                    {
                        ans[nn++]=1;
                        ans[nn++]=2;
                    }
                    p++;
                    while(q--)
                    {
                        ans[nn++]=3;
                        ans[nn++]=2;
                    }
                    q++;
                }
                if(k==3)
                {
                    while(q--)
                    {
                        ans[nn++]=2;
                        ans[nn++]=3;
                    }
                    q++;
                    while(l--)
                    {
                        ans[nn++]=4;
                        ans[nn++]=3;
                    }
                    l++;
                }
                if(k==4)
                {
                    while(l--)
                    {
                        ans[nn++]=3;
                        ans[nn++]=4;
                    }
                    l++;
                }
            }
            for(int i=0;i<nn;i++)printf("%d%c",ans[i]-1," \n"[i==nn-1]);
            return 0;
        }
    }
    cout<<"NO"<<endl;
    return 0;
}
/*
*/