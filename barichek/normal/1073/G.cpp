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

int n,q;
string s;

ull pp[arr];

ull h[arr];

ull magic(int a,int b)
{
    return (a+1)*b%(a==1?1:a-1)^124+a*b+a+b*1000ul+a^b+a^(b*12442ull)+a*a^(b%124564ull)+a%(b==0?1:b)+b%(a==0?1:a)+b*a%(b%a==0?1:b%a);
}

ull get_hash(int l,int r)
{
    if (l==r){
        return s[l];
    }
    ull res=h[r];
    res-=h[l];

    res*=pp[arr-l-1];

//    res%=md;
//    if (res<0){
//        res+=md;
//    }

    return res;
}

bool eq(int l1,int r1,int l2,int r2)
{
    return r1-l1==r2-l2&&s[l1]==s[l2]&&get_hash(l1,r1)==get_hash(l2,r2);
}

int lcp(int i,int j)
{
    int l=0,r=len(s)-max(i,j);
    while (r-l>0){
        int m=(l+r+1)/2;
        if (eq(i,i+m-1,j,j+m-1)){
            l=m;
        }
        else{
            r=m-1;
        }
    }
//    cout<<"lcp :: "<<s.substr(i)<<" "<<s.substr(j)<<" "<<l<<"\n";
    return l;
}

bool cmp(int i,int j)
{
    int l=lcp(i,j);
    if (i+l-1==len(s)-1||j+l-1==len(s)-1){
        return i>j;
    }
    return s[i+l]<s[j+l];
}

int p[arr];
int lpc[arr];

const int M=20;

int lg[arr];
int stb[arr][M];

int get_min(int l,int r)
{
    int k=lg[r-l+1];
    return min(stb[l][k],stb[r-(1ll<<k)+1][k]);
}

int L[arr];
int R[arr];

ull get_sum_min(vi v)
{
    vector<pii> s;

    s.clear();
    for (int i=0;i<len(v);i++){
        while (!s.empty()&&s.back().fir>v[i]){
            s.pop_back();
        }
        if (s.empty()){
            L[i]=-1;
        }
        else{
            L[i]=s.back().sec;
        }
        s.pb(mp(v[i],i));
    }

    s.clear();
    for (int i=len(v)-1;i>=0;i--){
        while (!s.empty()&&s.back().fir>=v[i]){
            s.pop_back();
        }
        if (s.empty()){
            R[i]=len(v);
        }
        else{
            R[i]=s.back().sec;
        }
        s.pb(mp(v[i],i));
    }


    ull res=0;
    for (int i=0;i<len(v);i++){
        res+=1ull*(i-L[i])*(R[i]-i)*v[i];
    }

//    cout<<"get_sum_min :: ";
//    for (auto i:v){
//        cout<<i<<" ";
//    }
//    cout<<"\n";
//    for (int i=0;i<len(v);i++){
//        cout<<"L["<<i<<"] R["<<i<<"] :: "<<L[i]<<" "<<R[i]<<"\n";
//    }
//    cout<<" res :: "<<res<<"\n";
    return res;
}

int rp[arr];

ull get(vi a)
{
    for (auto &i:a){
        i=rp[i];
    }

    sort(all(a));

//    cout<<"get :: :)"<<"\n";
//    cout<<"new a :: ";
//    for (auto i:a){
//        cout<<i<<" ";
//    }
//    cout<<"\n";
//    for (auto i:a){
//        cout<<s.substr(p[i])<<"\n";
//    }

    vi v(0);

    for (int i=0;i+1<len(a);i++){
        if (a[i]==a[i+1]){
            v.pb(len(s)-p[a[i]]);
        }
        else{
            v.pb(get_min(a[i],a[i+1]-1));
        }
    }

    return get_sum_min(v);
}

int class_eq[arr];
vector<pii> vh[arr];
vector<int> vh1[arr];

bool cmp_magic(int i,int j)
{
    return class_eq[i]<class_eq[j];
}

vector<pair<pii,int>> vh_sort[arr];

int fff[arr];
int lll[arr];
int nnn[arr];

void build_p()
{
    s=s+"#";
    n++;
    for (int i=0;i<n;i++){
        class_eq[i]=s[i];
    }
    for (int j=1;j<M;j++){

        vector<pair<pii,int>> v(0);
        for (int i=0;i<n;i++){
            v.pb(mp(mp(class_eq[i],class_eq[(i+(1ll<<(j-1)))%n]),i));
        }

//        sort(all(v));

        /// sort v in O(n)

        int max_class_eq=*max_element(class_eq,class_eq+n);

        vector<pair<pii,int>> vv;
        vv=v;
        int sz;

        for (int i=0;i<=max_class_eq;i++){
            fff[i]=-1;
        }
        for (int i=0;i<n;i++){
            int val=v[i].fir.sec;
            if (fff[val]==-1){
                fff[val]=i;
            }
            else{
                nnn[lll[val]]=i;
            }
            lll[val]=i;
            nnn[i]=-1;
        }
        sz=0;
        for (int i=0;i<=max_class_eq;i++){
            int cur=fff[i];
            while (cur!=-1){
                vv[sz++]=v[cur];
                cur=nnn[cur];
            }
        }
        v=vv;


        for (int i=0;i<=max_class_eq;i++){
            fff[i]=-1;
        }
        for (int i=0;i<n;i++){
            int val=v[i].fir.fir;
            if (fff[val]==-1){
                fff[val]=i;
            }
            else{
                nnn[lll[val]]=i;
            }
            lll[val]=i;
            nnn[i]=-1;
        }
        sz=0;
        for (int i=0;i<=max_class_eq;i++){
            int cur=fff[i];
            while (cur!=-1){
                vv[sz++]=v[cur];
                cur=nnn[cur];
            }
        }
        v=vv;

        int last=0;
        for (int i=0;i<n;i++){
            if (i==0||v[i].fir!=v[i-1].fir){
                class_eq[v[i].sec]=last++;
            }
            else{
                class_eq[v[i].sec]=class_eq[v[i-1].sec];
            }
        }
    }
    n--;
    s.pop_back();
    sort(p,p+n,cmp_magic);
}

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

    pp[0]=1;
    for (int i=1;i<arr;i++){
        pp[i]=pp[i-1]*12425ull;
    }

    cin>>n>>q;
    cin>>s;
    h[0]=0;
    for (int i=1;i<n;i++){
        h[i]=h[i-1]+pp[i]*magic(s[i-1],s[i]);
    }

    for (int i=0;i<n;i++){
        p[i]=i;
    }

    build_p();

    for (int i=0;i<n;i++){
        rp[p[i]]=i;
    }

//    for (int i=0;i<n;i++){
//        for (int j=i+1;j<n;j++){
//            cout<<"cmp("<<i<<","<<j<<") :: "<<cmp(i,j)<<"\n";
//        }
//    }

//    for (int i=0;i<n;i++){
//        cout<<s.substr(p[i])<<"\n";
//        cout<<"p["<<i<<"] :: "<<p[i]<<"\n";
//    }

    for (int i=1;i<n;i++){
        lpc[i-1]=lcp(p[i-1],p[i]);
    }
//    for (int i=1;i<n;i++){
//        cout<<"lpc["<<i-1<<"] :: "<<lpc[i-1]<<"\n";
//    }

    for (int i=0;i<n-1;i++){
        stb[i][0]=lpc[i];
    }
    for (int j=1;j<M;j++){
        for (int i=0;i+(1ll<<j)-1<n-1;i++){
            stb[i][j]=min(stb[i][j-1],stb[i+(1ll<<(j-1))][j-1]);
        }
    }

    while (q--){
        int s1,s2;
        cin>>s1>>s2;

        vi ab(0);
        vi a(0);
        vi b(0);

        while (s1--){
            int x;
            cin>>x;
            x--;

            a.pb(x);
            ab.pb(x);
        }

        while (s2--){
            int x;
            cin>>x;
            x--;

            b.pb(x);
            ab.pb(x);
        }

        cout<<get(ab)-get(a)-get(b)<<"\n";
    }
}