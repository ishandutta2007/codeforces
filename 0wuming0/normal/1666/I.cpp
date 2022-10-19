#include"bits/stdc++.h"
using namespace std;
int a[4][3];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        a[0][0]=1;a[0][1]=1;a[1][0]=1;a[1][1]=m;
        cout<<"SCAN "<<a[0][0]<<" "<<a[0][1]<<endl;
        cin>>a[0][2];
        cout<<"SCAN "<<a[1][0]<<" "<<a[1][1]<<endl;
        cin>>a[1][2];
        int x=(a[0][2]+a[1][2]-2*(m-1))/2;
        int y=a[0][2]-x;
        x=x/2+1;y=y/2+1;
        a[2][0]=x;a[2][1]=y;a[3][0]=x;a[3][1]=1;
        cout<<"SCAN "<<a[2][0]<<" "<<a[2][1]<<endl;
        cin>>a[2][2];
        cout<<"SCAN "<<a[3][0]<<" "<<a[3][1]<<endl;
        cin>>a[3][2];
        for(int x1=1;x1<=n;x1++)for(int x2=1;x2<=n;x2++)for(int y1=1;y1<=m;y1++)for(int y2=1;y2<=m;y2++)
        {
            if(x1>x2||x1==x2&&y1>=y2)continue;
            int i;
            for(i=0;i<4;i++)if(abs(x1-a[i][0])+abs(x2-a[i][0])+abs(y1-a[i][1])+abs(y2-a[i][1])!=a[i][2])break;
            if(i==4)
            {
                cout<<"DIG "<<x1<<" "<<y1<<endl;
                cin>>i;
                if(i==1)
                {
                    cout<<"DIG "<<x2<<" "<<y2<<endl;
                    cin>>i;
                    goto ne;
                }
            }
        }
        ne:;
    }
    return 0;
}