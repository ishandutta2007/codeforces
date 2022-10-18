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

int l[arr];
int r[arr];
ld sum[arr];

ld sy,a,b;
int n;

bool use[arr];

bool in(int a,int b,int c)
{
    return a<=b&&b<=c;
}

ld intersect(ld x,ld y,ld L,ld R)
{
    ld cur_pos_l=(x*sy-L*(y+sy))/(-y);
    ld cur_pos_r=(x*sy-R*(y+sy))/(-y);

    ld res=max(ld(0),min(b,cur_pos_r)-max(a,cur_pos_l));

//    if (res>=0){
//        cout<<"intersect :: "<<max(a,cur_pos_l)<<";"<<min(b,cur_pos_r)<<" !!\n";
//    }

    return res;
}

ld solve(ld x,ld y)
{
//    ld res=0;
//    for (int i=0;i<n;i++){
////        cout<<"i :: "<<i<<" :: "<<"\n";
//        res+=intersect(x,y,l[i],r[i]);
//    }
//    return res;

    int l1=0,r1=n-1;
    /// find first good
    while (r1-l1>0){
        int m=(l1+r1)/2;
        ld cur_pos=(x*sy-l[m]*(y+sy))/(-y);
        bool good=(cur_pos>=a);
        if (good){
            r1=m;
        }
        else{
            l1=m+1;
        }
    }
    int res1=l1;
    if ((x*sy-l[n-1]*(y+sy))/(-y)<a){
        return intersect(x,y,l[n-1],r[n-1]);
    }

    int l2=0,r2=n-1;
    /// find last good
    while (r2-l2>0){
        int m=(l2+r2+1)/2;
        ld cur_pos=(x*sy-r[m]*(y+sy))/(-y);
        bool good=(cur_pos<=b);
        if (good){
            l2=m;
        }
        else{
            r2=m-1;
        }
    }
    int res2=l2;
    if ((x*sy-r[0]*(y+sy))/(-y)>b){
        return intersect(x,y,l[0],r[0]);
    }

    ld ans=0;

    if (res1<=res2){
        ans+=(sum[res2]-(res1==0?0:sum[res1-1]))*(y+sy)/(y);
    }

    for (int i=max(0ll,res1-1);i<min(n,res1+2);i++){
        if (!in(res1,i,res2)&&!use[i]){
            use[i]=1;
            ans+=intersect(x,y,l[i],r[i]);
        }
    }
    for (int i=max(0ll,res2-1);i<min(n,res2+2);i++){
        if (!in(res1,i,res2)&&!use[i]){
            use[i]=1;
            ans+=intersect(x,y,l[i],r[i]);
        }
    }

    for (int i=max(0ll,res1-1);i<min(n,res1+2);i++){
        use[i]=0;
    }
    for (int i=max(0ll,res2-1);i<min(n,res2+2);i++){
        use[i]=0;
    }

    return ans;
}

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    fast;

    cin>>sy>>a>>b;
    sy*=-1;
    cin>>n;
    for (int i=0;i<n;i++){
        cin>>l[i]>>r[i];
        sum[i]=(i==0?0:sum[i-1])+(r[i]-l[i]);
    }

    int q;
    cin>>q;
    int cnt_do=0;
    while (q--){
        int x,y;
        cin>>x>>y;
//        if (++cnt_do==154){
//            cout<<fixed<<setprecision(10)<<solve(x,y)<<"\n";
//            return 0;
//        }
//        if (q<20)
        cout<<fixed<<setprecision(10)<<solve(x,y)<<"\n";
    }
}