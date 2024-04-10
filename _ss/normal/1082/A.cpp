#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    long long t,n,x,y,d,t1,t2;
    cin>>t;
    for (int i=1;i<=t;i++)
    {
        cin>>n>>x>>y>>d;
        if (int(abs(x-y))%d==0) cout<<abs(x-y)/d<<endl;
        else
        {
            if (int(abs(y-1))%d==0) t1=abs(y-1)/d+abs(x-1)/d; else t1=2000000000;
            if (int(abs(x-1))%d>0) t1++;
            if (int(abs(y-n))%d==0) t2=abs(y-n)/d+abs(x-n)/d; else t2=2000000000;
            if (int(abs(x-n))%d>0) t2++;
            if (t2<t1) t1=t2;
            if (t1>=2000000000) cout<<-1<<endl; else cout<<t1<<endl;
        }
    }
    return 0;
}