#include <iostream>
#include <cmath>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <stdio.h>
using namespace std;
int n;
vector<int>vt,g;
int kt[int(1e6)+1];
int gcd(int a,int b)
{
    int r=a%b;
    while (b>0)
    {
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}
int main()
{
    srand(time(NULL));
    cin>>n;
    int l=1,r=int(1e9),m=0,t,d=0;
    long long mid;
    while (l<=r)
    {
        d++;
        mid=(l+r)/2;
        cout<<"> "<<mid<<endl;
        fflush(stdout);
        cin>>t;
        if (t==1)
        {
            m=mid;
            l=mid+1;
        }
        else r=mid-1;
    }
    for (int i=d;i<min(60,n+d);i++)
    {
        mid=(abs(rand()*rand()))%n+1;
        while (kt[mid]==1) mid=(abs(rand()*rand()))%n+1;
        kt[mid]=1;
        cout<<"? "<<mid<<endl;
        fflush(stdout);
        cin>>t;
        vt.push_back(t);
    }
    int kq=abs(vt[1]-vt[0]);
    for (int i=0;i<vt.size();i++)
        for (int j=i+1;j<vt.size();j++) g.push_back(abs(vt[j]-vt[i]));
    for (int i=0;i<g.size();i++) kq=gcd(kq,g[i]);
    cout<<"! "<<m+1-kq*(n-1)<<" "<<kq<<endl;
    return 0;
}