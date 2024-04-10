#include"bits/stdc++.h"
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        while(k!=3)
        {
            k--;
            n--;
            printf("1 ");
        }
        if(n==3)cout<<"1 1 1"<<endl;
        else if(n==4)cout<<"2 1 1"<<endl;
        else
        {
            if(n%2)cout<<1<<" "<<n/2<<" "<<n/2<<endl;
            else if((n-2)/2%2==0)cout<<2<<" "<<(n-2)/2<<" "<<(n-2)/2<<endl;
            else cout<<n/2<<" "<<n/4<<" "<<n/4<<endl;
        }
    }
    return 0;
}