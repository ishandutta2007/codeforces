#include"bits/stdc++.h"
using namespace std;
char s[1005];
int main()
{
    int t;
    cin>>t;
    //1 8 4 2 6 8
    if(t==0)cout<<1<<endl;
    else if(t%4==1)cout<<8<<endl;
    else if(t%4==2)cout<<4<<endl;
    else if(t%4==3)cout<<2<<endl;
    else if(t%4==0)cout<<6<<endl;
    return 0;
}