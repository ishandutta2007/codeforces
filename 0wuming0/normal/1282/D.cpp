#include"bits/stdc++.h"
using namespace std;
char s[305];
int now;
int main()
{
    int t;
    cout<<"a"<<endl;
    cin>>t;
    for(int i=0;i<t;i++)s[i]='b';
    cout<<s<<endl;
    cin>>now;
    if(now==0)return 0;
    s[t]='b';
    int n=t+1;
    for(int i=0;i<n;i++)
    {
        s[i]='a';
        cout<<s<<endl;
        cin>>t;
        if(t>=now)
        {
            s[i]='b';
        }
        else
        {
            now=t;
            if(now==0)return 0;
        }
    }
    return 0;
}