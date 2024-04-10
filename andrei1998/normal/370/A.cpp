#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
    int r1,c1,r2,c2,l1,l2;
    cin>>r1>>c1>>r2>>c2;
    l1=r1,l2=r2;
    if(r1==r2 || c1==c2)
        cout<<"1 ";
    else
        cout<<"2 ";

    int cul1,cul2;

    cul1=((c1-1)%2)==((l1-1)%2);
    cul2=((c2-1)%2)==((l2-1)%2);
    if(cul1!=cul2)
        cout<<"0 ";
    else
    {
        int dp1=l1-c1,dp2=l2-c2;
        int ds1=l1+c1,ds2=l2+c2;

        if(dp1==dp2 || ds1==ds2)
            cout<<"1 ";
        else
            cout<<"2 ";
    }

    r1=abs(r2-r1)+1;
    c1=abs(c2-c1)+1;

    if(r1>c1)
        swap(r1,c1);
    cout<<c1-1<<'\n';

    return 0;
}