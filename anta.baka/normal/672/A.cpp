#include <bits/stdc++.h>
using namespace std;

string ts(int n)
{
    string res;
    while(n)
    {
        res+='0'+n%10;
        n/=10;
    }
    reverse(res.begin(),res.end());
    return res;
}

int main()
{
    int n;
    cin>>n;
    string s;
    for(int i=1; i<1000; i++) s+=ts(i);
    cout<<s[n-1];
    return 0;
}