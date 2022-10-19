#include<bits/stdc++.h>
#define ll long long
using namespace std;
int a[51][51],op,n;
void change()
{
    for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)
        if((i+j)%2)a[i][j]^=1;
}
void ask(int aa,int b,int c,int d)
{
    cout<<'?'<<' '<<aa<<' '<<b<<' '<<c<<' '<<d<<endl;
    cin>>op;
    if(op)a[c][d]=a[aa][b];
    else a[c][d]=1^a[aa][b];
}
int main()
{
    cin>>n;
    a[1][1]=1;
    a[n][n]=0;
    ask(1,2,3,2);
    int t=a[3][2];
    ask(2,1,3,2);
    if(a[3][2]!=t)a[1][2]^=1;
    ask(1,1,2,2);
    for(int i=3;i<=n;i++)
        ask(i-2,1,i,1);
    for(int i=4;i<=n;i++)
        ask(i-2,2,i,2);
    for(int i=1;i<=n;i++)for(int j=3;j<=n;j++)
        ask(i,j-2,i,j);
    t=0;
    for(int i=3;i<=n;i++)
    {
        if(a[i-2][i-2]==1&&a[i][i]==0)
        {
            t=i-2;
            break;
        }
    }
    if(t)
    {
        int x1,x2,x3,x4;
        op=1;
        flag:
        if(a[t+1][t+1]==a[t][t+1]||a[t+1][t+1]==a[t+1][t])
        {
            if(a[t+1][t+2])op=0,x1=t,x2=t,x3=t+1,x4=t+2;
            if(a[t+2][t+1])op=0,x1=t,x2=t,x3=t+2,x4=t+1;
        }
        if(a[t+1][t+1]==a[t+2][t+1]||a[t+1][t+1]==a[t+1][t+2])
        {
            if(a[t+1][t]==0)op=0,x1=t+1,x2=t,x3=t+2,x4=t+2;
            if(a[t][t+1]==0)op=0,x1=t,x2=t+1,x3=t+2,x4=t+2;
        }
        if(op)
        {
            change();
            goto flag;
        }
        cout<<'?'<<' '<<x1<<' '<<x2<<' '<<x3<<' '<<x4<<endl;
        cin>>op;
        if(!op)change();
    }
    cout<<'!'<<endl;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
            cout<<a[i][j];
        cout<<endl;
    }
    return 0;
}