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
///#define int long long

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

#define arr (int)(3e6+10)

int can_x1[arr];
bool is_prime[arr];

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    for (int i=0;i<arr;i++){
        is_prime[i]=1;
    }

    is_prime[1]=0;

    for (int i=2;i<arr;i++){
        if (is_prime[i]){
            for (int j=2*i;j<arr;j+=i){
                is_prime[j]=0;
            }
        }
    }

    int x2;
    cin>>x2;
    for (int p=2;p<=x2;p++){
        if (is_prime[p]&&x2%p==0){
            int R=x2;
            int L=max(p+1,x2-p+1);
            if (L<=R){
                can_x1[L]++;
                can_x1[R+1]--;
            }
        }
    }

    for (int i=1;i<arr;i++){
        can_x1[i]+=can_x1[i-1];
    }
    int ans=1e9;
    for (int p=2;p<arr;p++){
        if (is_prime[p]){
            for (int j=2*p;j<arr;j+=p){
                /// [p+1,2*p]
                if (can_x1[j]){
                    ans=min(ans,j-p+1);
                }
            }
        }
    }
    cout<<ans<<"\n";
}