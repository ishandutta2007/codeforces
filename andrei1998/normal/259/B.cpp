#include <iostream>

using namespace std;

int v[3][3];
bool ok()
{
    int s1=v[0][0]+v[1][1]+v[2][2];
    int s2=v[0][0]+v[0][1]+v[0][2];
    int s3=v[2][0]+v[1][1]+v[0][2];

    return ((s1==s2) && (s2==s3));
}

int main()
{
    int i,j;

    for(i=0;i<3;i++)
        for(j=0;j<3;j++)
            cin>>v[i][j];

    for(i=0;i<=100000;i++)
    {
        v[0][0]=i;
        int s=v[0][0]+v[0][1]+v[0][2];

        v[1][1]=s-v[0][1]-v[2][1];
        v[2][2]=s-v[0][2]-v[1][2];

        if(ok())
            break;
    }

    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
            cout<<v[i][j]<<' ';
        cout<<endl;
    }

    return 0;
}