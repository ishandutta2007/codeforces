#include<bits/stdc++.h>
using namespace std;
#define y1 cgbngfgn
#define pb push_back
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define fir first
#define m_p make_pair
#define sec second
#define files(name) freopen(name".in","r",stdin); freopen (name".out","w",stdout);
#define left eorgjrptgj
#define right rtyjtokh
#define time ddfkjgofidhj
#define int ll
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const int arr=5e5+100;
const int md=1e9+7;
const int base=1039;

string st[arr];

int bal(string s)
{
    int res=0;

    int mn=0;

    for (auto i:s)
    {
        if (i=='(')
            res++; else
            res--;
        mn=min(mn,res);
    }

    if (mn!=res)
        return(1e18);
    return(res);
}

signed main()
{
    map<int,int> cnt;

    int n;
    cin>>n;

    for (int i=1;i<=n;i++)
        cin>>st[i];

    for (int i=1;i<=n;i++)
    {
        cnt[bal(st[i])]++;
    }

    int ans=0;

    for (int i=1;i<=n;i++)
    {
        bool ch=1;

        int now=0;
        for (auto j:st[i])
        {
            if (j=='(')
                now++; else
                now--;
            if (now<0)
                ch=0;
        }

        if (ch)
        {
            ans+=cnt[-now];
        }
    }

    cout<<ans;
}
/*
*/