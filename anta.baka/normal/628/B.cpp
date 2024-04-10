#include <bits/stdc++.h>
using namespace std;

int s[300000];

int main()
{
    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    int n=0;
    char ch;
    long long ans=0;
    while(cin>>ch) {
        n++;
        s[n-1]=ch-'0';
        ans+=(s[n-1]%4==0);
    }

    for(int i=1; i<n; i++)
        if((s[i-1]*10+s[i])%4==0)
            ans+=i;

    cout<<ans;
    return 0;
}