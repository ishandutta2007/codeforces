#include <iostream>
using namespace std;
const int N=102;

int n,m;
int a[N][4];
int main()
{
    cin>>n>>m;
    int i=0,j=0;
    for(int k=1;k<=m;++k)
    {
        a[i][j]=k;
        if(j==0)
        {
            j=3;
        }
        else if(j==3)
        {
            if(i+1<n)
            {
                i++;
                j=0;
            }
            else
            {
                i=0;
                j=1;
            }
        }
        else if(j==1)
        {
            j=2;
        }
        else if(j==2)
        {
            ++i;
            j=1;
        }
    }
    for(int i=0;i<n;++i)
    {
        if(a[i][1])
            cout<<a[i][1]<<' ';
        if(a[i][0])
            cout<<a[i][0]<<' ';
        if(a[i][2])
            cout<<a[i][2]<<' ';
        if(a[i][3])
            cout<<a[i][3]<<' ';
    }
    cout<<endl;
    return 0;
}