#pragma GCC optimize("O3")
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

const int arr=2e5+10;
const int ar=2e3+10;
const ld pi=acos(-1);
const ld eps=1e-10;
const ll md=1e9+7;

///---program start---///

int cnt[arr];
int new_cnt[2001];

main()
{
    fast;
    int n,k,x;
    cin>>n>>k>>x;
    vi a;
    a.clear();
    a.resize(n);
    for (auto &i:a)
        cin>>i;
    for (auto i:a)
        cnt[i]++;
    while (k--)
    {
        memset(new_cnt,0,sizeof(new_cnt));
        int cur=0;
        for (int i=0;i<=2e3;i++)
            if (cnt[i])
            {
                int cur_cnt=cnt[i];
                if (cur%2==0)
                {
                    //cerr<<"gavno with val :: "<<i<<"\n";
                    cnt[i]-=(cur_cnt+1)/2;
                    new_cnt[i^x]+=(cur_cnt+1)/2;
                    cur+=cur_cnt;
                }
                else
                {
                    cnt[i]-=cur_cnt/2;
                    new_cnt[i^x]+=cur_cnt/2;
                    cur+=cur_cnt;
                }
            }
        for (int i=0;i<=2e3;i++)
            cnt[i]+=new_cnt[i];
    }
    int ans1=0;
    int ans2=1e9;
    for (int i=0;i<=2e3;i++)
        if (cnt[i])
            ans1=max(ans1,i),
            ans2=min(ans2,i);
    cout<<ans1<<" "<<ans2<<"\n";
}