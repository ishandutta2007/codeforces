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

int cnt[arr];
int f[arr];
int rf[arr];

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

string ss;

int get(string s)
{
    fill(cnt,cnt+arr,0);
    for (auto i:ss){
        cnt[i]++;
    }
    int res=0;
    for (int i=0;i<len(s);i++){
        int lol=f[len(s)-i-1];
        for (int j='a';j<='z';j++){
            lol=lol*rf[cnt[j]]%md;
        }
        for (int j='a';j<s[i];j++){
            if (cnt[j]){
                lol*=f[cnt[j]];
                lol%=md;
                cnt[j]--;
                lol*=rf[cnt[j]];
                lol%=md;

                res+=lol;
                res%=md;

                lol*=f[cnt[j]];
                lol%=md;
                cnt[j]++;
                lol*=rf[cnt[j]];
                lol%=md;
            }
        }
        cnt[s[i]]--;
        if (cnt[s[i]]<0){
            break;
        }
    }
    return res;
}

int naive(string s,string t)
{
    int res=0;
    string ss=s;
    sort(all(ss));
    do
    {
        if (ss>s&&ss<t){
            res++;
        }
    }
    while (next_permutation(all(ss)));
    return res;
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

    string s,t;
    cin>>s>>t;
    if (s>t){
        swap(s,t);
    }
//    cout<<"naive :: "<<naive(s,t)<<"\n";
    ss=s;
//    cout<<get(t)<<"!!\n";
//    cout<<get(s)<<"!!\n";
    cout<<(get(t)-get(s)-1+2*md)%md<<"\n";
}