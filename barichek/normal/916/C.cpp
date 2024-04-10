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

bool is_prime(int a)
{
    if (a<=1){
        return 0;
    }
    for (int i=2;i*i<=a;i++){
        if (a%i==0){
            return 0;
        }
    }
    return 1;
}

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    int n,m;
    cin>>n>>m;
    int kek=n-1;
    while (!is_prime(kek)){
        kek++;
    }
    cout<<kek<<" "<<kek<<"\n";
    cout<<1<<" "<<2<<" "<<kek-(n-2)<<"\n";
    for (int i=2;i<n;i++){
        cout<<i<<" "<<i+1<<" "<<1<<"\n";
    }
    m-=n-1;
    int cur1=1;
    int cur2=3;
    while (m--){
        cout<<cur1<<" "<<cur2<<" "<<(md-7)<<"\n";
        if (cur2==n){
            cur1++;
            cur2=cur1+2;
        }
        else{
            cur2++;
        }
    }
}