#include <iostream>

using namespace std;

int main()
{
    int n,d=0;
    string s;
    cin>>n>>s;
    for (int i=1;i<n-1;i++)
        if (s[i]==s[i-1] && s[i]==s[i+1])
        {
            if (s[i]=='R' || s[i]=='G') s[i]='B'; else s[i]='R';
            d++;
        }
    for (int i=1;i<n-1;i++)
        if (s[i]==s[i-1] || s[i]==s[i+1])
    {
        d++;
        if (s[i-1]=='R')
        {
            if (s[i+1]=='G') s[i]='B'; else s[i]='G';
        }
        else if (s[i-1]=='G')
        {
            if (s[i+1]=='R') s[i]='B'; else s[i]='R';
        }
        else
        {
            if (s[i+1]=='R') s[i]='G'; else s[i]='R';
        }
    }
    if (s[0]==s[1])
    {
        d++;
        if (s[0]!='R') s[1]='R'; else s[1]='G';
    }
    cout<<d<<endl;
    for (int i=0;i<n;i++) cout<<s[i];
    return 0;
}