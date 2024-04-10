#pragma GCC optimize("O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
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

int f(int n)
{
    int res=0;
    while ((res+1)*(res+2)/2<=n){
        res++;
    }
    return res;
}

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    int a,b;
    cin>>a>>b;
    int F=f(a+b);
    if (1){
        int cur=F;
        int aa=a;
        vi ans1(0);
        int sum_left=0;
        while (cur){
            if (cur<=aa){
                ans1.pb(cur);
                aa-=cur;
            }
            else{
                sum_left+=cur;
            }
            cur--;
        }
        if (sum_left<=b){
            vi ans2(0);
            set<int> have1(all(ans1));
            for (int i=1;i<=F;i++){
                if (!have1.count(i)){
                    ans2.pb(i);
                }
            }

//            cout<<F<<"\n";
            cout<<len(ans1)<<"\n";
            for (auto i:ans1){
                cout<<i<<" ";
            }
            cout<<"\n";
            cout<<len(ans2)<<"\n";
            for (auto i:ans2){
                cout<<i<<" ";
            }
            cout<<"\n";
        }
        else{
            int cur=F-1;
            int aa=a;
            vi ans1(0);
            int sum_left=0;
            while (cur){
                if (cur<=aa){
                    ans1.pb(cur);
                    aa-=cur;
                }
                else{
                    sum_left+=cur;
                }
                cur--;
            }
            vi ans2(0);
            set<int> have1(all(ans1));
            for (int i=1;i<=F;i++){
                if (!have1.count(i)){
                    ans2.pb(i);
                }
            }

            assert(len(ans1)+len(ans2)==F-1);
//            cout<<F-1<<"\n";
            cout<<len(ans1)<<"\n";
            for (auto i:ans1){
                cout<<i<<" ";
            }
            cout<<"\n";
            cout<<len(ans2)<<"\n";
            for (auto i:ans2){
                cout<<i<<" ";
            }
            cout<<"\n";
        }
    }
}