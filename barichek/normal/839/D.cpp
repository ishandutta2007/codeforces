#pragma GCC optimize("O3")
#include <bits/stdc++.h>

#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define files(name) name!=""?freopen(name".in","r",stdin),freopen(name".out","w",stdout):0
#define all(a) a.begin(),a.end()
#define len(a) (int)(a.size())
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

#define arr (int)(1e6+10)

int cnt1[arr];
int cnt[arr];
int ans[arr];
int p2[arr];

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    p2[0]=1;
    for (int i=1;i<arr;i++){
        p2[i]=p2[i-1]*2%md;
    }

    int n;
    cin>>n;
    for (int i=0;i<n;i++){
        int a;
        cin>>a;
        cnt1[a]++;
    }
    for (int i=1;i<arr;i++){
        for (int j=i;j<arr;j+=i){
            cnt[i]+=cnt1[j];
        }
    }
    for (int i=arr-1;i>=1;i--){
        if (cnt[i]){
            ans[i]=cnt[i]*p2[cnt[i]-1]%md;
        }
        for (int j=i+i;j<arr;j+=i){
            ans[i]-=ans[j];
            ans[i]%=md;
            ans[i]+=md;
            ans[i]%=md;
        }
    }
    int answer=0;
    for (int i=2;i<arr;i++){
        answer+=ans[i]*i%md;
        answer%=md;
    }
    cout<<answer<<"\n";
}