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

#define arr (int)(1e6+10)

signed pref[30][arr];
vi lol;

int bpow(int a,int n,int mod)
{
    int res=1;
    while (n){
        if (n&1){
            res*=a;
            res%=mod;
        }
        n/=2;
        a=(a*a)%mod;
    }
    return res;
}

int inv(int a,int mod)
{
    return bpow(a,mod-2,mod);
}

string s;

bool ok(int num,int x,int y)
{
//    cout<<"  ok :: "<<num<<" "<<x<<" "<<y<<"\n";
    int s1=0;
    s1+=pref[num][x];

    int s2=0;
    s2+=pref[num][y];
    s2-=(pref[num][x]*bpow(10,y-x,lol[num]))%lol[num];
    if (s2<0){
        s2+=lol[num];
    }

    int s3=0;
    s3+=pref[num][len(s)-1];
    s3-=(pref[num][y]*bpow(10,len(s)-y-1,lol[num]))%lol[num];
    if (s3<0){
        s3+=lol[num];
    }

//    cout<<"    "<<s1<<" "<<s2<<" "<<s3<<"\n";

    if ((s1+s2)%lol[num]==s3){
        return 1;
    }
    else{
        return 0;
    }
}

void check(int x,int y)
{
//    cout<<"check("<<x<<","<<y<<")"<<"\n";
    if (y<=x){
        return;
    }
    if (y==len(s)-1){
        return;
    }
    if (s[y+1]=='0'){
        return;
    }
    for (int i=0;i<len(lol);i++){
        if (!ok(i,x,y)){
//            cout<<"  fail :: "<<lol[i]<<"\n";
            return;
        }
    }
    string s1=s.substr(0,x+1);
    string s2=s.substr(x+1,y-x);
    string s3=s.substr(y+1);
    exit(!(cout<<s1<<"+"<<s2<<"="<<s3<<"\n"));
}

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    srand(time(0));

    int kek=1e9+7;
    while (len(lol)<30){
        kek=1e9+7+(rand()*rand())%(1000*1000*1000);
        while (!is_prime(kek)){
            kek++;
        }
        lol.pb(kek++);
    }
    cin>>s;
    for (int i=0;i<len(lol);i++){
        for (int j=0;j<len(s);j++){
            if (j==0){
                pref[i][j]=(s[j]-'0')%lol[i];
            }
            else{
                pref[i][j]=(pref[i][j-1]*10ll+(s[j]-'0'))%lol[i];
            }
        }
    }
    if (s[0]=='0'){
        string s1=s.substr(1,(len(s)-1)/2);
        cout<<"0"<<"+"<<s1<<"="<<s1<<"\n";
        return 0;
    }
    if (len(s)%2==1){
        string s1=s.substr(0,(len(s)-1)/2);
        string s2=s.substr((len(s)-1)/2+1);
        if (s1==s2){
            if (s[(len(s)-1)/2]=='0'){
                cout<<s1<<"+"<<"0"<<"="<<s2<<"\n";
                return 0;
            }
        }
    }
    for (int i=0;i<len(s)/2;i++){
        if (s[i+1]!='0'){
            for (int j=i+1;j<=i+2;j++){
                check(i,len(s)-j-1);
            }
            int easy=len(s)-i-1;
            for (int j=easy/2-1;j<=easy/2+1;j++){
                check(i,len(s)-j-1);
            }
        }
    }
    return 0;
    assert(0);
}