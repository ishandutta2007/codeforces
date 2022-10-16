#include <iostream>

using namespace std;

bool calif[2][100005];

int e1[100005];
int e2[100005];

int main()
{
    int n,i,k;
    cin>>n;
    for(i=0;i<n;i++)
        cin>>e1[i]>>e2[i];

    for(k=0;(2*k)<(n-1);k++)
    {
        calif[0][k]=1;
        calif[1][k]=1;
    }

    int j,poz;
    i=0,j=0,poz=0;
    while(i<n && j<n && poz<n)
        if(e1[i]<e2[j])
        {
            poz++;
            calif[0][i]=1;
            i++;
        }
        else
        {
            poz++;
            calif[1][j]=1;
            j++;
        }

    for(i=0;i<2;i++)
    {
        for(j=0;j<n;j++)
            cout<<calif[i][j];
        cout<<'\n';
    }


    return 0;
}