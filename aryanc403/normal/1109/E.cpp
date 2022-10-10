/*
  Warn - Don't change next line else you will get WA verdict. Online Judge is configured to give WA if next line is not present.
  Author - Aryan Choudhary (@aryanc403)

  const short DEBUG { 0 };
  #define debug(x) if (DEBUG) cout << #x << " = " << x << '\n'
*/

#pragma warning(disable:4996)
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize ("Ofast")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize ("-ffloat-store")

#include<iostream>
#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;
#define fo(i,n)   for(i=0;i<(n);++i)
#define repA(i,j,n)   for(i=(j);i<=(n);++i)
#define repD(i,j,n)   for(i=(j);i>=(n);--i)
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define endl "\n"
#define PI 3.1415926535897932384626433832795
typedef long long int lli;
typedef long double mytype;
typedef pair<lli,lli> ii;
typedef vector<ii> vii;
typedef vector<lli> vi;

clock_t time_p=clock();
void aryanc403()
{
    time_p=clock()-time_p;
    cerr<<"Time Taken : "<<(float)(time_p)/CLOCKS_PER_SEC<<"\n";
}

class CMP
{
public:
    bool operator()(lli a , lli b) //For min priority_queue .
    {
        return ! ( a <= b );
    }
};

void add( map<lli,lli> &m, lli x,lli cnt=1)
{
    map<lli,lli> ::iterator jt;
    jt=m.find(x);
    if(jt==m.end())         m.insert(mp(x,cnt));
    else                    jt->Y+=cnt;
}

void del( map<lli,lli> &m, lli x,lli cnt=1)
{
    map<lli,lli> ::iterator jt;
    jt=m.find(x);
    if(jt->Y<=cnt)            m.erase(jt);
    else                      jt->Y-=cnt;
}

bool cmp(const ii &a,const ii &b)
{
    return a.X<b.X||(a.X==b.X&&a.Y<b.Y);
}
const lli INF = 0xFFFFFFFFFFFFFFFL;
const lli MaxN = 100000L;
const lli MaxP = 2000000L;
const lli MaxF = 10L;

    lli T,n,i,j,k,in,cnt,l,r,mod,ty,x,q,sz;
    lli m;
    vi a,b;
    lli powBase[MaxF][MaxP+5];
    vi :: iterator it;
    
lli po(lli a,lli n)
{
    // assert(n>=0);
    if(n==0)
        return 1;
    if(n&1)
        return (a*po((a*a)%mod,n/2))%mod;
    return po((a*a)%mod,n/2);
}

lli euclid(lli a, lli b, lli &x, lli &y) {
		if (b) { lli d = euclid(b, a % b, y, x);
					return y -= a/b * x, d; }
			return x = 1, y = 0, a;
}

lli modInverse(lli a){
    lli p=mod;
		lli x,y;
			euclid(a,p,x,y);
				return ((x%p+p)%p);
}

void pre(lli n)
{
    lli i,j;
    for(i=2;i*i<=n;++i)
    {
        if(n%i==0)
            b.pb(i);
        while(n%i==0)
            n/=i;
    }
    if(n>1)
        b.pb(n);
    i=0;
    for(auto x:b)
    {
        powBase[i][0]=1;
        repA(j,1,MaxP)
            powBase[i][j]=(powBase[i][j-1]*x)%mod;
        i++;
    }
}

lli lazy[4*MaxN+5][MaxF],val[4*MaxN+5][MaxF];
lli s[4*MaxN+5];

void upd(lli id,const lli v[MaxF])
{
    lli i;
    fo(i,sz)
    {
        lazy[id][i]+=v[i];
        val[id][i]+=v[i];
    }
    
    lazy[id][sz]=(lazy[id][sz]*v[sz])%mod;
    s[id]=(s[id]*v[sz])%mod;
}

void shift(lli id)
{
    upd(2*id,lazy[id]);
    upd(2*id+1,lazy[id]);
    lli i;
    fo(i,sz)
        lazy[id][i]=0;
    lazy[id][sz]=1;
}

void setNode(lli id)
{
    lli x=s[2*id],y=s[2*id+1],i;
    fo(i,sz)
    {
        val[id][i]=min(val[2*id][i],val[2*id+1][i]);
        x=(x*powBase[i][val[2*id][i]-val[id][i]])%mod;
        y=(y*powBase[i][val[2*id+1][i]-val[id][i]])%mod;
        assert(val[2*id][i]-val[id][i]<=MaxP);
        assert(val[2*id+1][i]-val[id][i]<=MaxP);
    }
    s[id]=(x+y)%mod;
}

void update(lli id,lli l,lli r,lli L,lli R,const lli z[MaxF])
{
    if(l>r||r<L||R<l)
        return;
    if(L<=l&&r<=R)
    {
        upd(id,z);
        return;
    }
    lli m=(l+r)/2,i;
    shift(id);
    update(2*id,l,m,L,R,z);
    update(2*id+1,m+1,r,L,R,z);
    setNode(id);
}

void update(lli l,lli r,lli y,lli fl=1)
{
    lli cnt=0,i=0;
    lli c[MaxF];
    for(auto x:b)
    {
        cnt=0;
        while(y%x==0)
        {
            y/=x;
            cnt++;
        }
        c[i]=fl*cnt;
        i++;
    }
    if(fl==1)
        c[i]=y;
    else
        c[i]=modInverse(y);
    update(1,1,n,l,r,c);
}

lli sum(lli root,lli l,lli r,lli L,lli R)
{
    if(l>r||r<L||R<l)
        return 0;
    if(L<=l&&r<=R)
    {
        lli cnt=s[root],i;
        fo(i,sz)
            cnt=(cnt*powBase[i][val[root][i]])%mod;
        assert(val[root][i]<MaxP);
        return cnt;
    }
    lli m=(l+r)/2;
    shift(root);
    return (sum(2*root,l,m,L,R)+sum(2*root+1,m+1,r,L,R))%mod;
}

void dbg(lli id,lli l,lli r)
{
    lli i;
    cerr<<id<<" id "<<l<<" "<<r<<endl;
    fo(i,sz)
        cerr<<b[i]<<" "<<val[id][i]<<endl;
    cerr<<s[id]<<endl<<endl;
}

void built(lli id,lli l,lli r)
{
    lli i;
    if(l==r)
    {
        lli y=a[l];
        fo(i,sz)
        {
            cnt=0;
            while(y%b[i]==0)
            {
                y/=b[i];
                cnt++;
            }
            val[id][i]=cnt;
            lazy[id][i]=0;
        }
        s[id]=y%mod;
        lazy[id][sz]=0;
        return;
    }
    
    fo(i,sz)
    {
        lazy[id][i]=0;
        val[id][i]=0;
    }
    lazy[id][sz]=1;
    lli m=(l+r)/2;
    built(2*id,l,m);
    built(2*id+1,m+1,r);
    setNode(id);
    //dbg(id,l,r);
    return;
}

int main(void) {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin>>n>>mod;
    pre(mod);
    sz=(lli)b.size();
    a.clear();a.reserve(n+1);
    a.pb(0);
    repA(i,1,n)
    {
        cin>>in;
        a.pb(in);
    }
    built(1,1,n);
    cin>>q;
    while(q--)
    {
        cin>>ty;
        if(ty==1)
        {
            cin>>l>>r>>x;
            update(l,r,x);
        }
        else if(ty==2)
        {
            cin>>l>>x;
            update(l,l,x,-1);
        }
        else
        {
            cin>>l>>r;
            cout<<sum(1,1,n,l,r)<<endl;
        }
    }

    aryanc403();
    return 0;
}