#include <iostream>
#include <algorithm>

using namespace std;

#define NMAX 1005
int a[NMAX][NMAX];
int stsus[NMAX][NMAX];
int stjos[NMAX][NMAX];
int drsus[NMAX][NMAX];
int drjos[NMAX][NMAX];

int main()
{
    int n,m,i,j;
    cin>>n>>m;

    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            cin>>a[i][j];

    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
        {
            stsus[i][j]=a[i][j];
            if(i>=2 && j>=2)
                stsus[i][j]+=max(stsus[i-1][j],stsus[i][j-1]);
            else if(i>=2)
                stsus[i][j]+=stsus[i-1][j];
            else if(j>=2)
                stsus[i][j]+=stsus[i][j-1];
        }

    for(i=n;i>=1;i--)
        for(j=1;j<=m;j++)
        {
            stjos[i][j]=a[i][j];
            if(i<n && j>=2)
                stjos[i][j]+=max(stjos[i+1][j],stjos[i][j-1]);
            else if(i<n)
                stjos[i][j]+=stjos[i+1][j];
            else if(j>=2)
                stjos[i][j]+=stjos[i][j-1];
        }

    ///////////////////////
    for(i=1;i<=n;i++)
        for(j=m;j>=1;j--)
        {
            drsus[i][j]=a[i][j];
            if(i>=2 && j<m)
                drsus[i][j]+=max(drsus[i-1][j],drsus[i][j+1]);
            else if(i>=2)
                drsus[i][j]+=drsus[i-1][j];
            else if(j<m)
                drsus[i][j]+=drsus[i][j+1];
        }

    for(i=n;i>=1;i--)
        for(j=m;j>=1;j--)
        {
            drjos[i][j]=a[i][j];
            if(i<n && j<m)
                drjos[i][j]+=max(drjos[i+1][j],drjos[i][j+1]);
            else if(i<n)
                drjos[i][j]+=drjos[i+1][j];
            else if(j<m)
                drjos[i][j]+=drjos[i][j+1];
        }

    int maxim=0;
    for(i=2;i<n;i++)
        for(j=2;j<m;j++)
        {
            int aux;

            aux=stsus[i-1][j]+drjos[i+1][j]+stjos[i][j-1]+drsus[i][j+1];
            if(aux>maxim)
                maxim=aux;

            aux=stsus[i][j-1]+drjos[i][j+1]+stjos[i+1][j]+drsus[i-1][j];
            if(aux>maxim)
                maxim=aux;
        }

    cout<<maxim<<'\n';
    return 0;
}