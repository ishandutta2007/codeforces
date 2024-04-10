////////////////////////////////////////////////////////////////
////////////////// Sa1378 Platform Vesion 1.1 //////////////////
////////////////////////////////////////////////////////////////

#include <bits/stdc++.h>
using namespace std;

string s;
int main()
{
     cin>>s;
     int n=s.size();
     for(int i=0;i<=n/2;i++)
         if(s[i]!=s[n-i-1] || (s[i]!='A' && s[i]!='H' && s[i]!='I' && s[i]!='M' && s[i]!='O' && s[i]!='T' && s[i]!='U' && s[i]!='V' && s[i]!='W' && s[i]!='X' && s[i]!='Y'))
         {
             cout<<"NO"<<endl;
             return 0;
         }   
    cout<<"YES"<<endl;
    
    return 0;
}