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

void add(int& a,int b)
{
    a+=b;
    a%=md;
    if (a<0){
        a+=md;
    }
}

int bpow(int a,int n)
{
    int res=1;
    while (n){
        if (n&1){
            res=res*a%md;
        }
        n/=2;
        a=a*a%md;
    }
    return res;
}

int f[arr];
int rf[arr];

int C(int n,int k)
{
//    cout<<"C("<<n<<","<<k<<")"<<"\n";
    if (k<0||k>n){
        return 0;
    }
    return f[n]*rf[k]%md*rf[n-k]%md;
}

int CC(int m,int k)
{
//    cout<<"CC("<<m<<" "<<k<<")"<<"\n";
    if (m==0){
        return 1;
    }
    return C(m+k-1,k-1);
}

int get(int c00,int c01,int c10,int c11)
{
//    cout<<"get :: "<<c00<<" "<<c01<<" "<<c10<<" "<<c11<<"\n";

    if (min({c00,c01,c10,c11})<0){
        return 0;
    }

    int all_bits=c00+c01+c10+c11+1;

    if (1){
        int groups_0=c10;
        int groups_1=c01+1;
        int cnt_0=groups_0+c00;
        int cnt_1=all_bits-cnt_0;

        if (cnt_0<0){
            return 0;
        }

        if (cnt_1<=0){
            return 0;
        }

//        cout<<"groups_0 :: "<<groups_0<<" && groups_1 :: "<<groups_1<<"\n";
//        cout<<"cnt_0 :: "<<cnt_0<<" && cnt_1 :: "<<cnt_1<<"\n";

        if (groups_0>cnt_0){
            return 0;
        }
        if (groups_1>cnt_1){
            return 0;
        }

        if (groups_1!=groups_0&&groups_1!=groups_0+1){
            return 0;
        }

        return CC(cnt_1-groups_1,groups_1)*CC(cnt_0-groups_0,groups_0)%md;
    }
}

int get(string s,int c00,int c01,int c10,int c11)
{
//    cout<<"get :: "<<s<<" "<<c00<<" "<<c01<<" "<<c10<<" "<<c11<<"\n";
    int all_bits=c00+c01+c10+c11+1;
//    cout<<"all_bits :: "<<all_bits<<"\n";
    if (len(s)<all_bits){
        return 0;
    }
    if (len(s)>all_bits){
        return get(c00,c01,c10,c11);
    }
    int res=0;
    for (int i=0;i<len(s);i++){
        if (i>=2){
            if (s[i-2]=='0'&&s[i-1]=='0'){
                c00--;
            }
            if (s[i-2]=='0'&&s[i-1]=='1'){
                c01--;
            }
            if (s[i-2]=='1'&&s[i-1]=='0'){
                c10--;
            }
            if (s[i-2]=='1'&&s[i-1]=='1'){
                c11--;
            }
        }
        if (s[i]=='1'){
            if (i>=1){
                if (s[i-1]=='0'){
                    c00--;
                }
                if (s[i-1]=='1'){
                    c10--;
                }
//                cout<<"iii :: "<<i<<"\n";
                if (i+1==len(s)&&(c00==0&&c01==0&&c10==0&&c11==0)){
//                    cout<<"lol :: "<<"+1"<<"\n";
                    add(res,+1);
                }
                else{
                    add(res,get(c11,c10,c01,c00));
                }
                if (s[i-1]=='0'){
                    c00++;
                }
                if (s[i-1]=='1'){
                    c10++;
                }
            }
        }
    }
//    cout<<"res :: "<<res<<"\n";
    return res;
}

int good(string s,int c00,int c01,int c10,int c11)
{
    int cc[2][2];
    cc[0][0]=0;
    cc[0][1]=0;
    cc[1][0]=0;
    cc[1][1]=0;
    for (int i=1;i<len(s);i++){
        cc[s[i-1]-'0'][s[i]-'0']++;
    }
    if (cc[0][0]!=c00){
        return 0;
    }
    if (cc[0][1]!=c01){
        return 0;
    }
    if (cc[1][0]!=c10){
        return 0;
    }
    if (cc[1][1]!=c11){
        return 0;
    }
    return 1;
}

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    f[0]=1;
    for (int i=1;i<arr;i++){
        f[i]=f[i-1]*i%md;
    }
    rf[arr-1]=bpow(f[arr-1],md-2);
    for (int i=arr-2;i>=0;i--){
        rf[i]=rf[i+1]*(i+1)%md;
    }

    string a,b;
    cin>>a>>b;
    int c00,c01,c10,c11;
    cin>>c00>>c01>>c10>>c11;

    cout<<(get(b,c00,c01,c10,c11)-get(a,c00,c01,c10,c11)+good(b,c00,c01,c10,c11)+md)%md<<"\n";
}