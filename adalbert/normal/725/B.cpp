#include <bits/stdc++.h>
using namespace std;
///----------------------defines-----------------------///
#define push_back pb
#define make_pair mp
typedef unsigned long long ll;
typedef long double ld;
///--------------------end_of _define------------------///
ll perev(string st)
{
    ll ans=0;
    for (int i=0;i<st.size()-1;i++)
    {
        ans*=10;
        ans+=st[i]-48;
    }
    return(ans);
}
int main()
{
    string st;
    cin>>st;
    ll n=perev (st);
    char ch=st[st.size()-1];
    ll k=n/4;
ll ans=0;
    if (n%4==0) ans=n/2; else
        if (n%4==1) ans=(n+1)/2; else
        if (n%4==2) ans=(n+2)/2; else
        if (n%4==3) ans=n/2;
    ans=6*(ans-1)+((ans-1)/2)*3+ans/2;
    if (ch=='f') ans+=1; else
        if (ch=='e') ans+=2; else
        if (ch=='d') ans+=3; else
        if (ch=='a') ans+=4; else
        if (ch=='b') ans+=5; else
        if (ch=='c') ans+=6;
    cout<<ans;
}