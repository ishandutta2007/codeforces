#include <bits/stdc++.h>

using namespace std;
#define int long long

const int arr=2e5+10;
const int ar=2e3+10;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int,int> pii;
#define pb push_back
#define mp make_pair
#define fir first
#define sec second

///---program start---///

int n,k;
int mid;
int go[50];
int meb[1ll<<22];

bool check(int mask)
{
    for (int i=0;i<n;i++){
        if (mask&(1ll<<i)){
            if (((mask^(1ll<<i))&go[i])!=(mask^(1ll<<i))){
                return 0;
            }
        }
    }
    return 1;
}

int get(int mask)
{
    int res=(1ll<<n)-1;
    for (int i=0;i<n;i++){
        if (mask&(1ll<<i)){
            res&=go[i];
        }
    }
    return res&((1ll<<mid)-1);
}

void print_ans(int size,int k)
{
    ld one=ld(k)/ld(size);
    ld ans=size*one*(k-one)/2;
    cout<<fixed<<setprecision(10)<<ans<<"\n";
}

main()
{
    cin>>n>>k;
    if (n==1){
        return cout<<0<<"\n", 0;
    }
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            bool cur;
            cin>>cur;
            go[i]|=(cur*(1ll<<j));
        }
    }

    mid=n/2;
    /// left [0;mid)
    for (int mask=1;mask<(1ll<<mid);mask++){
        if (check(mask)){
            meb[mask]=__builtin_popcountll(mask);
        }
    }
    /// right [mid;n)
    vector<pii> right(0);
    for (int mask=0;mask<(1ll<<(n-mid));mask++){
        if (check(mask<<mid)){
            right.pb(mp(mask<<mid,get(mask<<mid)));
        }
    }

    for (int i=0;i<mid;i++){
        for (int mask=0;mask<(1ll<<mid);mask++){
            if (mask&(1ll<<i)){
                meb[mask]=max(meb[mask],meb[mask^(1ll<<i)]);
            }
        }
    }

    int ans=0;
    for (auto i:right){
        ans=max(ans,__builtin_popcountll(i.fir)+meb[i.sec]);
    }
    print_ans(ans,k);
}