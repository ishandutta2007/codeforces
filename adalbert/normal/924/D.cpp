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

struct fenwick_tree
{
    int n;
    vi t;

    fenwick_tree() {}
    fenwick_tree(int n)
    {
        n++;
        this->n=n;
        t.assign(n,0);
    }

    void upd(int pos,int val)
    {
//        cout<<"upd :: "<<pos<<" "<<val<<"\n";
        for (int i=pos;i<n;i|=i+1){
            t[i]+=val;
        }
    }

    int get(int pos)
    {
//        cout<<"get :: "<<pos<<"\n";
        int res=0;
        for (int i=pos;i>=0;i&=i+1,i--){
            res+=t[i];
        }
//        cout<<"res :: "<<res<<"\n";
        return res;
    }
    int get(int l,int r)
    {
        if (l>r){
            return 0;
        }
        return get(r)-get(l-1);
    }
};

int n,w;
int x[arr];
int v[arr];
pii lol1[arr];
pii lol2[arr];

map<pii,int> vh;

bool cmp1(pii a,pii b)
{
    return a.fir*b.sec<a.sec*b.fir;
}

bool cmp2(pair<pii,pii> a,pair<pii,pii> b)
{
    return cmp1(a.fir,b.fir);
}

bool eq(pii a,pii b)
{
    return a.fir*b.sec==a.sec*b.fir;
}

pii get(pii a)
{
    int cnt=0;
    cnt+=(a.fir<0);
    a.fir=abs(a.fir);
    cnt+=(a.sec<0);
    a.sec=abs(a.sec);
    int g=__gcd(a.fir,a.sec);
    a.fir/=g;
    a.sec/=g;
    if (cnt%2==1){
        a.fir*=-1;
    }
    return a;
}

int get_easy_answer(vector<pair<pii,pii>> v)
{
    sort(all(v),cmp2);
//    for (auto i:v){
//        cout<<i.fir.fir<<" "<<i.fir.sec<<" next"<<"\n";
//    }
    int res=0;
    fenwick_tree F(arr);
    for (int i=0;i<len(v);){
        int j=i;
        while (j<len(v)&&eq(v[i].fir,v[j].fir)){
            j++;
        }

        /// [i;j)
        /// let i=j
//        cout<<"["<<i<<";"<<j<<")"<<"\n";

        for (int k=i;k<j;k++){
            int pos=vh[v[k].sec];
            F.upd(pos,+1);
        }

        for (int k=i;k<j;k++){
            int pos=vh[v[k].sec];
//            cout<<"now i will get :: "<<F.get(pos)<<"\n";
            res+=F.get(pos)-1;
        }

        i=j;
    }

    return res;
}

int get_more_easy_answer(vector<pair<pii,pii>> v1,vector<pair<pii,pii>> v2)
{
    sort(all(v1),cmp2);
    sort(all(v2),cmp2);
    int res=0;
    fenwick_tree F(arr);
    int pointer=0; /// [0;pointer)
    for (int i=0;i<len(v1);){
        int j=i;
        while (j<len(v1)&&eq(v1[i].fir,v1[j].fir)){
            j++;
        }

        while (pointer<len(v2)&&eq(v1[i].fir,v2[pointer].fir)){
            int pos=vh[v2[pointer].sec];
            F.upd(pos,+1);
            pointer++;
        }

        /// [i;j)
        /// let i=j

        for (int k=i;k<j;k++){
            int pos=vh[v1[k].sec];
            res+=F.get(pos);
        }

        i=j;
    }

    return res;
}

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    fast;

    cin>>n>>w;
    vector<pii> to_vh;
    for (int i=1;i<=n;i++){
        cin>>x[i]>>v[i];
        lol1[i]=get(mp(x[i],w-v[i]));
        lol2[i]=get(mp(x[i],w+v[i]));
//        cout<<"lol1["<<i<<"] :: "<<lol1[i].fir<<" "<<lol1[i].sec<<"\n";
//        cout<<"lol2["<<i<<"] :: "<<lol2[i].fir<<" "<<lol2[i].sec<<"\n";
        to_vh.pb(lol2[i]);
    }
    if (w==0){
        map<pii,int> lol;
        lol.clear();
        int ans=0;
        for (int i=1;i<=n;i++){
            pii kek=get(mp(x[i],v[i]));
            ans+=lol[kek];
            lol[kek]++;
        }
        cout<<ans<<"\n";
        return 0;
    }
    sort(all(to_vh),cmp1); /// realy smaller
    int cnt_vh=0;
    for (int i=0;i<len(to_vh);){
        int j=i;
        while (j<len(to_vh)&&eq(to_vh[i],to_vh[j])){
            j++;
        }

        /// [i;j)
        /// let i=j

//        cout<<"vh :: "<<to_vh[i].fir<<" "<<to_vh[i].sec<<" :: "<<cnt_vh<<"\n";
        vh[to_vh[i]]=cnt_vh++;

        i=j;
    }

    vector<pair<pii,pii>> v1(0);
    vector<pair<pii,pii>> v2(0);
    for (int i=1;i<=n;i++){
        if (1){
            v1.pb(mp(lol1[i],lol2[i]));
        }
        else{
            v2.pb(mp(lol1[i],lol2[i]));
        }
    }
    int ans=0;
    ans+=get_easy_answer(v1);
//    cout<<ans<<" !!!\n";
//    ans+=get_easy_answer(v2);
//    cout<<ans<<" !!!\n";
//    ans+=get_more_easy_answer(v1,v2);
//    cout<<ans<<" !!!\n";
    cout<<ans<<"\n";
}