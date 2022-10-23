#include <iostream>
#include <cmath>
#include <iomanip>
#include <fstream>
using namespace std;

int main()
{
    int t;
    double l,r,d,mid;
    cin>>t;
    for (int i=1;i<=t;i++)
    {
        cin>>d;
        if (d-d*d/4>0.000000001) cout<<"N"<<endl; else
        {
            l=0;
            r=d/2;
            mid=(l+r)/2;
            while (abs(d-mid*(d-mid))>0.000000001)
                {
                    if (mid*(d-mid)>d) r=mid; else
                    if (mid*(d-mid)<d) l=mid;
                    mid=(l+r)/2;
                }
            cout<<"Y"<<" ";
            printf("%0.9f",d-mid);
            cout<<" ";
            printf("%0.9f",mid);
            cout<<endl;
        }
    }
    return 0;
}