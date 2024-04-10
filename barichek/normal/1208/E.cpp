//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma,tune=native")
//#pragma GCC optimize("unroll-loops")
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

#define arr (int)(1e6+10)

vi a[arr];
vi lefts[arr];

int maxs[arr];

int ans[arr];
int ans_suf[arr];

main()
{
    #ifdef Barik
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    fast;

    int n,w;
    cin>>n>>w;
    w+=2;
    for (int i=1;i<=n;i++){
        int L;
        cin>>L;

        a[i].resize(L);
        for (auto& j:a[i]){
            cin>>j;
        }
        L+=2;
        a[i].pb(0);
        reverse(all(a[i]));
        a[i].pb(0);
        reverse(all(a[i]));

        maxs[i]=*max_element(all(a[i]));

        int C_p=w-L+1;
        if (1){
            deque<int> pos;

    //        cerr<<i<<" !!!\n";

            lefts[i].resize(L);

            for (int j=0;j<L;j++){
    //            cerr<<"j :: "<<j<<"\n";
                while (!pos.empty()&&a[i][pos.back()]<=a[i][j]){
                    pos.pop_back();
                }
    //            cerr<<"kek1"<<"\n";
                if (!pos.empty()&&pos.front()==j-C_p){
                    pos.pop_front();
                }
    //            cerr<<"kek2"<<"\n";
                pos.push_back(j);
                lefts[i][j]=a[i][pos.front()];
            }
        }

//        cout<<"C_p :: "<<C_p<<"\n";
//        cout<<"lefts["<<i<<"] :: ";
//        for (auto j:lefts[i]){
//            cout<<j<<" ";
//        }
//        cout<<"\n";
        for (int j=0;j<len(a[i]);j++){
            ans[j]+=lefts[i][j];
        }
        if (w-len(a[i])-1>=len(a[i])){
            ans_suf[len(a[i])]+=maxs[i];
            ans_suf[(w-len(a[i])-1)+1]-=maxs[i];
        }

        reverse(all(a[i]));
        if (1){
            deque<int> pos;

    //        cerr<<i<<" !!!\n";

            lefts[i].resize(L);

            for (int j=0;j<L;j++){
    //            cerr<<"j :: "<<j<<"\n";
                while (!pos.empty()&&a[i][pos.back()]<=a[i][j]){
                    pos.pop_back();
                }
    //            cerr<<"kek1"<<"\n";
                if (!pos.empty()&&pos.front()==j-C_p){
                    pos.pop_front();
                }
    //            cerr<<"kek2"<<"\n";
                pos.push_back(j);
                lefts[i][j]=a[i][pos.front()];
            }
        }
        for (int j=0;j<len(a[i]);j++){
            if (w-1-j>=len(a[i])){
                ans[w-1-j]+=lefts[i][j];
            }
        }
    }
    for (int i=1;i<arr;i++){
        ans_suf[i]+=ans_suf[i-1];
        ans[i]+=ans_suf[i];
    }
    for (int i=1;i<w-1;i++){
        cout<<ans[i]<<" ";
    }
    cout<<"\n";
}