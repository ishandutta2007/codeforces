#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    string s;
    int k;
    cin>>s>>k;
    int t1=0,t2=0,n=0;
    for (int i=0;i<s.length();i++)
        if (s[i]=='*') t1++;
        else if (s[i]=='?') t2++;
        else n++;
    if ((n<k && t1==0) || (n>k && t1+t2<n-k))
    {
        cout<<"Impossible";
        return 0;
    }
    if (n<k)
    {
        int i=0;
        while (s[i]!='*')
        {
            if (s[i]!='?') cout<<s[i];
            i++;
        }
        for (int j=1;j<=k-n;j++) cout<<s[i-1];
        for (int j=i+1;j<s.length();j++)
            if (s[j]!='?' && s[j]!='*') cout<<s[j];
    }
    else
    {
        int d=n-k;
        for (int i=0;i<s.length();i++)
            if ((s[i+1]=='?' || s[i+1]=='*') && d>0)
            {
                d--;
                i++;
            }
            else if (s[i]!='?' && s[i]!='*') cout<<s[i];
    }
    return 0;
}