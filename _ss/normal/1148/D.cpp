#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
const ll maxn=3e5+1;
struct ds
{
    int l,r,st;
};

vector<ds> a,b;

void read()
{
    int n,x,y;
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        scanf("%d %d",&x,&y);
        if (x>y) a.pb({x,y,i});
        else b.pb({x,y,i});
    }
}

bool cmp1(ds t1,ds t2)
{
    return t1.l<t2.l;
}

bool cmp2(ds t1,ds t2)
{
    return t1.l>t2.l;
}

void process()
{
    sort(a.begin(),a.end(),cmp1);
    sort(b.begin(),b.end(),cmp2);
    if (a.size()>b.size())
    {
        cout<<a.size()<<endl;
        for (int i=0;i<a.size();i++) cout<<a[i].st<<" ";
    }
    else
    {
        cout<<b.size()<<endl;
        for (int i=0;i<b.size();i++) cout<<b[i].st<<" ";
    }
}

int main()
{
    read();
    process();
    return 0;
}