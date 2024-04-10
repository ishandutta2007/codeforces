#include <iostream>
#include <fstream>
using namespace std;
int a[10],b[10];
int main()
{
    int n,x,t1=0,t2=0,t3=0;
    cin>>n;
    char c;
    for (int i=1;i<=n;i++)
    {
        c=getchar();
        c=getchar();
        cin>>x;
        if (c=='&')
        for (int i=0;i<10;i++)
        {
            if (x%2==0)
            {
                b[i]=1;
                a[i]=0;
            }
            x=x/2;
        }
        else if (c=='|')
        for (int i=0;i<10;i++)
        {
            if (x%2==1)
            {
                b[i]=1;
                a[i]=1;
            }
            x=x/2;
        }
        else
        for (int i=0;i<10;i++)
        {
            if (x%2==1) a[i]=(a[i]+1)%2;
            x=x/2;
        }
    }
    int k=1;
    for (int i=0;i<10;i++)
        {
            if (b[i]!=1 || a[i]!=0) t1=t1+k;
            if (b[i]==1 && a[i]==1) t2=t2+k;
            if (b[i]==0 && a[i]==1) t3=t3+k;
            k=k*2;
        }
    cout<<3<<endl<<"& "<<t1<<endl<<"| "<<t2<<endl<<"^ "<<t3;
    return 0;
}