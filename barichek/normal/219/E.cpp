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

int n;

struct seg
{
    int l,r;
    int val;

    seg()
    {
        l=0;
        r=0;
        val=0;
    }

    seg(int l,int r)
    {
        this->l=l;
        this->r=r;
        if (l!=1&&r!=n){
            this->val=min(abs((l+r)/2-l),abs((l+r)/2-r))+1;
        }
        else{
            this->val=r-l+1;
        }
    }
};

struct cmp1
{
    bool operator() (const seg& lhs,const seg& rhs) const
    {
        return lhs.l<rhs.l||(lhs.l==rhs.l&&lhs.r<rhs.r);
    }
};

struct cmp2
{
    bool operator() (const seg& lhs,const seg& rhs) const
    {
        return lhs.val>rhs.val||(lhs.val==rhs.val&&lhs.l<rhs.l);
    }
};

int get_best_p(seg a)
{
    if (a.l==1){
        return 1;
    }
    elif (a.r==n){
        return n;
    }
    else{
        return (a.l+a.r)/2;
    }
}

set<seg,cmp1> s1;
set<seg,cmp2> s2;

void erase(seg a)
{
//    cout<<"erase :: "<<a.l<<" "<<a.r<<"\n";
    s1.erase(a);
    s2.erase(a);
}

void insert(seg a)
{
//    cout<<"insert :: "<<a.l<<" "<<a.r<<"\n";
    s1.insert(a);
    s2.insert(a);
}

void split(seg a,int p)
{
    erase(a);
    if (a.l!=p){
        insert(seg(a.l,p-1));
    }
    if (a.r!=p){
        insert(seg(p+1,a.r));
    }
}

int pos_of_poson[10*arr];

void open_pos(int p)
{
    auto it=s1.lower_bound(seg(p,p));
    bool flag=0;
    if (it!=s1.end()&&it->l==p+1){
        seg buf=*it;
        erase(buf);
        buf=seg(buf.l-1,buf.r);
        insert(buf);
        it=s1.find(buf);
        flag=1;
    }
    if (it!=s1.begin()&&prev(it)->r==p-1){
        it--;
        if (flag){
            seg buf1=*it;
            seg buf2=*next(it);
            erase(buf1);
            erase(buf2);
            seg buf=seg(buf1.l,buf2.r);
            insert(buf);
        }
        else{
            seg buf=*it;
            erase(buf);
            buf=seg(buf.l,buf.r+1);
            insert(buf);
            flag=1;
        }
    }
    if (!flag){
        insert(seg(p,p));
    }
}

main()
{
    #ifdef Barik
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    int m;
    cin>>n>>m;

    insert(seg(1,n));

    for (int i=0;i<m;i++){
        int type,id;
        cin>>type>>id;
//        cout<<"s1 :: ";
//        for (auto i:s1){
//            cout<<i.l<<","<<i.r<<" | ";
//        }
//        cout<<"\n";
//        cout<<"s2 :: ";
//        for (auto i:s2){
//            cout<<i.l<<","<<i.r<<" | ";
//        }
//        cout<<"\n";
        if (type==1){
            seg cur_seg=*s2.begin();
            int p=get_best_p(cur_seg);
            pos_of_poson[id]=p;
            split(cur_seg,p);
            cout<<p<<"\n";
        }
        else{
            open_pos(pos_of_poson[id]);
        }
    }
}