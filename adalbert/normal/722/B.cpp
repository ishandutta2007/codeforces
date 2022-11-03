
#include <bits/stdc++.h>
#include<queue>
using namespace std;
typedef long long  ll;
#define fir first
#define sec second
#define mp make_pair
#define pb push_back
#define _y1 dgkpothjoih
///------------------------------------------------------------///
string st[1000];
ll p[1000];
///------------------------------------------------------------///
int main()
{
    ll n;
    cin>>n;
    for (int i=1;i<=n;i++) cin>>p[i];
    n++;
    for (int i=1;i<=n;i++) getline(cin,st[i]);
    for (int i=2;i<=n;i++)
    {
        ll k=0;
        for (int j=0;j<=st[i].size();j++)
            if (st[i][j]=='a' ||st[i][j]=='e' ||st[i][j]=='o' ||st[i][j]=='y' ||st[i][j]=='i' ||st[i][j]=='u' ) k++;
        if (k!=p[i-1])
        {
            cout<<"NO";
            return(0);
        }
    }
    cout<<"YES";
}