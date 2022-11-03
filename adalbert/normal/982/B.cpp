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
#pragma GCC optimize ("O2")
#define int ll
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

signed main()
{
    int n;
    cin>>n;

    set<pair<int,int> > setik1,setik2;

    for (int i=1;i<=n;i++)
    {
        int a;
        cin>>a;
        setik1.insert({a,i});
    }

    string st;
    cin>>st;
    for (auto i:st)
        if (i=='0')
    {
        pair<int,int> now=*setik1.begin();
        setik1.erase(now);
        cout<<now.sec<<' ';
        setik2.insert(now);
    } else
    {
        pair<int,int> now=*setik2.rbegin();
        setik2.erase(now);
        cout<<now.sec<<' ';

    }
}
/*
*/