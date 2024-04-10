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
#define files(name) freopen(name".dat","r",stdin); freopen (name".sol","w",stdout);
#define left eorgjrptgj
#define right rtyjtokh
#define int ll
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int arr=1600;
const int md=1e9+7;

map<int,int> ok;

int get(int u, int i)
{
    return((u&(1<<i))!=0);
}

bool check(string st)
{
    int u=0;
    for (auto i:st)
    {
        u*=10;
        u+=i-'0';
    }
    if (st.empty() || st[0]=='0')
        return(0);
    return(ok[u]);
}

signed main()
{
    string st;
    cin>>st;

    for (int i=1;i*i<=3*1e9;i++)
        ok[i*i]=1;

    int ans=1e9;
    for (int mask=0;mask<(1<<int(st.size()));mask++)
    {
        string now="";
        for (int j=0;j<st.size();j++)
            if (get(mask,j))
            now+=st[j];
        if (check(now))
            ans=min(ans,int(st.size())-now.size());
    }

    if (ans==1e9)
        cout<<-1; else
        cout<<ans;
}