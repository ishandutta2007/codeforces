#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
typedef double ld;
#define ll unsigned long long
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define files(name) freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
#define fir first
#define sec second
#define m_p make_pair
#define pb push_back

///--------------------------------------------------------------------------------------------------------------///
int main()
{
    ll n;
    ll k1=0,k2=0;
    cin>>n;
    string st;
    cin>>st;
    for (int i=0;i<st.size();i++)
        if (st[i]=='A') k1++; else k2++;
    if (k1>k2) cout<<"Anton"; else
        if (k1<k2) cout<<"Danik"; else cout<<"Friendship";
}