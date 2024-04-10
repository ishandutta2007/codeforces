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

const int bsize=300;

int n,k;
int type[arr];
int a[arr];
ll pref_math[arr];
ll pref_ec[arr];
ll global_ans;

unordered_map<ll,int> vh;

int cnt_r[10*arr];
int cnt_l_minus_one[10*arr];

ll ans[arr];

int vh1[arr];
int vh2[arr];
int vh3[arr];
vector<pair<pii,int>> qq;

const bool cmp(const pair<pii,int>& lhs,const pair<pii,int>& rhs)
{
    if (lhs.fir.fir/bsize!=rhs.fir.fir/bsize){
        return lhs.fir.fir/bsize<rhs.fir.fir/bsize;
    }
    return lhs.fir.sec<rhs.fir.sec;
}

void add_l(int l)
{
    cnt_r[vh2[l]]++;
    cnt_l_minus_one[vh2[l-1]]++;
    global_ans+=cnt_r[vh3[l-1]];
}

void add_r(int r)
{
    cnt_r[vh2[r]]++;
    cnt_l_minus_one[vh2[r-1]]++;
    global_ans+=cnt_l_minus_one[vh1[r]];
}

void del_l(int l)
{
    global_ans-=cnt_r[vh3[l-1]];
    cnt_r[vh2[l]]--;
    cnt_l_minus_one[vh2[l-1]]--;
}

void del_r(int r)
{
    global_ans-=cnt_l_minus_one[vh1[r]];
    cnt_r[vh2[r]]--;
    cnt_l_minus_one[vh2[r-1]]--;
}

static const int buf_size=4096;

static unsigned char buf[buf_size];

static int buf_len=0,buf_pos=0;

inline bool is_eof()
{
    if (buf_pos==buf_len){
        buf_pos=0;
        buf_len=fread(buf,1,buf_size,stdin);
        if (buf_pos==buf_len){
            return 1;
        }
    }
    return 0;
}

inline int get_char()
{
    return is_eof()?-1:buf[buf_pos++];
}

inline int read_char()
{
    char c=get_char();
    while (c!=-1&&c==32){
        c=get_char();
    }
    return c;
}

inline int read_int()
{
    int x=0;
    int m=1;
    char c=read_char();
    if (c=='-'){
        m=-1;
        c=get_char();
    }
    elif (c=='+'){
        c=get_char();
    }
    while ('0'<=c&&c<='9'){
        x=x*10+(c-'0');
        c=get_char();
    }
    return x*m;
}

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    /**

    pref_math[r]-pref_math[l-1]-(pref_ec[r]-pref_ec[l-1])==k;
    pref_math[r]-pref_ec[r]==pref_math[l-1]-pref_ec[l-1]+k

    */

    n=read_int();
    k=read_int();
    for (int i=1;i<=n;i++){
        type[i]=read_int();
    }
    for (int i=1;i<=n;i++){
        a[i]=read_int();
        if (type[i]==1){
            pref_math[i]=pref_math[i-1]+a[i];
            pref_ec[i]=pref_ec[i-1];
        }
        else{
            pref_math[i]=pref_math[i-1];
            pref_ec[i]=pref_ec[i-1]+a[i];
        }
    }

    for (int i=0;i<=n;i++){
        vh[pref_math[i]-pref_ec[i]-k];
        vh[pref_math[i]-pref_ec[i]];
        vh[pref_math[i]-pref_ec[i]+k];
    }

    int kek=0;
    for (auto& i:vh){
        i.sec=++kek;
    }

    for (int i=0;i<=n;i++){
        vh1[i]=vh[pref_math[i]-pref_ec[i]-k];
        vh2[i]=vh[pref_math[i]-pref_ec[i]];
        vh3[i]=vh[pref_math[i]-pref_ec[i]+k];
    }

    int q;
    q=read_int();
    for (int i=0;i<q;i++){
        int l,r;
        l=read_int();
        r=read_int();
        qq.pb({{l,r},i});
    }

    sort(all(qq),cmp);

    int l=1,r=1; /// [l;r)
    for (auto w:qq){
        int L=w.fir.fir;
        int R=w.fir.sec;

        while (l>L){
            add_l(--l);
        }
        while (r<=R){
            add_r(r++);
        }

        while (l<L){
            del_l(l++);
        }
        while (r>R+1){
            del_r(--r);
        }

        ans[w.sec]=global_ans;
    }
    for (int i=0;i<q;i++){
        cout<<ans[i]<<"\n";
    }
}