#include <bits/stdc++.h>
using namespace std;
string s;
int main()
{ 
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]!='1')
        {
            cout<<"NO";
            return 0;
        }
        if(s[i+1]=='4' && s[i+2]=='4')
            i+=2;
        else if(s[i+1]=='4')
            i++;
    }
    cout<<"YES";
    return 0;
}