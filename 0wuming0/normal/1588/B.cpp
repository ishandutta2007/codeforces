#include"bits/stdc++.h"
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int l=1,r=n;
        while(l+1!=r)
        {
            int x=l+r>>1;//cout<<"???"<<l<<" "<<r<<" "<<x<<endl;
            cout<<"? 1 "<<x<<endl;
            long long k;
            cin>>k;
            if(k)r=x;
            else l=x;
        }
        cout<<"? 1 "<<n<<endl;
        long long sum=0;
        long long d=0;
        cin>>sum;
        cout<<"? "<<l+1<<" "<<n<<endl;
        cin>>d;
        int m=l+sum-d;
        m++;
        cout<<"? "<<m<<" "<<n<<endl;
        cin>>sum;
        cout<<"? "<<m+1<<" "<<n<<endl;
        cin>>d;
        r=m+sum-d;
        cout<<"! "<<l<<" "<<m<<" "<<r<<endl;
    }
    return 0;
}