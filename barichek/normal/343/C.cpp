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

int n,m;
int a[arr];
int b[arr];

bool check(int x)
{
    int p=0;
    for (int i=0;i<n;i++){
        if (a[i]<b[p]){
            while (p<m&&b[p]<=a[i]+x){
                p++;
            }
            if (p==m){
                return 1;
            }
        }
        else{
            if (a[i]-b[p]>x){
                return 0;
            }
            else{
                int max_right=max(a[i]+x-2*(a[i]-b[p]),a[i]+(x-(a[i]-b[p]))/2);
                while (p<m&&b[p]<=max_right){
                    p++;
                }
            }
            if (p==m){
                return 1;
            }
        }
    }
    return 0;
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

    fast;
    cin>>n>>m;
    for (int i=0;i<n;i++){
        cin>>a[i];
    }
    for (int i=0;i<m;i++){
        cin>>b[i];
    }
    sort(a,a+n);
    sort(b,b+m);
    int l=0,r=1e11;
    while (r-l>1){
        int mid=(l+r)/2;
        if (check(mid)){
            r=mid;
        }
        else{
            l=mid;
        }
    }
    cout<<(check(l)?l:r)<<"\n";
}