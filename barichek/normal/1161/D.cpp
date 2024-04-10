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
///#define int long long

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

bool use[arr];
int value[arr];
vi edges1[arr];
vi edges2[arr];

void make_zero(int v)
{
//    cout<<"zero :: "<<v<<"\n";
    value[v]=0;
}

void make_one(int v)
{
//    cout<<"one :: "<<v<<"\n";
    value[v]=1;
}

void make_equal(int u,int v)
{
//    cout<<"equal :: "<<u<<" "<<v<<"\n";
    edges1[u].pb(v);
    edges1[v].pb(u);
}

void make_diff(int u,int v)
{
//    cout<<"diff :: "<<u<<" "<<v<<"\n";
    edges2[u].pb(v);
    edges2[v].pb(u);
}

int comp[arr];
bool mark[arr];

vi cur;

void dfs(int now,int c)
{
    cur.pb(now);
    use[now]=1;
    comp[now]=c;
    for (auto wh:edges1[now]){
        if (!use[wh]){
            dfs(wh,c);
        }
    }
}

int value_comp[arr];
vi reb[arr];

vi cur1;
vi cur2;

void dfs2(int now,int color)
{
    if (color){
        cur1.pb(now);
    }
    else{
        cur2.pb(now);
    }
    mark[now]=color;
    use[now]=1;
    for (auto wh:reb[now]){
        if (!use[wh]){
            dfs2(wh,color^1);
        }
    }
}

main()
{
    #ifdef Barik
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    string s;
    cin>>s;
    int m=len(s);
    int ans=0;
    for (int i=m-2;i>=0;i--){
        auto solve=[&]()
        {
            int c=0;
            for (int i=0;i<2*m;i++){
                if (!use[i]){
                    cur.clear();
                    c++;
                    value_comp[c]=-1;
                    dfs(i,c);

//                    cout<<"new comp :: ";
//                    for (auto i:cur){
//                        cout<<i<<" ";
//                    }
//                    cout<<"\n";

                    int val=-1;
                    for (auto j:cur){
                        if (value[j]!=-1){
                            if (val!=-1&&val!=value[j]){
                                return 0;
                            }
                            val=value[j];
                        }
                    }
                    value_comp[c]=val;
                }
            }
            for (int i=1;i<=c;i++){
                reb[i].clear();
            }
            for (int i=0;i<2*m;i++){
                for (auto j:edges2[i]){
                    if (i<j){
                        if (comp[i]==comp[j]){
//                            cout<<i<<" "<<j<<" kek1\n";
                            return 0;
                        }
                        reb[comp[i]].pb(comp[j]);
                        reb[comp[j]].pb(comp[i]);
                    }
                }
            }
            for (int i=0;i<2*m;i++){
                use[i]=0;
                mark[i]=0;
            }
            int res=1;
            for (int i=1;i<=c;i++){
                if (!use[i]){
                    cur1.clear();
                    cur2.clear();
                    dfs2(i,0);

//                    cout<<"cur1 :: ";
//                    for (auto i:cur1){
//                        cout<<i<<" ";
//                    }
//                    cout<<"\n";
//                    cout<<"cur2 :: ";
//                    for (auto i:cur2){
//                        cout<<i<<" ";
//                    }
//                    cout<<"\n";

                    for (auto j:cur1){
                        for (auto wh:reb[j]){
                            if (mark[j]==mark[wh]){
//                                cout<<j<<" "<<wh<<" :(1"<<"\n";
                                return 0;
                            }
                        }
                    }
                    for (auto j:cur2){
                        for (auto wh:reb[j]){
                            if (mark[j]==mark[wh]){
//                                cout<<j<<" "<<wh<<" :(2"<<"\n";
                                return 0;
                            }
                        }
                    }

                    int val1=-1;
                    int val2=-1;
                    for (auto j:cur1){
                        if (value_comp[j]!=-1){
                            if (val1!=-1&&val1!=value_comp[j]){
//                                cout<<"comp :: "<<val1<<" "<<j<<" 1\n";
                                return 0;
                            }
                            val1=value_comp[j];
                        }
                    }
                    for (auto j:cur2){
                        if (value_comp[j]!=-1){
                            if (val2!=-1&&val2!=value_comp[j]){
//                                cout<<"comp :: "<<val2<<" "<<j<<" 2\n";
                                return 0;
                            }
                            val2=value_comp[j];
                        }
                    }
                    if (val1!=-1&&val2!=-1&&val1==val2){
//                        cout<<i<<" "<<val1<<" "<<val2<<"\n";
                        return 0;
                    }
                    if (val1==-1&&val2==-1){
                        res=res*2%998244353ll;
                    }
                }
            }
            return res;
        };

        /// clear
            for (int j=0;j<2*m;j++){
                use[j]=0;
                value[j]=-1;
                edges1[j].clear();
                edges2[j].clear();
            }

        for (int j=i+1;j<m;j++){
            make_zero(j);
        }
        make_one(i);
        make_one(2*m-1);
        for (int j=0;j<m;j++){
            int id=m-j-1;
            if (s[j]=='0'){
                make_equal(id,id+m);
            }
            if (s[j]=='1'){
                make_diff(id,id+m);
            }
        }
        for (int l=0,r=i;l<r;l++,r--){
            make_equal(l,r);
        }
        for (int l=m,r=2*m-1;l<r;l++,r--){
            make_equal(l,r);
        }
        ans+=solve();
//        cout<<i<<" "<<ans<<" !!\n";
        ans%=998244353ll;
    }
    cout<<ans<<"\n";
}