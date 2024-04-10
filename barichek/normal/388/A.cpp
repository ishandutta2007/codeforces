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
vi a;

bool check(int x)
{
//    cout<<"check :: "<<x<<"\n";
    multiset<int> m;
    m.clear();
    for (int i=0;i<x;i++){
        m.insert(a[i]);
    }
    for (int i=x;i<n;i++){
//        cout<<*m.rbegin()<<"\n";
        if (*m.rbegin()==0){
            return 0;
        }
        else{
            int kek=*m.rbegin();
            m.erase(m.find(kek));
            kek--;
            kek=min(kek,a[i]);
            m.insert(kek);
        }
    }
}

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    cin>>n;
    a.resize(n);
    for (auto& i:a){
        cin>>i;
    }
    sort(all(a));
    reverse(all(a));
    for (int i=1;i<=n;i++){
        if (check(i)){
            return cout<<i<<"\n", 0;
        }
    }
}