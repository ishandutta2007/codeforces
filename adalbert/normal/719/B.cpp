#include <bits/stdc++.h>
#include<queue>
using namespace std;
typedef int ll;
#define fir first
#define sec second
#define mp make_pair
#define pb push_back
#define _y1 dgkpothjoih
///--------------------------------------------------------------------------------------------------------------///
ll n;
res1(string st)
{
    ll k1=0,k2=0;
    for (int i=0;i<st.size();i++)
        if (i%2==0 && st[i]=='b') k1++; else
        if (i%2==1 && st[i]=='r') k2++;
    return(max(k1,k2));
}
res2(string st)
{
    ll k1=0,k2=0;
    ll ans=0;
    for (int i=0;i<st.size();i++)
        if (i%2==1 && st[i]=='b') k1++; else
        if (i%2==0 && st[i]=='r') k2++;
    return(max(k1,k2));
}
///--------------------------------------------------------------------------------------------------------------///

int main()
{
    cin>>n;
    string st;
    cin>>st;
    cout<<min(res1(st),res2(st));
}