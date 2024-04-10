#include <bits/stdc++.h>
using namespace std;
const int N=105;

int n;
int a[N];

bool stg()
{
    double x=0;
    for(int i=0;i<n;++i)
    {
        x+=a[i];
    }
    double y=x/n;
    y+=0.5;
    int h=y;
    if(h==5)
        return true;
    return false;
}

int main()
{
    cin>>n;
    for(int i=0;i<n;++i)
        cin>>a[i];
    sort(a,a+n);
    if(stg())
    {
        cout<<0<<endl;
        return 0;
    }
    for(int i=0;i<n;++i)
    {
        a[i]=5;
        if(stg())
        {
            cout<<i+1<<endl;
            return 0;
        }
    }
    return 0;
}