#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

int a[5];

int32_t main()
{
    IOS;
    int idx=1;
    char ch;
    while(cin>>ch)
    {   
        a[idx]++;
        while(cin>>ch && ch=='|')
        {
            a[idx]++;
        }
        idx++;
    }    
    if(a[1]+a[2]!=a[3])
    {
        if(abs(a[3]-(a[1]+a[2]))==2)
        {
            if(a[3]>a[1]+a[2])
            {
                a[3]--;
                a[1]++;
            }
            else
            {
                a[3]++;
                if(a[1]>1)
                    a[1]--;
                else
                    a[2]--;
            }
        }
        else
        {
            cout<<"Impossible";
            return 0;
        }
    }
    for(int i=1;i<=a[1];i++)
        cout<<"|";
    cout<<"+";
    for(int i=1;i<=a[2];i++)
        cout<<"|";
    cout<<"=";
    for(int i=1;i<=a[3];i++)
        cout<<"|";
    return 0;
}