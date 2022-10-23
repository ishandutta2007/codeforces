#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    string s;
    int a[1000],i;
    char c;
    cin>>s;
    for (i=0;i<s.length();i++) a[i]=0;
    i=s.length()-1;
    while (s[i]=='b') i--;
    while (i>=0)
    {
        c=s[i];
        a[i]=1;
        i--;
        while (i>=0 && s[i]==c) i--;
    }
    cout<<a[0];
    for (int i=1;i<s.length();i++) cout<<" "<<a[i];
    return 0;
}