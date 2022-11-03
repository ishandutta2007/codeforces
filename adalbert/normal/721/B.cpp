#include <bits/stdc++.h>
#include<queue>
using namespace std;
typedef long long  ll;
#define fir first
#define sec second
#define mp make_pair
#define pb push_back
#define _y1 dgkpothjoih
string st,s[10000];
int main()
{
    ll n,k;
    cin>>n>>k;
    for (int i=1;i<=n;i++)
        cin>>s[i];
    cin>>st;
    ll km=0;
    ll ko=0;
    for (int i=1;i<=n;i++)
    {
        if (s[i].size()<st.size()) km++; else
        if (s[i].size()==st.size()) ko++;
    }
    km++;
    cout<<km+(km-1)/k*5<<' ';
    km--;
    km+=ko;
    cout<<km+(km-1)/k*5;
}