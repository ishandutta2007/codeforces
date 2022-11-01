#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const ll inf=(1ll<<60);

struct line
{
    ll k,n,r;
    line(ll a,ll b,ll c){k=a;n=b;r=c;}
};

bool operator<(const line &a,const line &b){return a.k<b.k;}
bool operator<(const line &a,const ll &b){return a.r<b;}

ld intersect(line a,line b)
{
    assert(a.k!=b.k);
    return ((ld)b.n-a.n)/(a.k-b.k);
}

struct cht
{
    set<line,less<>> s;
    void upd(line a,ll nr)
    {
        s.erase(a);
        a.r=nr;
        s.insert(a);
    }
    void updr(set<line>::iterator it)
    {
        if(it!=s.begin())
        {
            line tmp=*it;
            it--;
            upd(*it,floor(intersect(tmp,*it)));
        }
    }
    void add(ll k,ll n)
    {
        line now(k,n,0);
        auto it=s.lower_bound(now);
        if(it!=s.end()&&it->k==k)
        {
            if(n<=it->n) return;
            else
            {
                it=s.erase(it);
                updr(it);
            }
        }
        if(it!=s.end()&&it!=s.begin()&&intersect(*prev(it),now)>intersect(*it,now)) return;
        it=s.insert(now).first;
        it++;
        while(it!=s.end()&&next(it)!=s.end()&&intersect(now,*it)>=intersect(*it,*next(it))) it=s.erase(it);
        it--;
        while(it!=s.begin()&&prev(it)!=s.begin()&&intersect(now,*prev(it))<=intersect(*prev(it),*prev(prev(it)))) it=s.erase(prev(it));
        updr(it);
        if(next(it)!=s.end()) upd(now,floor(intersect(now,*next(it))));
        else upd(now,inf);
    }
    ll query(ll a)
    {
        auto it=s.lower_bound(a);
        ll k=it->k;
        ll n=it->n;
        return k*a+n;
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<array<ll,3>> v(n);
    for(int i=0;i<n;i++) for(int j=0;j<3;j++) cin >> v[i][j];
    sort(v.begin(),v.end());
    cht c;
    c.add(0,0);
    ll res=0;
    for(auto [x,y,a]:v)
    {
        ll dp=x*y-a+c.query(y);
        res=max(res,dp);
        c.add(-x,dp);
    }
    cout << res << "\n";
    return 0;
}