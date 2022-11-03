#include <bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pb push_back
#define m_p make_pair
#define get leirogoerg
#define files(s) freopen(s".in","r",stdin); freopen(s".out","w",stdout);
#define left dogjreg
#define right dgfdogjreg
#define int ll
typedef long long ll;
typedef long double ld;
const int arr=3e5;

int a[arr];

int get(string st, int u)
{
    vector<int> vec;
    vec.pb(-1);
    for (int i=0;i<st.size();i++)
        if (st[i]==u)
        vec.pb(i);

    vec.pb(st.size());

    int res=0;
    for (int i=1;i<vec.size();i++)
        res=max(res,vec[i]-vec[i-1]);
    return(res);
}

signed main()
{
    string st;
    cin>>st;

    int ans=1e9;
    for (int i='a';i<='z';i++)
        ans=min(ans,get(st,i));

    cout<<ans;
}