#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
const int N=1003;

int n,m;
char a[N][N],b[N][N];

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;++i)
        cin>>a[i];
    for(int i=0;i<n;i++)
        for(int j=0;j<m;++j)
            b[i][j]='.';
    for(int i=0;i<=n-3;++i)
    {
        for(int j=0;j<=m-3;++j)
        {
            bool z=true;
            for(int ii=0;ii<3;++ii)
            {
                for(int jj=0;jj<3;++jj)
                {
                    char t='#';
                    if(ii==1 && jj==1)
                    {
                        t='.';
                    }
                    if(t=='#' && a[i+ii][j+jj]=='.')
                    {
                        z=false;
                        break;
                    }
                }
            }
            if(z)
            {
                for(int ii=0;ii<3;++ii)
                {
                    for(int jj=0;jj<3;++jj)
                    {
                        char t='#';
                        if(ii==1 && jj==1)
                        {
                            t='.';
                        }
                        if(t=='#')
                            b[i+ii][j+jj]=t;
                    }
                }
            }
        }
    }
    bool z=true;
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
        {
            if(a[i][j]!=b[i][j])
            {
                z=false;
                break;
            }
        }
    }
    if(z==true)
    {
        cout<<"YES"<<endl;
    }
    else
    {
        cout<<"NO"<<endl;
    }
    return 0;
}