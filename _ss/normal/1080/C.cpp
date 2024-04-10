#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    //freopen("m.inp","r",stdin);
    //freopen("m.out","w",stdout);
    int t;
    long long n,m,x1,y1,x2,y2,x3,y3,x4,y4,t1,t2,t3,t4,x5,y5,x6,y6,t5;
    cin>>t;
    for (int i=1;i<=t;i++)
    {
        cin>>n>>m>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4;
        t2=(n*m)/2;
        t1=n*m-t2;
        if ((x2-x1+1)*(y2-y1+1)%2==1 && (x1+y1)%2==1) t4=((x2-x1+1)*(y2-y1+1))/2+1;
        else t4=((x2-x1+1)*(y2-y1+1))/2;
        t1=t1+t4;
        t2=t2-t4;
        if ((x4-x3+1)*(y4-y3+1)%2==1 && (x3+y3)%2==0) t3=((x4-x3+1)*(y4-y3+1))/2+1;
        else t3=((x4-x3+1)*(y4-y3+1))/2;
        t1=t1-t3;
        t2=t2+t3;
        x5=max(x1,x3);
        x6=min(x2,x4);
        y5=max(y1,y3);
        y6=min(y2,y4);
        if (x5<=x6 && y5<=y6)
        {
            if ((x6-x5+1)*(y6-y5+1)%2==1 && (x5+y5)%2==1) t5=((x6-x5+1)*(y6-y5+1))/2+1;
            else t5=((x6-x5+1)*(y6-y5+1))/2;
            t1=t1-t5;
            t2=t2+t5;
        }
        cout<<t1<<" "<<t2<<endl;
    }
    return 0;
}