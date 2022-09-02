#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;
#define ll long long


void print(vector<ll> &a)
{
    for (int i = 0; i<a.size(); i++) cout<<a[i]<<' ';
    cout<<endl;
}

const ll q = 1e9 + 7;

map<ll, ll> p;
map<ll, ll> val;
map<ll, ll> s;

void g(int i)
{
    cout<<i<<" : "<<p[i]<<' '<<val[i]<<endl;    
}


void make_set(ll v)
{
    if (p.find(v)!=p.end()) return;
    p[v] = v;
    val[v] = 0;
    s[v] = 1;
}

void upd(ll v)
{
    if (p[v]==v) return;
    upd(p[v]);
    val[v] = val[v]^val[p[v]];
    p[v] = p[p[v]];
}

void union_set(ll l, ll r, ll v)
{
    l--;
    make_set(l);
    make_set(r);
    upd(l);
    upd(r);
    //cout<<"Connected "<<l<<' '<<r<<" with "<<v<<endl;
    ll l1 = p[l];
    ll r1 = p[r];
    if (l1==r1) return;
    if (s[l1]<s[r1]) swap(l1, r1);
    s[l1]+=s[r1];
    p[r1] = l1;
    val[r1] = (val[r]^val[l])^v;
}

ll solve(ll l, ll r)
{
    l--;
    //cout<<"Try to connect "<<l<<' '<<r<<endl;
    if (p.find(l)==p.end()) return -1;
    if (p.find(r)==p.end()) return -1;
    upd(l);
    upd(r);
    ll l1 = p[l];
    ll r1 = p[r];
    if (l1!=r1) return -1;
    return val[l]^val[r];
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);    
    int q;
    cin>>q;
    
    ll last = 0;
    ll t;
    for (int i = 0; i<q; i++)
    {
       cin>>t;
       if (t==1)
       {
           ll l, r, x;
           cin>>l>>r>>x;
           l^=last;
           r^=last;
           x^=last;
           if (l>r) swap(l, r);
           union_set(l, r, x);
      //     g(l-1);
        //   g(r);
       }
       if (t==2)
       {
           ll l, r;
           cin>>l>>r;
           l^=last;
           r^=last; 
           if (l>r) swap(l, r);
           last = solve(l, r);
           cout<<last<<endl;
           if (last==-1) last = 1;
       }
       /*if (i>7)     
       {
       cout<<endl; for (int i = 0; i<=3; i++) cout<<i<<" : "<<p[i]<<' '<<val[i]<<endl;
       cout<<endl;}*/
    }

    
}