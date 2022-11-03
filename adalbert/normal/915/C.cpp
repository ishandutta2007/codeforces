#include <bits/stdc++.h>
using namespace std;
#define y1 cgbngfgn
#define pb push_back
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define fir first
#define m_p make_pair
#define sec second
#define files(name) freopen(name".in","r",stdin); freopen (name".out","w",stdout);
#define time pdojegoritg
#define left eorgjrptgj
#define right rtyjtokh
#define int ll
typedef long long ll;
typedef long double ld;
const int arr=5e5+100;
const int md=1e9+7;
const int base=1e9+7;
///magic
/*
#pragma GCC optimize ("O3")
#pragma GCC optimize ("O2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
*/
///

int cnt[100];

string getmax()
{
    string res="";
    for (int i=0;i<=9;i++)
    {
        int c=cnt[i];
        while (c--)
        {
            res+=i+'0';
        }
    }
    return(res);
}

bool ok(string st1,string st2)
{
    if (st1.size()<st2.size())
        return(1); else
        return(st1<=st2);
}

signed main()
{
    string a,b;
    cin>>a>>b;

    for (int i=0;i<a.size();i++)
        cnt[a[i]-'0']++;

    string ans="";

    for (int i=0;i<a.size();i++)
    {
        char mx='0';
        for (int j=0;j<10;j++)
        if (cnt[j]!=0)
        {
            cnt[j]--;
            string now=ans;
            now+=char(j+'0');
            now+=getmax();
            if (ok(now,b))
                mx=j+'0';
            cnt[j]++;
        }
        cnt[mx-'0']--;
        ans+=mx;
    }
    cout<<ans;
}
/*
5
1 2 3 4 5
5
1 1
2 2
3 3
4 4
5 5
*/