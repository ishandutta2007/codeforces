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

unordered_map<string,int> kek;
vector<vi> reb[arr];
int n;

int to_int(string s)
{
    stringstream stt;
    stt<<s;
    int res;
    stt>>res;
    return res;
}

vector<string> split(string s,char c=' ')
{
    vector<string> res(0);
    string cur="";
    for (auto i:s){
        if (i==c){
            if (!cur.empty()){
                res.pb(cur);
                cur="";
            }
        }
        else{
            cur+=i;
        }
    }
    if (!cur.empty()){
        res.pb(cur);
        cur="";
    }
    return res;
}

int p[arr];

int find1(int a)
{
    return p[a]==a?a:p[a]=find1(p[a]);
}

void merge1(int a,int b)
{
    a=find1(a);
    b=find1(b);
    if (a==b){
        return;
    }
    if (rand()&1){
        swap(a,b);
    }
    p[a]=b;
}

void answer(vector<pii> ans)
{
//    cout<<"ans :: "<<"\n";
//    for (auto i:ans){
//        cout<<i.fir<<" "<<i.sec<<"\n";
//    }
    if (ans.size()!=n-1){
        exit(!(cout<<-1<<"\n"));
    }
    for (int i=1;i<=n;i++){
        p[i]=i;
    }
    for (auto i:ans){
        merge1(i.fir,i.sec);
    }
    for (int i=1;i<=n;i++){
        if (find1(i)!=find1(1)){
            exit(!(cout<<-1<<"\n"));
        }
    }
    cout<<n-1<<"\n";
    for (auto i:ans){
        cout<<i.fir<<" "<<i.sec<<"\n";
    }
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
    int global_cnt=0;
    for (int i=1;i<=n;i++){
        string s;
        cin>>s;
        vector<string> vec=split(s,'-');
        global_cnt+=len(vec);
//        cout<<"len(vec) :: "<<len(vec)<<"\n";
        if (global_cnt>2*(n-1)){
            return cout<<-1<<"\n", 0;
        }
        for (auto k:vec){
            string cur=k;
            for (int j=0;j<len(cur);j++){
                if (cur[j]==':'){
                    cur=cur.substr(j+1);
                    break;
                }
            }
            vector<string> cur1=split(cur,',');
            reb[i].pb(vi{});
            for (auto j:cur1){
                reb[i].back().pb(to_int(j));
            }
        }
    }
//    cout<<"global_cnt :: "<<global_cnt<<"\n";
    if (global_cnt!=2*(n-1)){
        return cout<<-1<<"\n", 0;
    }
    vector<pii> ans(0);
    for (int i=1;i<=n;i++){
//        cout<<"set ans :: "<<i<<"\n";
        string cur=string(n+1,'0');
        for (auto j:reb[i]){
            for (auto k:j){
                cur[k]='1';
            }
        }
        for (auto j:reb[i]){
            string cur1=string(n+1,'0');
            for (auto k:j){
                cur1[k]='1';
            }
            if (kek[cur1]){
                ans.pb(mp(i,kek[cur1]));
            }
//            cout<<"set kek :: "<<cur1<<"\n";
            for (auto k:j){
                cur[k]='0';
            }
            cur[i]='1';
            kek[cur]=i;
            for (auto k:j){
                cur[k]='1';
            }
            cur[i]='0';
        }
    }
    answer(ans);
}