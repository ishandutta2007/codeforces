#include"bits/stdc++.h"
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a=0,b=0;
    int k;
    for(int i=0;i<n;i++)\
    {
        cin>>k;
        if(k==5)b++;
        else a++;
    }
    if(a==0)
    {
        cout<<-1<<endl;
        return 0;
    }
    if(b<9)
    {
        cout<<0<<endl;
        return 0;
    }
    for(int i=0;i<b/9;i++)
    {
        cout<<"555555555";
    }
    for(int i=0;i<a;i++)cout<<0;cout<<endl;
    return 0;
}