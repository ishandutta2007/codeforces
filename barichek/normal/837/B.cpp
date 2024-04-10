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

char a[ar][ar];

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #else
        files("");
        files_ds("");
    #endif

    int n,m;
    cin>>n>>m;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            cin>>a[i][j];
        }
    }
    if (n%3==0){
        set<char> s;
        set<char> s1;

        s1.clear();
        for (int i=1;i<=n/3;i++){
            for (int j=1;j<=m;j++){
                s1.insert(a[i][j]);
            }
        }
        if (len(s1)==1){
            s.insert(*s1.begin());
        }

        s1.clear();
        for (int i=n/3+1;i<=2*n/3;i++){
            for (int j=1;j<=m;j++){
                s1.insert(a[i][j]);
            }
        }
        if (len(s1)==1){
            s.insert(*s1.begin());
        }

        s1.clear();
        for (int i=2*n/3+1;i<=n;i++){
            for (int j=1;j<=m;j++){
                s1.insert(a[i][j]);
            }
        }
        if (len(s1)==1){
            s.insert(*s1.begin());
        }

        if (len(s)==3){
            return cout<<"YES"<<"\n", 0;
        }
    }
    if (m%3==0){
        set<char> s;
        set<char> s1;

        s1.clear();
        for (int i=1;i<=n;i++){
            for (int j=1;j<=m/3;j++){
                s1.insert(a[i][j]);
            }
        }
        if (len(s1)==1){
            s.insert(*s1.begin());
        }

        s1.clear();
        for (int i=1;i<=n;i++){
            for (int j=m/3+1;j<=2*m/3;j++){
                s1.insert(a[i][j]);
            }
        }
        if (len(s1)==1){
            s.insert(*s1.begin());
        }

        s1.clear();
        for (int i=1;i<=n;i++){
            for (int j=2*m/3+1;j<=m;j++){
                s1.insert(a[i][j]);
            }
        }
        if (len(s1)==1){
            s.insert(*s1.begin());
        }

        if (len(s)==3){
            return cout<<"YES"<<"\n", 0;
        }
    }
    cout<<"NO"<<"\n";
}