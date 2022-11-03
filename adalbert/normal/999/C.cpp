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
#pragma GCC optimize ("O2")
typedef long long ll;
typedef unsigned long long ull;
typedef double ld;

vector<int> vec[1000];

int ans[600000];

signed main()
{
    int n,k;
    cin>>n>>k;

    string st;
    cin>>st;

    for (int i=0;i<st.size();i++)
        vec[st[i]].pb(i);

    for (int i='a';i<='z';i++)
    {
        reverse(vec[i].begin(),vec[i].end());

        while (k && !vec[i].empty())
            vec[i].pop_back(),k--;

        for (auto j:vec[i])
            ans[j]=i;
    }

    string res="";
    for (int i=0;i<n;i++)
        if (ans[i]!=0)
        res+=ans[i];

    cout<<res;
}