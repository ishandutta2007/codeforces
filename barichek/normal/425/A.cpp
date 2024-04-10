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

main()
{
    int n,k;
    cin>>n>>k;
    vi a;
    a.resize(n);
    for (auto &i:a)
        cin>>i;
    int ans=-maxint;
    for (int i=0;i<n;i++)
    {
        for (int j=i;j<n;j++)
        {
            int cnt=0;
            multiset<int> setik;
            multiset<int> left;
            for (int j_=0;j_<i;j_++)
                left.insert(a[j_]);
            for (int j_=j+1;j_<n;j_++)
                left.insert(a[j_]);
            for (int j_=i;j_<=j;j_++)
                cnt+=a[j_],
                setik.insert(a[j_]);
            int k_=k;
            while (k_--&&!left.empty())
            {
                if (*left.rbegin()>*setik.begin())
                {
                    int from=*setik.begin();
                    int to=*left.rbegin();
                    setik.erase(setik.find(from));
                    left.erase(left.find(to));
                    setik.insert(to);
                    left.insert(from);
                    cnt-=from;
                    cnt+=to;
                }
            }
            ans=max(ans,cnt);
        }
    }
    cout<<ans;
}