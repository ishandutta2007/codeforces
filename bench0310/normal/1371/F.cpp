#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

struct obj
{
    int x=0,y=0;
    int sz=0;
    int tl=0,tr=0;
    int cntl=0,cntr=0;
    int vl=0,vr=0;
    int s=0;
    int flip=0;
    void ini(char c)
    {
        x=y=sz=1;
        tl=tr=(c=='>');
        cntl=cntr=1;
        vl=vr=1;
        s=1;
    }
    void chmax(int &a,int b){a=max(a,b);}
    void pull(obj &a,obj &b)
    {
        sz=a.sz+b.sz;
        tl=a.tl;
        cntl=(a.cntl+(a.cntl==a.sz&&b.tl==a.tl)*(b.cntl));
        tr=b.tr;
        cntr=(b.cntr+(b.cntr==b.sz&&a.tr==b.tr)*(a.cntr));
        s=a.s+b.s-(a.tr==b.tl);
        //vl
        vl=a.vl;
        if(a.s==1)
        {
            if(a.tr==b.tl) vl=a.sz+b.vl;
            else vl=a.sz+b.cntl;
        }
        else if(a.s==2&&a.tr==b.tl) vl=a.sz+b.cntl;
        //vr
        vr=b.vr;
        if(b.s==1)
        {
            if(a.tr==b.tl) vr=b.sz+a.vr;
            else vr=b.sz+a.cntr;
        }
        else if(b.s==2&&a.tr==b.tl) vr=b.sz+a.cntr;
        //x&y
        x=max(a.x,b.x);
        y=max(a.y,b.y);
        if(tl==1) chmax(x,vl);
        else chmax(y,vl);
        if(tr==0) chmax(x,vr);
        else chmax(y,vr);
        if(a.tr!=b.tl)
        {
            if(a.tr==1) chmax(x,a.cntr+b.cntl);
            else chmax(y,a.cntr+b.cntl);
        }
        else
        {
            if(a.tr==1)
            {
                chmax(y,a.vr+b.cntl);
                chmax(x,b.vl+a.cntr);
            }
            else
            {
                chmax(x,a.vr+b.cntl);
                chmax(y,b.vl+a.cntr);
            }
        }
    }
    void apply()
    {
        swap(x,y);
        tl^=1; tr^=1;
        flip^=1;
    }
    void push(obj &a,obj &b)
    {
        if(flip)
        {
            a.apply();
            b.apply();
            flip=0;
        }
    }
};

const int N=500005;
vector<obj> tree(4*N);
string s;

void build(int idx,int l,int r)
{
    if(l==r) tree[idx].ini(s[l]);
    else
    {
        int m=(l+r)/2;
        build(2*idx,l,m);
        build(2*idx+1,m+1,r);
        tree[idx].pull(tree[2*idx],tree[2*idx+1]);
    }
}

obj query(int idx,int l,int r,int ql,int qr)
{
    if(ql>qr) return obj();
    if(l==ql&&r==qr)
    {
        tree[idx].apply();
        return tree[idx];
    }
    int m=(l+r)/2;
    tree[idx].push(tree[2*idx],tree[2*idx+1]);
    obj one=query(2*idx,l,m,ql,min(qr,m));
    obj two=query(2*idx+1,m+1,r,max(ql,m+1),qr);
    tree[idx].pull(tree[2*idx],tree[2*idx+1]);
    if(qr<=m) return one;
    else if(m+1<=ql) return two;
    else
    {
        obj res;
        res.pull(one,two);
        return res;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,q;
    cin >> n >> q;
    cin >> s;
    s="$"+s;
    build(1,1,n);
    while(q--)
    {
        int l,r;
        cin >> l >> r;
        cout << query(1,1,n,l,r).x << "\n";
    }
    return 0;
}