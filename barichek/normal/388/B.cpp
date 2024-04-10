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

int n=2;
bool reb[ar][ar];

void add(int from,int to)
{
//    cout<<from<<" "<<to<<"\n";
    reb[from][to]=1;
    reb[to][from]=1;
}

void add_tsep(int from,int to,int len)
{
    len--;
    while (len--){
        n++;
        add(from,n);
        from=n;
    }
    add(from,to);
}

int build(int from,int to,int k)
{
    if (k==1){
        add(from,to);
        return 1;
    }
    if (k&1){
        int buf=build(from,to,k-1);
        add_tsep(from,to,buf);
        return buf;
    }
    else{
        int k1=++n;
        int k2=++n;
        int k3=++n;
        add(from,k1);
        add(k1,k3);
        add(from,k2);
        add(k2,k3);
        return build(k3,to,k/2)+2;
    }
}

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    int k;
    cin>>k;
    build(1,2,k);
    cout<<n<<"\n";
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            cout<<(reb[i][j]?"Y":"N")<<(j==n?"\n":"");
        }
    }
}