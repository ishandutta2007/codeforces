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

struct line
{
    /// k*x+b
    ld k,b;
    set<line>::iterator it;
    set<line>* where;

    line() {}
    line(ld k,ld b)
    {
        this->k=k;
        this->b=b;
    }

    ld eval(ld x)
    {
        return k*x+b;
    }
};

const bool operator<(const line& lhs,const line& rhs)
{
    if (rhs.k==5e18){
        auto it=lhs.it;
        return next(it)!=lhs.where->end()&&next(it)->k*rhs.b+next(it)->b<=it->k*rhs.b+it->b;
    }
    return lhs.k>rhs.k||(lhs.k==rhs.k&&lhs.b<rhs.b);
}

ld intersect(line l1,line l2)
{
    return (l1.b-l2.b)/(l2.k-l1.k);
}

bool to_erase(line l1,line l2,line l3)
{
    ld x=intersect(l1,l3);
    return l2.eval(x)>=l3.eval(x);
}

struct convex_hull_trick
{
    set<line> lines;

    convex_hull_trick()
    {
        lines.clear();
    }

    void add_line(line l)
    {
        auto it=lines.insert(l).fir;
        line* what=(line*)&*it;
        what->it=it;
        what->where=(set<line>*)&lines;

        if (it!=lines.begin()&&next(it)!=lines.end()&&to_erase(*prev(it),*it,*next(it))){
            lines.erase(it);
            return;
        }

        while (it!=lines.begin()&&prev(it)!=lines.begin()&&to_erase(*prev(prev(it)),*prev(it),*it)){
            lines.erase(prev(it));
        }

        while (next(it)!=lines.end()&&next(next(it))!=lines.end()&&to_erase(*it,*next(it),*next(next(it)))){
            lines.erase(next(it));
        }
    }

    ld get(ld x)
    {
        if (lines.empty()){
            return 5e18;
        }
        auto it=*lines.lower_bound(line{5e18,x});
        return it.eval(x);
    }
};

int n;
int a[arr];
int b[arr];
int dp[arr];
convex_hull_trick kek;

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>a[i];
    }
    for (int i=1;i<=n;i++){
        cin>>b[i];
    }
    dp[1]=0;
    kek.add_line(line{b[1],dp[1]});
    for (int i=2;i<=n;i++){
        dp[i]=kek.get(a[i]);
        kek.add_line(line{b[i],dp[i]});
    }
    cout<<dp[n]<<"\n";
}