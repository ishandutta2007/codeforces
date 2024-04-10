#include <bits/stdc++.h>
#define eps 1e-8
#define pt pair<double,double>
#define x first
#define y second
using namespace std;
typedef double ld;

ld d(pt a, pt b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

pt a, b, t;

bool cmp1(pt f, pt s)
{
    return d(f,a)-d(f,t)<d(s,a)-d(s,t);
}

bool cmp2(pt f, pt s)
{
    return d(f,b)-d(f,t)<d(s,b)-d(s,t);
}

int main()
{
    //ifstream cin("input.txt");

    cin>>a.x>>a.y>>b.x>>b.y>>t.x>>t.y;
    int n;
    cin>>n;
    vector<pt> p(n);
    ld ans=0;
    for(int i=0; i<n; i++) { cin>>p[i].x>>p[i].y; ans+=2*d(t,p[i]); }
    ld d0=ans;
    ans+=min(d(a,t),d(b,t));
    vector<pt> p1=p,p2=p;
    sort(p1.begin(),p1.end(),cmp1);
    sort(p2.begin(),p2.end(),cmp2);
    ans=min(ans,min(d0-d(p1[0],t)+d(p1[0],a), d0-d(p2[0],t)+d(p2[0],b)));
    if(n!=1)
    {
        if(p1[0]!=p2[0]) ans=min(ans,d0-d(t,p1[0])-d(t,p2[0])+d(a,p1[0])+d(b,p2[0]));
        else ans=min(ans,min(d0-d(t,p1[0])-d(t,p2[1])+d(a,p1[0])+d(b,p2[1]),
                     d0-d(t,p1[1])-d(t,p2[0])+d(a,p1[1])+d(b,p2[0])));
    }
    cout.precision(6);
    cout<<fixed<<ans;
    return 0;
}