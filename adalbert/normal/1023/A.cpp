#include<bits/stdc++.h>
using namespace std;
#define y1 cgbngfgn
#define pb push_back
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define fir first
#define m_p make_pair
#define sec second
#define files(name) freopen(name".in","r",stdin); freopen (name".out","w",stdout);
#define left eorgjrptgjs
#define right rtyjtokh
#define y eth
#define int ll
typedef long long ll;
typedef unsigned long long ull;
typedef double ld;
const int md=1e9+7;
const int base=3;

signed main()
{
    int n,m;
    cin>>n>>m;
    string st1,st2;
    cin>>st1>>st2;


    int pos=0;
    while (pos!=st1.size() && st1[pos]!='*')
        pos++;
    if (pos==st1.size())
    {
        if (st1==st2)
            cout<<"YES"; else
            cout<<"NO";
        return(0);
    }

    if (st2.size()+1<st1.size())
    {
        cout<<"NO";
        return(0);
    }

    int cnt1=0;

    while (st1[cnt1]==st2[cnt1])
        cnt1++;
    int cnt2=0;
    while (st1[st1.size()-1-cnt2]==st2[st2.size()-1-cnt2])
        cnt2++;


    if (cnt1+cnt2+1==st1.size())
        cout<<"YES"; else
        cout<<"NO";
}