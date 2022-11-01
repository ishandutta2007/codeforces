#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    string s;
    cin>>s;
    int n = s.length();
    char a[]={'a','b','c'};
    for(int i=n-1; i>1; i--)
        if(s[i]==s[i-1])
            for(int j=0; j<3; j++)
                if(s[i-2]!=a[j] && s[i]!=a[j])
                    s[i-1]=a[j];
    if(n>1 && s[1]==s[0])
        s[0]=(s[1]=='z'?'a':'z');
    cout<<s;
    return 0;
}