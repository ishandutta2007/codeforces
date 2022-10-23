#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    string s,t;
    cin>>s>>t;
    bool kt=true,kt2,kt3;
    char ch[6];
    ch[1]='a';
    ch[2]='e';
    ch[3]='i';
    ch[4]='o';
    ch[5]='u';
    if (s.length()!=t.length()) kt=false;
    else
    {
    for (int i=0;i<s.length();i++)
    {
        kt2=false;
        kt3=false;
        for (int j=1;j<=5;j++)
        {
            if (s[i]==ch[j]) kt2=true;
            if (t[i]==ch[j]) kt3=true;
        }
        if (kt2!=kt3) kt=false;
    }
    }
    if (kt) cout<<"Yes"; else cout<<"No";
    return 0;
}