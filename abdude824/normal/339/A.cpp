#include<bits/stdc++.h>
using namespace std;
int32_t main()
{
    string s;cin>>s;
    vector<char>a;
    int n=s.size();
    if(n==1)
    {
        cout<<s<<endl;
    }
    else{
    for(int i=0;i<n;i++)
    {
        if(s[i]=='+')
            continue;
        else{
            a.push_back(s[i]);
        }
    }
    sort(a.begin(),a.end());
    for(int i=0;i<a.size()-2;i+=2)
        cout<<a[i]<<"+"<<a[i+1]<<"+";
    if(a.size()%2==0)
    {
        cout<<a[a.size()-2]<<"+"<<a[a.size()-1];
    }
    else{
        cout<<a[a.size()-1];
    }
    cout<<endl;}
}