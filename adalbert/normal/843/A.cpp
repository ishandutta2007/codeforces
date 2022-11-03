#include <bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pb push_back
#define m_p make_pair
#define get leirogoerg
#define files(s) freopen(s".in","r",stdin); freopen(s".out","w",stdout);
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pii;
typedef vector <pii> vii;
const ld pi = acos(-1);
const int arr = 4*1e5+100;
const ll md = 1e9+7;
const ll base=31;
const int AaA = 'a'-'A';
ld eps=1e-7;

pair<int,int> a[arr];
int pos[arr],use[arr];

signed main()
{
    int n;
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i].fir;
        a[i].sec=i;
    }
    sort(a+1,a+1+n);
    for (int i=1;i<=n;i++)
        pos[a[i].sec]=i;

    vector<vector<int> > ans;
    for (int i=1;i<=n;i++)
    {
        if (use[i]) continue;
        int start=i;
        vector<int> now;
        now.pb(i);
        while (pos[i]!=start)
        {
            use[i]=1;
            i=pos[i];
            now.pb(i);
        }
        use[i]=1;
        ans.pb(now);
        i=start;
    }

    cout<<ans.size()<<'\n';
    for (int i=0;i<ans.size();i++)
    {
        cout<<ans[i].size()<<' ';
        for (int j=0;j<ans[i].size();j++)
            cout<<ans[i][j]<<' ';
        cout<<'\n';
    }
}