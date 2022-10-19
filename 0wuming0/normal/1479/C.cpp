#include"bits/stdc++.h"
using namespace std;
int a[1205],b[1205],c[1205],nn;
void add(int x,int y,int z)
{
    a[nn]=min(x,y);
    b[nn]=max(x,y);
    c[nn]=z;
    nn++;
}
int n=28;
int use=2;
int m[35][35];
int solve(int l)
{
    //28
    //1-27
    //27-x
    for(int i=27;i>=1;i--)
    {
        int x=(1<<(27-i));
        if(l+1>=2*x)
        {
            for(int j=i+1;j<=28;j++)
            {
                m[i][j]=m[j][i]=x;
            }
        }
        else
        {
            l-=x;
            if(l<0)return i;
            m[i][28]=m[28][i]=x;
            int now=0;
            for(int j=0;j<28;j++)if((1<<j)&l)
            {
                m[i][27-j]=m[27-j][i]=x-(1<<j)+1+now;
                now+=(1<<j);
            }
            return i;
        }
    }
}
int main()
{
    int l,r;
    cin>>l>>r;
    cout<<"YES"<<endl;
    int t;
    if(l==r)
    {
        add(1,28,l);
        goto en;
    }
    if(l==1)
    {
        l++;
        add(1,28,1);
    }
    t=solve(r-l+1);
    for(int i=2;i<28;i++)add(1,i,l-1);

    //add(1,t+1,l-1);
    for(int i=0;i<33;i++)for(int j=i+1;j<33;j++)
    {
        if(m[i][j])add(i,j,m[i][j]);
    }
    en:;
    cout<<28<<" "<<nn<<endl;
    for(int i=0;i<nn;i++)
    {
        printf("%d %d %d\n",a[i],b[i],c[i]);
    }
    return 0;
}
/*
7
2 2 1 2 2 2 2
*/