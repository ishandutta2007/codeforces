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

#define arr (int)(1e6+10)

#define hash hash_____

ull p[arr];

vi v;
vector<ull> hash;

void hash_it()
{
    for (int i=0;i+1<len(v);i++){
//        hash.pb(((hash.empty()?0:hash.back())+p[i]*v[i]%md)%md);
        hash.pb((hash.empty()?0:hash.back())+p[i]*(v[i+1]*125325ull-v[i]*1ull*v[i+1]+v[i+1]%(abs(v[i])+1)+v[i]*124ull%(abs(v[i+1])+1)));
    }
}

ull get_hash(int l,int r)
{
    if (l==r){
        return v[l];
    }

    r--;

    ull res=hash[r];
    if (l){
        res-=hash[l-1];
    }
//    if (res<0){
//        res+=md;
//    }

    res=res*p[arr-l-1];

    return res;
}

int lcp(int i,int j)
{
//    cout<<"lcp :: "<<i<<" "<<j<<" :: ";
    int l=0,r=min(len(v)-i,len(v)-j);
    while (r-l>0){
        int m=(l+r+1)/2;
        if (get_hash(i,i+m-1)==get_hash(j,j+m-1)){
            l=m;
        }
        else{
            r=m-1;
        }
    }

//    cout<<l<<"\n";

    return l;
}

bool smaller(int i,int j)
{
    int l=lcp(i,j);
    if (i+l-1==len(v)-1||j+l-1==len(v)-1){
        return i>j;
    }
    return v[i+l]<v[j+l];
}

ll ans[arr];
int pos_start[arr];
int who[arr];

int L[arr];

int lsp[arr];

const int M=20;
int sparse[arr][M];

void build_sparse(int n)
{
    for (int i=0;i<n;i++){
        sparse[i][0]=lsp[i];
    }
    for (int j=1;(1ll<<j)<=n;j++){
        for (int i=0;i+(1ll<<j)-1<n;i++){
            sparse[i][j]=min(sparse[i][j-1],sparse[i+(1ll<<(j-1))][j-1]);
        }
    }
}

int lg[arr];

int get_sparse(int l,int r)
{
    int L=lg[r-l+1];
    return min(sparse[l][L],sparse[r-(1ll<<L)+1][L]);
}

pii f(int x,int y) /// max seg that :: pos with ind==x have lcp>=y
{
//    cout<<"f("<<x<<","<<y<<") :: ";
    int L=x;
    if (x!=0&&lsp[x-1]>=y){
        int l=1,r=x;
        while (r-l>0){
            int m=(l+r+1)/2;
            if (get_sparse(x-m,x-1)>=y){
                l=m;
            }
            else{
                r=m-1;
            }
        }
        L=x-l;
    }
    int R=x;
    if (x!=len(v)-1&&lsp[x]>=y){
        int l=1,r=len(v)-x-1;
        while (r-l>0){
            int m=(l+r+1)/2;
            if (get_sparse(x,x+m-1)>=y){
                l=m;
            }
            else{
                r=m-1;
            }
        }
        R=x+l;
    }
//    cout<<"("<<L<<","<<R<<")"<<"\n";
    return mp(L,R);
}

bool check(int id,int len_pref)
{
    pii kek=f(id,len_pref);
    return L[kek.sec]>=kek.fir;
}

int kekus[arr];

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    fast;

    for (int i=2;i<arr;i++){
        lg[i]=lg[i/2]+1;
    }

//    p[0]=1235237ll;
//    for (int i=1;i<arr;i++){
//        p[i]=p[i-1]*1235237ll%md;
//    }

    p[0]=1235237ull;
    for (int i=1;i<arr;i++){
        p[i]=p[i-1]*1235237ull;
    }

    int n,k;
    cin>>n>>k;
    for (int i=0;i<n;i++){
        string s;
        cin>>s;
        pos_start[i]=len(v)+1;
        who[len(v)]=-1;
        v.pb(300000+i);
        int lolus=len(s);
        for (auto j:s){
            who[len(v)]=i;
            kekus[len(v)]=lolus;
            v.pb(j);
            lolus--;
        }
    }
    who[len(v)]=-1;
    v.pb(0);

//    cout<<"v :: "<<"\n";
//    for (int i=0;i<len(v);i++){
//        cout<<" v["<<i<<"] :: "<<v[i]<<"\n";
//    }

//    cout<<"i will hash it !"<<"\n";

    hash_it();

//    cout<<"hashed !"<<"\n";

    vi id(0);

    for (int i=0;i<len(v);i++){
        id.pb(i);
    }

//    cout<<"i will sort id !"<<"\n";

    sort(all(id),smaller);

//    if (n==1e5){
//        return 0;
//    }

//    cout<<"id is sorted !"<<"\n";

//    cout<<"id :: "<<"\n";
//    for (int i=0;i<len(id);i++){
//        cout<<" id["<<i<<"] :: "<<id[i]<<"\n";
//    }

    for (int i=1;i<len(id);i++){
        lsp[i-1]=lcp(id[i-1],id[i]);
//        cout<<"lsp["<<i-1<<"] :: "<<lsp[i-1]<<"\n";
    }

    set<pii> s;
    s.clear();
    map<int,int> last;
    for (int i=0;i<len(id);i++){
//        cout<<"lol :: "<<i<<" "<<id[i]<<" "<<who[id[i]]<<"\n";
        if (who[id[i]]!=-1){
            if (last.count(who[id[i]])){
                s.erase(mp(last[who[id[i]]],who[id[i]]));
            }
            last[who[id[i]]]=i;
            s.insert(mp(last[who[id[i]]],who[id[i]]));
        }

        if (len(s)>k){
            s.erase(s.begin());
        }

        if (len(s)==k){
            L[i]=s.begin()->fir;
        }
        else{
            L[i]=-1e9;
        }

//        cout<<"L["<<i<<"] :: "<<L[i]<<"\n";
    }

    build_sparse(len(id)-1);

    for (int i=0;i<len(id);i++){
        if (who[id[i]]!=-1){
            int l=0,r=kekus[id[i]];
            while (r-l>0){
                int m=(l+r+1)/2;
                if (check(i,m)){
                    l=m;
                }
                else{
                    r=m-1;
                }
            }
//            cout<<i<<" "<<id[i]<<" "<<who[id[i]]<<" :: "<<l<<"\n";
            ans[who[id[i]]]+=l;
        }
    }

    for (int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<"\n";
}