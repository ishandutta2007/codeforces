#include"bits/stdc++.h"
using namespace std;
int que(int l,int r)
{
    cout<<"? "<<l<<" "<<r<<endl;
    int w;
    cin>>w;
    return w;
}
int main()
{
    int n;
    cin>>n;
    int m=que(1,n);
    int x1=1,x2=m,x;
    if(m!=1&&que(1,m)==m)
    {
        x1=1;
        x2=m;
        while(x1+1!=x2)
        {
            x=(x1+x2)/2;
            if(que(x,m)==m)x1=x;
            else x2=x;
        }
        cout<<"! "<<x1<<endl;
    }
    else
    {
        x1=m;
        x2=n;
        while(x1+1!=x2)
        {
            x=(x1+x2+1)/2;
            if(que(m,x)==m)x2=x;
            else x1=x;
        }
        cout<<"! "<<x2<<endl;
    }

    return 0;
}