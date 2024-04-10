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

#define arr (int)(2e5+10)

const int bsize=2000;

vi version[arr];
int pos_in_version[arr];

int count_with_cnt[arr];
int cnt[arr];

void inc_cnt(int val)
{
    count_with_cnt[cnt[val]]--;
    cnt[val]++;
    count_with_cnt[cnt[val]]++;
}

void dec_cnt(int val)
{
    count_with_cnt[cnt[val]]--;
    cnt[val]--;
    count_with_cnt[cnt[val]]++;
}

int type1[arr];
int l1[arr];
int r1[arr];

int T=0;
int L=1,R=1; /// [L;R)

void add_T(int T)
{
    if (type1[T]==2){
        int pos=l1[T];
        if (L<=pos&&pos<R){
            dec_cnt(version[pos][pos_in_version[pos]]);
        }
        pos_in_version[pos]++;
        if (L<=pos&&pos<R){
            inc_cnt(version[pos][pos_in_version[pos]]);
        }
    }
}

void del_T(int T)
{
    if (type1[T]==2){
        int pos=l1[T];
        if (L<=pos&&pos<R){
            dec_cnt(version[pos][pos_in_version[pos]]);
        }
        pos_in_version[pos]--;
        if (L<=pos&&pos<R){
            inc_cnt(version[pos][pos_in_version[pos]]);
        }
    }
}

void add_element(int position)
{
    inc_cnt(version[position][pos_in_version[position]]);
}

void del_element(int position)
{
    dec_cnt(version[position][pos_in_version[position]]);
}

int get_mex()
{
    int res=1;
    while (count_with_cnt[res]){
        res++;
    }
    return res;
}

map<int,int> vh;

const bool cmp(const pair<pii,pii>& lhs,const pair<pii,pii>& rhs)
{
    pair<int,pii> LHS={lhs.fir.sec/bsize,{lhs.sec.fir/bsize,lhs.sec.sec}};
    pair<int,pii> RHS={rhs.fir.sec/bsize,{rhs.sec.fir/bsize,rhs.sec.sec}};
    return LHS<RHS;
}

int ans[arr];
int a[arr];

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    fast;

    fast;

    int n,q;
    cin>>n>>q;
    for (int i=1;i<=n;i++){
        cin>>a[i];
        vh[a[i]];
        pos_in_version[i]=0;
    }
    vector<pair<pii,pii>> Q(0);
    for (int i=1;i<=q;i++){
        int type,l,r;
        cin>>type>>l>>r;
        type1[i]=type;
        l1[i]=l;
        r1[i]=r;
        if (type==2){
            vh[r];
        }
        else{
            Q.pb({{type,i},{l,r}});
        }
    }
    int cnt_vh=1;
    for (auto& i:vh){
        i.sec=cnt_vh++;
    }
    for (int i=1;i<=n;i++){
        a[i]=vh[a[i]];
        version[i].pb(a[i]);
    }
//    for (auto& q:Q){
//        if (q.fir.fir==2){
//            q.sec.sec=vh[q.sec.sec];
//            version[q.sec.fir].pb(q.sec.sec);
//        }
//    }
    for (int i=1;i<=q;i++){
        if (type1[i]==2){
            r1[i]=vh[r1[i]];
            version[l1[i]].pb(r1[i]);
        }
    }
    sort(all(Q),cmp);
    for (auto i:Q){
        int type=i.fir.fir;
        int t=i.fir.sec;
        int l=i.sec.fir;
        int r=i.sec.sec;
//        cerr<<type<<" "<<t<<" "<<l<<" "<<r<<"\n";
//        cerr<<T<<" "<<l<<" "<<R<<"\n";
        while (L>l){
            add_element(--L);
        }
//        cerr<<"check point 1"<<"\n";
        while (R<=r){
            add_element(R++);
        }
//        cerr<<"check point 2"<<"\n";
        while (L<l){
            del_element(L++);
        }
        while (R>r+1){
            del_element(--R);
        }
//        cerr<<"check point 3"<<"\n";
        while (T<t){
            add_T(++T);
        }
//        cerr<<"check point 4"<<"\n";
        while (T>t){
            del_T(T--);
        }
        ans[t]=get_mex();
//        cerr<<"i end this request !"<<"\n";
    }
    for (int i=1;i<=q;i++){
        if (ans[i]){
            cout<<ans[i]<<"\n";
        }
    }
}