#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
const ll maxn=1e5+1;

ll a[maxn],n=0,dd1[12],dd2[12],tp1[12],tp2[12];
int main()
{
    //freopen("ss.inp","r",stdin);
    //freopen("ss.out","w",stdout);
    char ch=getchar();
    while (ch!=-1 && ch!='\n')
    {
        n++;
        a[n]=int(ch)-48;
        ch=getchar();
    }
    ll kq=0;
    for (int i=1;i<=n;i++)
    {
        for (int j=a[i]+1;j<=10;j++)
        {
            tp1[((j*(j-1))/2+a[i]+10)%11]+=dd2[j];
            tp2[((j*(j-1))/2+a[i]+10)%11]+=dd1[j];
            kq+=dd1[j]+dd2[j];
        }
        for (int j=0;j<=10;j++)
        {
            dd1[j]=tp1[j];
            dd2[j]=tp2[j];
            tp1[j]=0;
            tp2[j]=0;
            //kq+=dd1[j]+dd2[j];
        }
        //tp1[0]=tp2[0]=0;
        if (a[i]>0) dd1[a[i]]++,kq++;
        //cout<<kq<<endl;
    }
    cout<<kq;
    /*cout<<endl;
    for (int i=0;i<=10;i++) cout<<dd1[i]<<" ";
    cout<<endl;
    for (int i=0;i<=10;i++) cout<<dd2[i]<<" ";*/
    return 0;
}