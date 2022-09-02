#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;
#define ll long long

#define id pair<int, double>
#define ii pair<id, id>
#define di pair<double, ii>

void print(vector<ll> &a)
{
    for (int i = 0; i<a.size(); i++) cout<<a[i]<<' ';
    cout<<endl;
}

const ll p = 1e9 + 9;

struct node
{
    int count = 0;
    int bit = 0;
    int level = 0;
    bool check = false;
    node* bit0;
    node* bit1;
};

node* start = new node;

void add(ll p)
{
    bitset<28> a(p);
    node* kek = start;
    for (int i = 27; i>=0; i--)
    {
        kek->level = i;
        (kek->count)++;
        if (i!=0&&((kek->check)==false)) {kek->bit0 = new node; kek->bit0->bit = 0; kek->bit1 = new node; kek->bit1->bit = 1; kek->check = true;}
        if (i!=0)
        {
            if (a[i-1]==0) kek = kek->bit0;
            else kek = kek->bit1;
        }
    }
}

void del(ll p)
{
    bitset<28> a(p);
    node* kek = start;
    for (int i = 27; i>=0; i--)
    {
        (kek->count)--;
        if (i == 0) return;
        if (a[i-1]==0) kek = kek->bit0;
        else kek = kek->bit1;
    }
}

ll partial_solve(bitset<28> &P, bitset<28> &L, node* kek)
{
    if (kek->count==0) return 0;
    int i = kek->level;
    if ((P[i]^(kek->bit))<L[i]) return kek->count;
    if ((P[i]^(kek->bit))>L[i]) return 0;
    if (i==0) return 0;
    return partial_solve(P, L, kek->bit0) + partial_solve(P, L, kek->bit1);
}

ll solve(ll p, ll l)
{
    bitset<28> P(p);
    bitset<28> L(l);
    return partial_solve(P, L, start);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    start->bit = 0;
    
    int q;
    cin>>q;
    int t;
    for (int i = 0; i<q; i++)
    {
        cin>>t;
        if (t==1)
        {
            int p; cin>>p; add(p);
        }
        if (t==2)
        {
            int p; cin>>p; del(p);
        }
        if (t==3)
        {
            int p, l;
            cin>>p>>l;
            cout<<solve(p, l)<<endl;
        }
    }
}