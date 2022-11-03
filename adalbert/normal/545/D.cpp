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

int n;
int a[arr];

bool check(int x)
{
//    cout<<"check :: "<<x<<"\n";
    multiset<int> ms;
    for (int i=0;i<n;i++){
        ms.insert(a[i]);
    }
    int sum=0;
    int cnt=0;
    while (1){
        if (ms.empty()||*ms.rbegin()<sum){
            break;
        }
        auto it=ms.lower_bound(sum);
        sum+=*it;
        ms.erase(it);
        cnt++;
    }
    return cnt>=x;
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
    for (int i=0;i<n;i++){
        cin>>a[i];
    }
    int l=0,r=n;
    while (r-l>1){
        int m=(l+r)/2;
        if (check(m)){
            l=m;
        }
        else{
            r=m;
        }
    }
    int res=check(r)?r:l;
    cout<<res<<"\n";
}