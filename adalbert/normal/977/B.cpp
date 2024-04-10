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
#define int ll
typedef long long ll;
typedef unsigned long long ull;
typedef double ld;
const int arr=6e5;

signed main()
{
    int n;
    cin>>n;
    string st;
    cin>>st;
    map<string,int> mp;

    for (int i=0;i+1<st.size();i++)
    {
        string now="";
        now+=st[i];
        now+=st[i+1];
        mp[now]++;
    }

    pair<int,string> mx={0,""};

    for (auto i:mp)
    {
        mx=max(mx,m_p(i.sec,i.fir));
    }

    cout<<mx.sec;
}
/*
*/