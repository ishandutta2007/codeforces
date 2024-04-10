#pragma GCC optimize("O3")
#include <bits/stdc++.h>

#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define files(name) name!=""?freopen(name".in","r",stdin),freopen(name".out","w",stdout):0
#define files_ds(name) name!=""?freopen(name".dat","r",stdin),freopen(name".sol","w",stdout):0
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

void maximize(int& a,int b)
{
    if (a<b){
        a=b;
    }
}

int dp1[ar][2];
int dp2[ar][2];

vi a;
int n;

int do2(int a,bool b);

int do1(int a,bool b)
{
    if (dp1[a][b]!=-1e9){
        return dp1[a][b];
    }
    if (a==n){
        return 0;
    }
    if (a==n-1){
        return b*::a[a];
    }
    int& res=dp1[a][b];
    int sum=0;
    for (int i=a;i<len(::a);i++){
        sum+=::a[i];
    }
    if (b){
//        cout<<sum<<"\n";
//        cout<<do2(a+1,1)<<" !!\n";
        maximize(res,(sum-::a[a])-do2(a+1,1)+::a[a]);
        maximize(res,do1(a+1,1));
    }
    else{
        return res=sum-do2(a,1);
    }
    return res;
}

int do2(int a,bool b)
{
    if (dp2[a][b]!=-1e9){
        return dp2[a][b];
    }
    if (a==n){
        return 0;
    }
    if (a==n-1){
        return b*::a[a];
    }
    int& res=dp2[a][b];
    int sum=0;
    for (int i=a;i<len(::a);i++){
        sum+=::a[i];
    }
    if (b){
        maximize(res,(sum-::a[a])-do1(a+1,1)+::a[a]);
        maximize(res,do2(a+1,1));
    }
    else{
        return res=sum-do1(a,1);
    }
    return res;
}

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #else
        files("");
        files_ds("");
    #endif

    cin>>n;
    a.resize(n);
    for (auto& i:a){
        cin>>i;
    }
    int sum=0;
    for (auto i:a){
        sum+=i;
    }
//    sort(all(a),greater<int>());
//    sort(all(a));
    for (int i=0;i<ar;i++){
        dp1[i][0]=dp1[i][1]=-1e9;
        dp2[i][0]=dp2[i][1]=-1e9;
    }
    cout<<sum-do1(0,1)<<" "<<do1(0,1)<<"\n";
}