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

vector<pair<pii,int>> a;

vi xors[arr];
vector<pii> sets[arr];

pii last_make_equal[arr];
int answer[arr];

int f[arr];

void upd(int pos)
{
    for (int i=pos;i<arr;i|=i+1){
        f[i]++;
    }
}

int get(int pos)
{
    int res=0;
    for (int i=pos;i>=0;i&=i+1,i--){
        res+=f[i];
    }
    return res;
}

int get1(int pos)
{
    return get(arr-1)-get(pos-1);
}

main()
{
    #ifdef Barik
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    fast;

    int n,q;
    cin>>n>>q;
    a.resize(n);
    for (int i=0;i<n;i++){
        cin>>a[i].fir.fir;
        if (a[i].fir.fir<0){
            a[i].fir.fir*=-1;
            a[i].fir.sec=1;
        }
        a[i].sec=i+1;
    }

    sort(all(a));
//    for (auto i:a){
//        cout<<i.fir.fir<<" "<<i.fir.sec<<" | "<<i.sec<<"\n";
//    }

    auto make_xor=[&](int time,int value)
    {
//        cout<<"make_xor :: "<<time<<" "<<value<<"\n";
        if (a[0].fir.fir>value){
            return;
        }
        auto id=(upper_bound(all(a),mp(mp(value,md),md))-a.begin())-1;
        xors[id].pb(time);
    };

    auto make_equal=[&](int time,int value,int new_push)
    {
//        cout<<"make_equal :: "<<time<<" "<<value<<" :: "<<new_push<<"\n";
        if (a[len(a)-1].fir.fir<value){
            return;
        }
        auto id=(lower_bound(all(a),mp(mp(value,-md),-md))-a.begin());
//        cout<<"id :: "<<id<<"\n";
        sets[id].pb(mp(time,new_push));
    };

    for (int i=0;i<q;i++){
//        cout<<"req ::::::"<<"\n";
        char type;
        int x;
        cin>>type>>x;
        if (type=='<'){
            if (x<=0){
                make_equal(i,-x+1,0);
            }
            else{
                make_xor(i,x-1);
                make_equal(i,x,0);
            }
        }
        else{
            if (x>=0){
                make_equal(i,x+1,1);
            }
            else{
                make_xor(i,-x-1);
                make_equal(i,-x,1);
            }
        }
    }

    for (int i=0;i<n;i++){
        last_make_equal[i]=mp(-1,a[i].fir.sec);
    }
    for (int i=0;i<n;i++){
        if (i&&last_make_equal[i-1].fir>-1){
            last_make_equal[i]=last_make_equal[i-1];
        }
        for (auto j:sets[i]){
            if (j.fir>last_make_equal[i].fir){
                last_make_equal[i]=j;
            }
        }
//        cout<<i<<" :: "<<last_make_equal[i].fir<<" "<<last_make_equal[i].sec<<"\n";
    }
    for (int i=n-1;i>=0;i--){
        for (auto j:xors[i]){
            upd(j);
        }
        answer[a[i].sec]=a[i].fir.fir;
        if (last_make_equal[i].sec^(get1(last_make_equal[i].fir+1)%2)){
            answer[a[i].sec]*=-1;
        }
    }
    for (int i=1;i<=n;i++){
        cout<<answer[i]<<" ";
    }
    cout<<"\n";
}