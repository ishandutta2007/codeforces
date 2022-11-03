#include<bits/stdc++.h>
using namespace std;
#define y1 cgbngfgn
#define pb push_back
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define fir first
#define m_p make_pair
#define sec second
#define files(name) freopen(name".dat","r",stdin); freopen (name".sol","w",stdout);
#define left eorgjrptgj
#define right rtyjtokh
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const int md=1e9+7;
const int arr=7e5;

string st[2100],pref[2100],suf[2100];

string orr(string st1, string st2)
{
    string res="";

    for (int i=0;i<st1.size();i++)
        if (st1[i]=='1' || st2[i]=='1')
        res+='1'; else
        res+='0';
    return(res);
}

signed main()
{
    int n,m;
    cin>>n>>m;
    for (int i=1;i<=n;i++)
        cin>>st[i];

    pref[1]=st[1];
    for (int i=2;i<=n;i++)
        pref[i]=orr(pref[i-1],st[i]);

    suf[n]=st[n];
    for (int i=n-1;i>=1;i--)
        suf[i]=orr(st[i],suf[i+1]);

    for (int i=2;i<n;i++)
        if (orr(pref[i-1],suf[i+1])==suf[1])
        {
            cout<<"YES";
            return(0);
        }
    if (pref[n-1]==pref[n] || suf[2]==suf[1])
    {
        cout<<"YES";
        return(0);
    }

    cout<<"NO";

}