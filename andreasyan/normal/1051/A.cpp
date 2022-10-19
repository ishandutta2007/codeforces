#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
const int N=102;
const char t[3]={'1','A','a'};

int n;
char a[N];
bool stg()
{
    bool z1=false,z2=false,z3=false;
    for(int i=0;i<n;++i)
    {
        if('a'<=a[i] && a[i]<='z')
            z1=true;
        else if('A'<=a[i] && a[i]<='Z')
            z2=true;
        else
            z3=true;
    }
    return (z1 && z2 && z3);
}
void solv()
{
    cin>>a;
    n=strlen(a);
    if(stg())
        return;
    for(int i=0;i<n;++i)
    {
        char x=a[i];
        for(int j=0;j<3;++j)
        {
            a[i]=t[j];
            if(stg())
                return;
        }
        a[i]=x;
    }
    for(int i=0;i<n-1;++i)
    {
        char x=a[i],y=a[i+1];
        for(int j=0;j<3;++j)
        {
            for(int j1=0;j1<3;++j1)
            {
                a[i]=t[j];
                a[i+1]=t[j1];
                if(stg())
                    return;
            }
        }
        a[i]=x;
        a[i+1]=y;
    }
    for(int i=0;i<n-2;++i)
    {
        char x=a[i],y=a[i+1],z=a[i+2];
        for(int j=0;j<3;++j)
        {
            for(int j1=0;j1<3;++j1)
            {
                for(int j2=0;j2<3;++j2)
                {
                    a[i]=x;
                    a[i+1]=y;
                    a[i+2]=z;
                    if(stg())
                        return;
                }
            }
        }
        a[i]=x;
        a[i+1]=y;
        a[i+2]=z;
    }
}

int main()
{
    //freopen("input.txt","r",stdin);
    int tt;
    cin>>tt;
    while(tt--)
    {
        solv();
        cout<<a<<endl;
    }
    return 0;
}