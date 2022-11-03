#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define files(name) freopen(name".in","r",stdin); freopen(name".out","w",stdout);
#define fir first
#define sec second
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long ll;
///-------------------///
vector<pair<ll,ll> > vec;
ll a[1000000][3],kilk,cnt[1000000];
///---program start---///
ll get(string st)
{
    ll tep=0;
    for (int i=0;i<st.size();i++)
    {
        if (a[tep][st[i]-48]==0)
        {
            kilk++;
            a[tep][st[i]-48]=kilk;
        }
        tep=a[tep][st[i]-48];
    }
    return(tep);

}
main()
{
    ll n;
    cin>>n;
    while(n--)
    {
        char type;
        cin>>type;
        if (type=='+')
        {
            string st;
            cin>>st;
            for (int i=0;i<st.size();i++)
                st[i]=st[i]%2+48;
            reverse(st.begin(),st.end());
            while (st.size()<18) st+='0';
            cnt[get(st)]++;
        }
        if (type=='-')
        {
            string st;
            cin>>st;
            for (int i=0;i<st.size();i++)
                st[i]=st[i]%2+48;
            reverse(st.begin(),st.end());
            while (st.size()<18) st+='0';
            cnt[get(st)]--;
        }
        if (type=='?')
        {
            string st;
            cin>>st;
            for (int i=0;i<st.size();i++)
                st[i]=st[i]%2+48;
            reverse(st.begin(),st.end());
            while (st.size()<18) st+='0';
            cout<<cnt[get(st)]<<'\n';
        }
    }

}