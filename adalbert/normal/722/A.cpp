
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

///------------------------------------------------------------///
int main()
{
    string st;
    ll n;
    cin>>n;
    cin>>st;
    if (n==12)
    {
        if (st[0]=='0' && st[1]=='0') st[1]='1';
        if (st[0]=='1' && st[1]>'2') st[1]='1';
        if (st[0]>='2' &&  st[1]>'0') st[0]='0';
        if (st[0]>='2' && st[1]=='0') st[0]='1';
        if (st[3]>'5') st[3]='1';
        cout<<st;
    }
    if (n==24)
    {
        if (st[0]>'2') st[0]='1';
        if (st[1]>'3' && st[0]=='2') st[1]='0';
        if (st[3]>'5') st[3]='1';
        cout<<st;
    }
}