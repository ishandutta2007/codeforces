#include <bits/stdc++.h>
using namespace std;
const int N=2002;

int n,p;
char a[N];

int main()
{
    cin>>n>>p;
    cin>>a;
    bool z=false;
    for(int i=0;i<n-p;++i)
    {
        if(a[i]=='0')
        {
            if(a[i+p]=='1')
            {
                z=true;
                break;
            }
            if(a[i+p]=='.')
            {
                a[i+p]='1';
                z=true;
                break;
            }
        }
        else if(a[i]=='1')
        {
            if(a[i+p]=='0')
            {
                z=true;
                break;
            }
            if(a[i+p]=='.')
            {
                a[i+p]='0';
                z=true;
                break;
            }
        }
        else
        {
            if(a[i+p]=='1')
            {
                a[i]='0';
                z=true;
                break;
            }
            else if(a[i+p]=='0')
            {
                a[i]='1';
                z=true;
                break;
            }
            else
            {
                a[i]='1';
                a[i+p]='0';
                z=true;
                break;
            }
        }
    }
    if(!z)
    {
        cout<<"No"<<endl;
        return 0;
    }
    for(int i=0;i<n;++i)
        if(a[i]=='.')
            a[i]='0';
    cout<<a<<endl;
    return 0;
}