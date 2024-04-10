#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin>>s;
    unsigned long long n=10000*(s[0]-'0')+1000*(s[2]-'0')+100*(s[4]-'0')+10*(s[3]-'0')+(s[1]-'0');
    unsigned long long ans=1;
    for(int i=0; i<5; i++)
        ans=(ans*n)%1000000000000;
    string m;
    for(int i=0; i<5; i++) {
        m+=ans%10+'0';
        ans/=10;
    }
    cout<<m[4]<<m[3]<<m[2]<<m[1]<<m[0];
    return 0;
}