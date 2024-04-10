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
const int arr=2e5;

int ans=0;

int p[arr],use[arr];

void dfs(int u)
{
    if (use[u])
        return;
    use[u]=1;
    ans++;
    dfs(p[u]);
}

signed main()
{
    int n;
    cin>>n;
    for (int i=1;i<=n;i++)
        cin>>p[i];

    vector<int> vec;

    for (int i=1;i<=n;i++)
        if (!use[i])
        {
            dfs(i);
            vec.pb(ans);
            ans=0;
        }

    sort(vec.begin(),vec.end());
    if (vec.size()==1)
    {
        cout<<vec[0]*vec[0];
    } else
    {
        vec[vec.size()-2]+=vec.back();
        vec.pop_back();
        int ans=0;
        for (auto i:vec)
            ans+=i*i;
        cout<<ans;
    }
}

/*
!!! https://pastebin.com/jHpxMZq3
*/