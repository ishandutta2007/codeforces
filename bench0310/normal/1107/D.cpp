#include <bits/stdc++.h>

using namespace std;

int gcd(int a,int b)
{
    if(!b) return a;
    return gcd(b,a%b);
}

string hex(char c)
{
    if(c>='A') c-='A'-10;
    else c-='0';
    string s;
    int n=c;
    while(n)
    {
        s+=(n&1)?'1':'0';
        n/=2;
    }
    while(s.size()<4) s+='0';
    reverse(s.begin(),s.end());
    return s;
}

int main()
{
    ios::sync_with_stdio(false);
    //cin.tie(NULL); cout.tie(NULL);
    int n;
    cin >> n;
    string s[n];
    for(int o=0;o<n;o++)
    {
        string temp;
        cin >> temp;
        for(int i=0;i<n/4;i++) s[o]+=hex(temp[i]);
    }
    int x=n;
    for(int o=0;o<n;o++)
    {
        int prev=0;
        for(int i=1;i<n;i++)
        {
            if(s[o][i]!=s[o][i-1])
            {
                x=gcd(x,i-prev);
                prev=i;
            }
        }
        x=gcd(x,n-prev);
    }
    for(int o=0;o<n;o++)
    {
        int prev=0;
        for(int i=1;i<n;i++)
        {
            if(s[i][o]!=s[i-1][o])
            {
                x=gcd(x,i-prev);
                prev=i;
            }
        }
        x=gcd(x,n-prev);
    }
    cout << x << endl;
    return 0;
}