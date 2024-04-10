
 #include<bits/stdc++.h>
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
const int md=1e9+7;
const int arr=7e5;

int ans=0;

bool use[arr];
vector<int> vec[arr],vis;
int sum[arr],mx[arr],v[arr],len[arr],tutu[arr];

void getsize(int u, int pred)
{
    sum[u]=1;
    mx[u]=0;
    vis.pb(u);

    for (auto i:vec[u])
        if (i!=pred && !use[i])
    {
        getsize(i,u);
        sum[u]+=sum[i];
        mx[u]=max(mx[u],sum[i]);
    }
}

int allsum;

void add(int u, int pred, int sum, int ln)
{
    if (ln%2)
        sum-=v[u]; else
        sum+=v[u];
    sum%=md;
    sum+=md;
    sum%=md;

    tutu[u]=sum;
    len[u]=ln;
    allsum+=sum;
    allsum%=md;

    vis.pb(u);

    for (auto i:vec[u])
        if (i!=pred && !use[i])
        add(i,u,sum,ln+1);

}

void change_ans(int u)
{
    allsum=0;
    int cnt=0;
    for (auto i:vec[u])
        if (!use[i])
        {
            vis.clear();
            add(i,u,v[u],1);
            cnt+=vis.size();
        }
    int sum=allsum;
    ans+=allsum+v[u];
    ans%=md;
    ans+=md;
    ans%=md;
    for (auto i:vec[u])
        if (!use[i])
        {
            allsum=0;
            vis.clear();
            add(i,u,v[u],1);
            sum-=allsum;
            sum%=md;
            sum+=md;
            sum%=md;
            for (auto i:vis)
            {
                if (len[i]%2==0)
                {
                    ans+=sum+(cnt-vis.size())*(((tutu[i]-v[u])%md+md)%md)%md;
                    ans%=md;
                    ans+=md;
                    ans%=md;
                    ans+=tutu[i];
                    ans%=md;
                    ans+=md;
                    ans%=md;
                } else
                {
                    ans-=sum+(cnt-vis.size())*(((tutu[i]-v[u])%md+md)%md)%md;
                    ans%=md;
                    ans+=md;
                    ans%=md;
                    ans-=tutu[i];
                    ans%=md;
                    ans+=md;
                    ans%=md;
                }
            }

            sum+=allsum;
            sum%=md;
            sum+=md;
            sum%=md;
        }

}

void solve(int u)
{
    vis.clear();
    getsize(u,0);

    int root=0;
    for (auto i:vis)
        if (max(sum[u]-sum[i],mx[i])<=sum[u]/2)
        root=i;

    change_ans(root);

    use[root]=1;
    for (auto i:vec[root])
        if (!use[i])
        solve(i);
}

signed main()
{
    fast;
    int n;
    cin>>n;
    for (int i=1;i<=n;i++)
        cin>>v[i];

    for (int i=1;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        vec[a].pb(b);
        vec[b].pb(a);
    }

    solve(1);

    cout<<ans<<'\n';
}