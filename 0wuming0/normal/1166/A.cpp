#include"bits/stdc++.h"
using namespace std;
int main()
{
    int n;
    cin>>n;
    int num[505]={0};
    while(n--)
    {
        string s;
        cin>>s;
        num[s[0]]++;
    }
    int ans=0;
    for(int i='a';i<='z';i++)
    {
        int a,b;
        a=num[i]/2;
        b=num[i]-a;
        ans+=a*(a-1)/2+b*(b-1)/2;
    }
    cout<<ans<<endl;
    return 0;
}