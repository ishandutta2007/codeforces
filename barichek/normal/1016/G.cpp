#pragma GCC optimize("O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
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

int cnt_mask_as_a_i[arr];
int cnt_mask_as_a_j[arr];

int cnt_sub_mask_as_a_j[arr];

int n,x,y;
int p[arr];
int alpha[arr];
int beta[arr];
int sz;

bool work[arr];

void add_as_a_i(int a)
{
    if (a%x!=0){
        return;
    }

    int A=a;

    int mask=0;
    for (int i=0;i<sz;i++){
        int cur=0;
        while (a%p[i]==0){
            a/=p[i];
            cur++;
        }
        if (!work[i]){
            continue;
        }
        if (cur!=beta[i]){
            mask|=(1ll<<i);
        }
    }
    cnt_mask_as_a_i[mask]++;
    a=A;

//    cout<<"a :: "<<a/10<<a%10<<" mask_as_a_i :: "<<bitset<10>(mask)<<"\n";
}

void add_as_a_j(int a)
{
    if (y%a!=0){
        return;
    }

    int A=a;

    int mask=0;
    for (int i=0;i<sz;i++){
        int cur=0;
        while (a%p[i]==0){
            a/=p[i];
            cur++;
        }
        if (!work[i]){
            continue;
        }
        if (cur!=alpha[i]){
            mask|=(1ll<<i);
        }
    }
    cnt_mask_as_a_j[mask]++;
    a=A;

//    cout<<"a :: "<<a/10<<a%10<<" mask_as_a_j :: "<<bitset<10>(mask)<<"\n";
}

int mult(int a,int b,int mod)
{
    if (b==0){
        return 0;
    }
    if (b&1){
        return (a+mult(a,b-1,mod))%mod;
    }
    else{
        return mult(2*a%mod,b/2,mod);
    }
}

int polard_ro(int a)
{
    const int magic=2e5;
    vi p(magic,0);
    for (auto p0:{2,3,5}){
        p[0]=p0;
        for (int i=1;i<magic;i++){
            p[i]=(mult(p[i-1],p[i-1],a)+1)%a;
        }
        for (int i=0;2*i<magic;i++){
            int cur=__gcd(a,abs(p[i]-p[i*2]));
            if (a%cur==0&&cur!=1&&cur!=a){
                return cur;
            }
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

    fast;

    cin>>n>>x>>y;

    if (y%x!=0){
        cout<<0<<"\n";
        return 0;
    }
    if (y==1){
        int cnt_1=0;
        for (int i=0;i<n;i++){
            int a;
            cin>>a;
            cnt_1+=(a==1);
        }
        cout<<cnt_1*(cnt_1-1)/2+cnt_1<<"\n";
        return 0;
    }
    /// factorize x,y
    int Y=y;
    int X=x;

    for (int i=2;i<=1e6;i++){
        if (y%i==0){
            int cur=0;
            while (y%i==0){
                y/=i;
                cur++;
            }
            p[sz]=i;
            alpha[sz]=cur;
            sz++;
        }
    }

    if (y!=1){
        int d=polard_ro(y);
        if (d==1||d==y){
            p[sz]=y;
            alpha[sz]=1;
            sz++;
        }
        elif (y==d*d){
            p[sz]=d;
            alpha[sz]=2;
            sz++;
        }
        else{
            p[sz]=d;
            alpha[sz]=1;
            sz++;

            p[sz]=y/d;
            alpha[sz]=1;
            sz++;
        }
    }

    for (int i=0;i<sz;i++){
        while (x%p[i]==0){
            x/=p[i];
            beta[i]++;
        }
        work[i]=(alpha[i]>beta[i]);
    }

    x=X;
    y=Y;

    assert(sz<=15);

//    cout<<x<<" "<<y<<" !!!\n";

//    for (int i=0;i<sz;i++){
//        cout<<"p[i] :: "<<p[i]<<" :: "<<beta[i]<<" "<<alpha[i]<<" !!!\n";
//    }
//    system("pause");
//    return 0;

    /// now easy :)
    for (int i=0;i<n;i++){
        int a;
        cin>>a;
        add_as_a_i(a);
        add_as_a_j(a);
    }
    int ans=0;
    for (int mask=0;mask<(1ll<<sz);mask++){
        cnt_sub_mask_as_a_j[mask]=cnt_mask_as_a_j[mask];
    }
    for (int i=0;i<sz;i++){
        for (int mask=0;mask<(1ll<<sz);mask++){
            if (mask&(1ll<<i)){
                cnt_sub_mask_as_a_j[mask]+=cnt_sub_mask_as_a_j[mask^(1ll<<i)];
            }
        }
    }
    for (int m=0;m<(1ll<<sz);m++){
        ans+=cnt_mask_as_a_i[m]*cnt_sub_mask_as_a_j[((1ll<<sz)-1)^m];
    }
    cout<<ans<<"\n";
}