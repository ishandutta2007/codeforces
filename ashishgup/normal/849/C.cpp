#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

int32_t main()
{
    IOS;
    int k;
    cin>>k;
    if(k==0)
    {
        cout<<"a";
        return 0;
    }
    string s;
    char ch='a';
    while(k>0)
    {
        s+=ch;
        int ct=1;
        while(k>=ct)
        {
            s+=ch;
            k-=ct;
            ct++;
        }
        ch++;
    }
    cout<<s;
    return 0;
}