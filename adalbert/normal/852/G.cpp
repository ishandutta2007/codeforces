#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <string>
#include <cmath>
#include <algorithm>
#include <assert.h>
#include <memory.h>
#include <string.h>
#include <complex>
#include <queue>
#include <cstdlib>
#include <ctime>
using namespace std;
#define y1 cgbngfgn
#define pb push_back
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define fir first
#define m_p make_pair
#define sec second
#define files(name) freopen(name".sol","r",stdin); freopen (name".dat","w",stdout);
#define time pdojegoritg

#pragma GCC optimize ("O3")
#pragma GCC optimize ("O2")

typedef long long ll;
typedef long double ld;
const int arr=4*1e5;

#define int ll

int base=11;
int md=1e9+7;

map<int,int> mp;

string s;

int hesh=0;

set<int> all;

void add(string st)
{
    int now=0;
    for (int i=0;i<st.size();i++)
    {
        now*=base;
        now+=st[i]-'a'+1;
    }
    mp[now]++;
}

void solve(int u)
{
    if (u==s.size())
    {
        all.insert(hesh);
        return;
    }


    int ans=0;
    if (s[u]=='?')
    {

        solve(u+1);
        for (int c='a';c<='e';c++)
        {
            int pred=hesh;
            hesh*=base;
            hesh+=c-'a'+1;
            solve(u+1);
            hesh=pred;
        }
    } else
    {
        int pred=hesh;
        hesh*=base;
        hesh+=s[u]-'a'+1;
        solve(u+1);
        hesh=pred;
    }
}

signed main()
{
    int n,m;
    cin>>n>>m;
    for (int i=1;i<=n;i++)
    {
        string st;
        cin>>st;
        add(st);
    }

    for (int i=1;i<=m;i++)
    {
        cin>>s;
        hesh=0;all.clear();
        solve(0);
        int ans=0;

        for (auto i:all)
            ans+=mp[i];
        cout<<ans<<'\n';
    }
}