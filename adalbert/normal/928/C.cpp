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

unordered_map<string,int> wh;
int cnt_wh=0;
unordered_map<int,string> r_wh;

map<pii,int> wh1;
int cnt_wh1=0;
map<int,pii> r_wh1;

int add_pii(pii a)
{
    if (wh1.count(a)){
        return wh1[a];
    }
    wh1[a]=cnt_wh1++;
    r_wh1[wh1[a]]=a;
    return wh1[a];
}

int add_string(string s)
{
    if (wh.count(s)){
        return wh[s];
    }
    wh[s]=cnt_wh++;
    r_wh[wh[s]]=s;
    return wh[s];
}

int get_num_of_string(int num_of_pair)
{
    return r_wh1[num_of_pair].fir;
}

int get_num_of_version(int num_of_pair)
{
    return r_wh1[num_of_pair].sec;
}

vi reb[arr];

int dp[arr];
bool use[arr];

bool use_kek[arr];
bool good[arr];

vi q[arr];
vector<pair<string,int>> ans(0);

void add_to_answer(int id)
{
    pii p=r_wh1[id];
    ans.pb(mp(r_wh[p.fir],p.sec));
}

void bfs()
{
    use[0]=1;
    q[0].pb(0);
    good[0]=1;
    for (int i=0;!q[i].empty();i++){
        if (i!=0){
            vector<pair<int,int>> cur(0); /// pair<num_of_string,-num_of_version>
            for (auto j:q[i]){
                cur.pb({get_num_of_string(j),-get_num_of_version(j)});
            }
            sort(all(cur));
            for (auto j:cur){
                if (!use_kek[j.fir]){
                    use_kek[j.fir]=1;
                    good[wh1[mp(j.fir,-j.sec)]]=1;
                    add_to_answer(wh1[mp(j.fir,-j.sec)]);
                }
            }
        }
        for (auto now:q[i]){
            if (good[now]){
                for (auto wh:reb[now]){
                    if (!use[wh]){
                        q[i+1].pb(wh);
                        use[wh]=1;
                    }
                }
            }
        }
    }
}

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    fast;

    int n;
    cin>>n;
    for (int i=0;i<n;i++){
        string s;
        int id;
        cin>>s>>id;
        pii cur={add_string(s),id};
        add_pii(cur);
        int k;
        cin>>k;
        while (k--){
            string s;
            int id;
            cin>>s>>id;
            pii to={add_string(s),id};
            if ((i==0&&to.fir!=0)||(cur.fir!=0&&to.fir!=0)){
                reb[add_pii(cur)].pb(add_pii(to));
            }
//            cout<<"edge :: "<<add_pii(cur)<<" -> "<<add_pii(to)<<"\n";
        }
    }
    bfs();
    sort(all(ans));
    cout<<len(ans)<<"\n";
    for (auto i:ans){
        cout<<i.fir<<" "<<i.sec<<"\n";
    }
}