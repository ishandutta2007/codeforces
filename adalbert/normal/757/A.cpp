#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
typedef double ld;
#define int ll
#define y1 humiuyn
#define fir first
#define sec second
#define pb push_back
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define files(name) freopen(name".in","r",stdin); freopen(name".out","w",stdout);
vector <pair <int,int> > vec[200000];
int cnt[100000];
///-----------------------------------------------------------------------///
signed main()
{
    string st;
    cin>>st;
    for (int i=0;i<st.size();i++)
        cnt[st[i]]++;
    st="Bulbasaur";
    int ans=1e9;
    for (int i=0;i<st.size();i++)
        ans=min(ans,cnt[st[i]]);
    cout<<min(min(ans,cnt['a']/2),cnt['u']/2);
}