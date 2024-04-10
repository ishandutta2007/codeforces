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

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    int n;
    cin>>n;
    n++;
    vi a(n);
    for (auto& i:a){
        cin>>i;
    }
    for (int i=1;i<len(a);i++){
        if (a[i]!=1&&a[i-1]!=1){
            vi ans1(0);
            {
                ans1.pb(0);
                int kek=1;
                for (int j=1;j<len(a);j++){
                    int cnt=a[j];
                    int new_kek=kek;
                    while (cnt--){
                        ans1.pb(kek);
                        new_kek++;
                    }
                    kek=new_kek;
                }
            }
            vi ans2(0);
            {
                ans2.pb(0);
                int kek=1;
                for (int j=1;j<len(a);j++){
                    int cnt=a[j];
                    int new_kek=kek;
                    bool ok=0;
                    while (cnt--){
                        if (j==i&&!ok){
                            ans2.pb(kek-1);
                        }
                        else{
                            ans2.pb(kek);
                        }
                        new_kek++;
                        ok=1;
                    }
                    kek=new_kek;
                }
            }
            cout<<"ambiguous"<<"\n";
            for (auto i:ans1){
                cout<<i<<" ";
            }
            cout<<"\n";
            for (auto i:ans2){
                cout<<i<<" ";
            }
            cout<<"\n";
            return 0;
        }
    }
    cout<<"perfect"<<"\n";
}