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

int bpow(int a,int n)
{
    int res=1;
    while (n){
        if (n&1){
            res=(res*a)%md;
        }
        n/=2;
        a=(a*a)%md;
    }
    return res;
}

int inv(int a,int m=md)
{
    return a==1?1:(1-inv(m%a,a)*m)/a+m;
}

void inc(int& a,int b)
{
    a+=b;
    a%=md;
    a+=md;
    a%=md;
}

int k,p_a,p_b;
int dp[ar][ar];
bool use[ar][ar];

int sum(int b1,int q) /// 0<q<1
{
    return b1*inv((1-q+md)%md)%md;
}

int get_sum(int c) /// sum(i=1..inf) i*(c^i)
{
    return c*inv((1-c)*(1-c)%md)%md;
}

int get(int cnt_a,int cnt_ab)
{
    if (use[cnt_a][cnt_ab]){
        return dp[cnt_a][cnt_ab];
    }
    use[cnt_a][cnt_ab]=1;
    int& res=dp[cnt_a][cnt_ab];
    if (cnt_ab>=k){
        return res=cnt_ab;
    }
    if (cnt_a+cnt_ab>=k){
        inc(res,sum((cnt_ab+cnt_a)%md*p_b%md*inv(p_a+p_b)%md,p_a*inv(p_a+p_b)%md));
        inc(res,p_b*inv(p_a+p_b)%md*get_sum(p_a*inv(p_a+p_b)%md));
        return res;
    }
    inc(res,get(cnt_a+1,cnt_ab)*p_a%md*inv(p_a+p_b)%md);
    inc(res,get(cnt_a,cnt_ab+cnt_a)*p_b%md*inv(p_a+p_b)%md);
    return res;
}

main()
{
    #ifdef I_love_Maria_Ivanova
    
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    cin>>k>>p_a>>p_b;
    cout<<get(1,0)<<"\n";
}