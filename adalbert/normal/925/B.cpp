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

    fast;

    int n,x1,x2;
    cin>>n>>x1>>x2;
    vector<pii> a(0);
    for (int i=1;i<=n;i++){
        int aa;
        cin>>aa;
        a.pb({aa,i});
    }
    sort(all(a));
    /// if 1 2
    int right=-1;
    for (int i=n-1;i>=0;i--){
        if (a[i].fir*(n-1-i+1)>=x2){
            right=i;
            break;
        }
    }
    if (right!=-1){
        int right1=-1;
        for (int i=right-1;i>=0;i--){
            if (a[i].fir*(right-i)>=x1){
                right1=i;
                break;
            }
        }
        if (right1!=-1){
            vi ans1(0);
            vi ans2(0);
            for (int i=right1;i<right;i++){
                ans1.pb(a[i].sec);
            }
            for (int i=right;i<n;i++){
                ans2.pb(a[i].sec);
            }
            cout<<"Yes"<<"\n";
            cout<<len(ans1)<<" "<<len(ans2)<<"\n";
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

    if (1){
        swap(x1,x2);
        int right=-1;
        for (int i=n-1;i>=0;i--){
            if (a[i].fir*(n-1-i+1)>=x2){
                right=i;
                break;
            }
        }
        if (right!=-1){
            int right1=-1;
            for (int i=right-1;i>=0;i--){
                if (a[i].fir*(right-i)>=x1){
                    right1=i;
                    break;
                }
            }
            if (right1!=-1){
                vi ans1(0);
                vi ans2(0);
                for (int i=right1;i<right;i++){
                    ans1.pb(a[i].sec);
                }
                for (int i=right;i<n;i++){
                    ans2.pb(a[i].sec);
                }
                swap(ans1,ans2);
                cout<<"Yes"<<"\n";
                cout<<len(ans1)<<" "<<len(ans2)<<"\n";
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
    }
    cout<<"No"<<"\n";
}