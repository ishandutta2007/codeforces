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
const ll md=1e9+7;
const ld eps=1e-10;

///---program start---///

#define int ll

main()
{
    ll a,b,c;
    cin>>a>>b>>c;
    if (a+b+c==1) return cout<<0, 0;
    if (a==1&&b==1&&c==0) return cout<<0, 0;
    if (a==1&&b==0&&c==1) return cout<<0, 0;
    if (a==0&&b==1&&c==1) return cout<<0, 0;
    if (a==1&&b==1&&c==1) return cout<<0, 0;
    ll ans=maxll;
    for (int i=0;i<3;i++)
        for (int j=1;j<4;j++)
        {
            int cnt1=max((a!=0)*(a-(i<=0)-(j>=1)),0ll);
            int cnt2=max((b!=0)*(b-(i<=1)-(j>=2)),0ll);
            int cnt3=max((c!=0)*(c-(i<=2)-(j>=3)),0ll);
            //cout<<cnt1<<" "<<cnt2<<" "<<cnt3<<" 000!\n";
            int cur=maxll;
            cnt1=max(cnt1,max(cnt2,cnt3));
            cur=min(cur,cnt1*3);
            //cur=min(cur,max(cnt2-2,0ll)*3);
            //cur=min(cur,max(cnt3-2,0ll)*3);
            //cout<<i<<" "<<j<<" "<<cur<<" 111!\n";
            if (cur==0&&a<2&&b<2&&c<2)
            {
                if (j<=i) continue;
                else cur+=j-i;
            }
            else cur+=3-i, cur+=j;
            //cout<<i<<" "<<j<<" "<<cur<<" 222!\n";
            //cout<<i<<" "<<j<<" "<<cur-a-b-c<<" !!!!!!!!\n";
            ans=min(ans,cur-a-b-c);
        }
    cout<<ans;
}