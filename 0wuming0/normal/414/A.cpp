#include"bits/stdc++.h"
using namespace std;
int now=1000000000;
int main()
{
    int n,k;
    cin>>n>>k;
    if(k<n/2)cout<<-1<<endl;
    else
    {
            if(n/2==0)
    {
        if(k==0)cout<<"62471046"<<endl;
        else cout<<"-1"<<endl;
    }
    else
    {
        for(int i=0;i<n/2-1;i++)
        {
            cout<<now<<" "<<now-1<<" ";now-=5;
        }
        if(n%2)cout<<k-n/2+1<<" "<<(k-n/2+1)*2<<" ";
        else cout<<k-n/2+1<<" "<<(k-n/2+1)*2<<endl;
        if(n%2)cout<<now-3<<endl;
    }
    }

    return 0;
}