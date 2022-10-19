#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    string s;
    cin>>n;
    cin>>s;
    if(n==1)
    {
        if(s[0]=='1')
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
        return 0;
    }
    for(int i=0;i<n-1;++i)
    {
        if(s[i]=='1' && s[i+1]=='1')
        {
            cout<<"No"<<endl;
            return 0;
        }
    }
    for(int i=0;i<n;++i)
    {
        if(s[i]=='0' && (i-1<0 || s[i-1]=='0') && (i+1>=n || s[i+1]=='0'))
        {
            cout<<"No"<<endl;
            return 0;
        }
    }
    cout<<"Yes"<<endl;
    return 0;
}