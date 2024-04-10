#include"bits/stdc++.h"
using namespace std;
int main()
{
    int n;cin>>n;
    while(n--)
    {
        int x,y;
        cin>>x>>y;
        if(x<y)swap(x,y);
        if(x==2&&y==2||y==1)cout<<"yes"<<endl;else cout<<"No"<<endl;
    }
    return 0;
}