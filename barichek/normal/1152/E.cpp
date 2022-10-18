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

int b[arr];
int c[arr];

main()
{
    #ifdef Barik
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    fast;

    int n;
    cin>>n;
    n--;
    for (int i=1;i<=n;i++){
        cin>>b[i];
//        cout<<i<<" "<<b[i]<<" !!\n";
    }
    for (int i=1;i<=n;i++){
        cin>>c[i];
//        cout<<i<<" "<<c[i]<<" !!\n";
    }

    map<int,multiset<int>> reb;
    map<int,int> st;

    for (int i=1;i<=n;i++){
        if (b[i]>c[i]){
//            cout<<"here"<<" LOL"<<"\n";
//            cout<<b[i]<<" "<<c[i]<<"\n";
            cout<<-1<<"\n";
            return 0;
        }
        if (b[i]!=c[i]){
            reb[b[i]].insert(c[i]);
            reb[c[i]].insert(b[i]);
            st[b[i]]++;
            st[c[i]]++;
        }
        else{
            reb[b[i]].insert(c[i]);
            st[b[i]]+=2;
        }
    }

    function<vi()> make_euler=[&]()
    {
        set<int> kekus;
        kekus.clear();
        for (auto i:st){
            if (i.sec%2==1){
                kekus.insert(i.fir);
            }
        }
        if (len(kekus)>2||len(kekus)==1){
            return vi{};
        }
        vi res(0);

        auto del_edge=[&](int u,int v)
        {
            if (u==v){
                reb[u].erase(reb[u].find(v));
            }
            else{
                reb[u].erase(reb[u].find(v));
                reb[v].erase(reb[v].find(u));
            }
        };

        function<void(int)> dfs=[&](int now)
        {
//            cout<<"now :: "<<now<<"\n";
            int last=-1;
            while (!reb[now].empty()&&*reb[now].rbegin()>=last){
                auto it=reb[now].lower_bound(last);
                last=*it;
                del_edge(now,*it);
                dfs(last);
            }
            res.pb(now);
        };

        if (len(kekus)==0){
            dfs(st.begin()->fir);
            res.pop_back();

//            cout<<"res1 :: ";
//            for (auto i:res){
//                cout<<i<<" ";
//            }
//            cout<<"\n";

            if (len(res)<n){
                return vi{};
            }

            res.pb(res.front());

            return res;
        }
        else{
            int p1=*kekus.begin();
            int p2=*kekus.rbegin();

            reb[p1].insert(p2);
            reb[p2].insert(p1);

            dfs(p1);
            res.pop_back();

//            cout<<"res2 :: ";
//            for (auto i:res){
//                cout<<i<<" ";
//            }
//            cout<<"\n";

            if (len(res)<n+1){
                return vi{};
            }

            auto para=[&](int a,int b)
            {
                if (a>b){
                    swap(a,b);
                }
                return mp(a,b);
            };

            int pp=0;

            while (para(res[pp],res[(pp+1)%len(res)])!=para(p1,p2)){
                pp++;
            }

            vi new_res(0);

            for (int i=pp+1;i<len(res);i++){
                new_res.pb(res[i]);
            }
            for (int i=0;i<=pp;i++){
                new_res.pb(res[i]);
            }

            return new_res;
        }
    };

    vi e=make_euler();

//    cout<<"e :: ";
//    for (auto i:e){
//        cout<<i<<" ";
//    }
//    cout<<"\n";

    if (e.empty()){
        cout<<-1<<"\n";
        return 0;
    }

    for (auto i:e){
        cout<<i<<" ";
    }
    cout<<"\n";
}