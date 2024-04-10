//for(auto a: x);
#include<iostream>
#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;
#define fo(i,n)   for(i=0;i<(n);++i)
#define LLI long long int
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define MAX 1000002
typedef long long int lli;
typedef pair<lli,lli> ii;
typedef long double mytype;
typedef vector<ii> vii;
typedef vector<lli> vi;
const lli INF = 0xFFFFFFFFFFFFFFFL;
const lli MOD = 1000000007L;
    lli T,n,in,i,m,j,k;
    vii t;
    vi a;
    vi :: iterator it;

const mytype esp = 1e-12;

bool cmp(const ii &a,const ii &b)
{
    return a.X<b.X||(a.X==b.X&&a.Y<b.Y);
}

mytype getmin(mytype lef)
{
    lli i=0;
    mytype ans=0,cur;
    while(i<n&&lef>esp)
    {
        cur=min(lef,(mytype)t[i].Y);
        ans+=cur*t[i].X;
        lef-=cur;
        i++;
    }
    return ans;
}

mytype getmax(mytype lef)
{
    lli i=n-1;
    mytype ans=0,cur;
    while(i>=0&&lef>esp)
    {
        cur=min(lef,(mytype)t[i].Y);
        ans+=cur*t[i].X;
        lef-=cur;
        i--;
    }
    return ans;
}

bool poss(mytype sum)
{
    mytype mi=getmin(sum);
    mytype ma=getmax(sum);
    return mi-esp<=T*sum&&T*sum<=ma+esp;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    scanf(" %lld %lld",&n,&T);
    mytype l=0,r=0,m=0;
    fo(i,n)
    {
        scanf(" %lld",&in);
        a.pb(in);
        r+=in;
    }
    fo(i,n)
    {
        scanf(" %lld",&in);
        t.pb(mp(in,a[i]));
    }
    sort(t.begin(),t.end(),cmp);
    
    if(t[0].X==0)
    {
        lli ans=0;
        i=0;
        while(i<n&&t[i].X==0)
            ans+=t[i++].Y;
        cout<<ans;
        return 0;
    }

    if(t[n-1].X==0)
    {
        lli ans=0;
        i=n-1;
        while(i>=0&&t[i].X==0)
            ans+=t[i--].Y;
        cout<<ans;
        return 0;
    }
    
    lli itr=200;
    while(itr--)
    {
        m=(l+r)/2;
        if(poss(m))
            l=m;
        else
            r=m;
    }
    cout<<fixed<<setprecision(30)<<r<<endl;
    return 0;
}