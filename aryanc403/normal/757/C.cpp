#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define fo(i,n)   for(i=0;i<(n);++i)
#define X first
#define Y second
typedef long long int lli;

struct pa{
    lli x,y;
    pa(lli _x=0,lli _y=0) : x(_x), y(_y) {};

    pa operator + (const pa &o){
        pa ans;
        ans.x=x+o.x;
        ans.y=y+o.y;
        return ans;
    }
    pa operator * (const pa &o){
        pa ans;
        ans.x=x*o.x;
        ans.y=y*o.y;
        return ans;
    }

    pa operator % (const pa &o){
        pa ans;
        ans.x=x%o.x;
        ans.y=y%o.y;
        return ans;
    }
};

bool operator < (const pa &a,const pa &o){
    if(a.x!=o.x)
        return a.x<o.x;
    if(a.y!=o.y)
        return a.y<o.y;
    return false;
}

const lli mod = 1000000007L;
const lli maxM = 1000000L;
const pa B(103L,101L);
const pa M(1000992299L,999119999L);
const lli L = 7L;

    lli n,in;
    lli m,j,k;
    map<lli,lli> b;
    vector<pair<lli,lli>> a[maxM+5];
    lli prt=1;
    map<pa,lli> ans;

pa po(pa a,lli n,pa m)
{
    if(n==0)
        return pa(1,1);
    if(n&1)
        return (a*po(a,n-1,m))%m;
    return po(a*a%m,n/2,m);
}

pa cvt(lli x)
{
    string s="0000000";
    for(lli i=L-1;i>=0;i--)
    {
        s[i]=x%10;
        x/=10;
    }
    pa h;
    lli i;
    fo(i,L)
        h=(h*B+pa(s[i],s[i]))%M;
    return h;
}

void add(vector<pair<lli,lli>> &a)
{
    pa h=0;
    lli pvr=0,n;

    for(auto x:a)
    {
        n=x.X-pvr;
        h= (h*po(B,n*L,M) +cvt(x.Y))%M;
        pvr=x.X;
    }
    ans[h]++;
    prt=(prt*ans[h])%mod;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n>>m;
    for(lli i=1;i<=n;++i)
    {
        cin>>k;
        b.clear();
        fo(j,k)
        {
            cin>>in;
            b[in]++;
        }
        for(auto x:b)
            a[x.X].push_back({i,x.Y});
    }

    for(lli i=1;i<=m;++i)
    {
        a[i].push_back({n+1,0});
        add(a[i]);
    }
    cout<<prt<<endl;
    return 0;
}