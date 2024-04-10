#include <bits/stdc++.h>
#include<queue>
using namespace std;
typedef long long  ll;
#define fir first
#define sec second
#define mp make_pair
#define pb push_back
#define _y1 dgkpothjoih
vector <ll> vec;
string st;
int main()
{
    ll n;
    cin>>n;
    cin>>st;
    st+='W';
    ll tep=0;
    reverse(st.begin(),st.end());
    st+='W';
    reverse(st.begin(),st.end());
    //cout<<st<<'\n';
    for (int i=1;i<=n+1;i++)
        if (st[i]=='B') tep++;
        else if (st[i]=='W' && st[i-1]=='B')
            {
                vec.pb(tep);
                tep=0;
            }
    cout<<vec.size()<<'\n';
    for (int i=0;i<vec.size();i++)
        cout<<vec[i]<<' ';

}