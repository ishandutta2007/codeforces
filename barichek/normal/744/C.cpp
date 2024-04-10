#include <bits/stdc++.h>

#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define files(name) freopen(name".in","r",stdin); freopen(name".out","w",stdout);
#define all(a) a.begin(),a.end()
#define elif else if
#define mp make_pair
#define pb push_back
#define fir first
#define sec second

using namespace std;
#define int long long

typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long double ld;
typedef long long ll;

const int maxint=numeric_limits<int>::max();
const ll maxll=numeric_limits<ll>::max();
const int arr=2e5+10;
const int ar=2e3+10;
const ld pi=acos(-1);
const ld eps=1e-10;
const ll md=1e9+7;

///---program start---///

vi mask_group[20];
int dp[(1ll<<16)][16*16+2];
pii cnt[arr];

main()
{
    int n;
    cin>>n;
    vector<pair<char,pii>> vec;
    vec.clear();
    vec.resize(n);
    for (auto &i:vec)
        cin>>i.fir>>i.sec.fir>>i.sec.sec;
    int sum_r=0;
    int sum_b=0;
    for (auto i:vec)
        sum_r+=i.sec.fir,
        sum_b+=i.sec.sec;
    for (int mask=1;mask<(1ll<<n);mask++)
        mask_group[__builtin_popcountll(mask)].pb(mask);
    for (int mask=1;mask<(1ll<<n);mask++)
        for (int bit=0;bit<n;bit++)
            if (mask&(1ll<<bit))
            {
                if (vec[bit].fir=='R')
                    cnt[mask].fir++;
                else
                    cnt[mask].sec++;
            }
    for (int i=0;i<(1ll<<16);i++)
        for (int j=0;j<16*16+2;j++)
            dp[i][j]=-1e8;
    dp[0][0]=0;
    for (int i=1;i<=n;i++)
        for (auto new_mask:mask_group[i])
            for (int bit=0;bit<n;bit++)
                if (new_mask&(1ll<<bit))
                {
                    int old_mask=new_mask^(1ll<<bit);
                    int cur_had_r=cnt[old_mask].fir;
                    int cur_had_b=cnt[old_mask].sec;
                    for (int economist=0;economist<16*16;economist++)
                    {
                        if (dp[old_mask][economist]==-1e8) continue;
                        //cout<<"update ::\n";
                        //cout<<" new_mask :: "<<new_mask<<"\n";
                        //cout<<" old_mask :: "<<old_mask<<"\n";
                        //cout<<"  economist :: "<<economist<<"\n";
                        dp[new_mask][economist+min(vec[bit].sec.fir,cur_had_r)]=max(
                                                                                    dp[new_mask][economist+min(vec[bit].sec.fir,cur_had_r)],
                                                                                    dp[old_mask][economist]+min(vec[bit].sec.sec,cur_had_b)
                                                                                    );
                    }
                }
    //for (int j=0;j<=n*n;j++)
      //  cout<<"econom red :: "<<j<<" && dp=="<<dp[(1ll<<n)-1][j]<<"\n";
    //cout<<"sum_r :: "<<sum_r<<"\n";
    //cout<<"sum_b :: "<<sum_b<<"\n";
    int ans=1e12;
    for (int j=0;j<16*16+2;j++)
        ans=min(ans,max(sum_r-j,sum_b-dp[(1ll<<n)-1][j]));
    cout<<ans+n;
}