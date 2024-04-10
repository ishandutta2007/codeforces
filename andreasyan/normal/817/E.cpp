#include <bits/stdc++.h>
using namespace std;
const int N=6000006;

vector<int> v;
void bil(int x)
{
    v.clear();
    while(x)
    {
        v.push_back(x%2);
        x/=2;
    }
    while(v.size()<31)
        v.push_back(0);
    reverse(v.begin(),v.end());
}

vector<int> v1;
void bil1(int x)
{
    v1.clear();
    while(x)
    {
        v1.push_back(x%2);
        x/=2;
    }
    while(v1.size()<31)
        v1.push_back(0);
    reverse(v1.begin(),v1.end());
}

int z;
int t[N];
int h[N][2];

void add(int i,int pos)
{
    if(i==v.size())
    {
        t[pos]++;
        return;
    }
    if(!h[pos][v[i]])
        h[pos][v[i]]=++z;
    add(i+1,h[pos][v[i]]);
    t[pos]=0;
    if(h[pos][0])
        t[pos]+=t[h[pos][0]];
    if(h[pos][1])
        t[pos]+=t[h[pos][1]];
}

void rem(int i,int pos)
{
    if(i==v.size())
    {
        t[pos]--;
        return;
    }
    if(!h[pos][v[i]])
        h[pos][v[i]]=++z;
    rem(i+1,h[pos][v[i]]);
    t[pos]=0;
    if(h[pos][0])
        t[pos]+=t[h[pos][0]];
    if(h[pos][1])
        t[pos]+=t[h[pos][1]];
}

int qry(int i,int pos)
{
    if(i==v.size())
        return 0;
    if(!h[pos][0])
        h[pos][0]=++z;
    if(!h[pos][1])
        h[pos][1]=++z;
    if(v1[i]==1)
        return t[h[pos][v[i]]]+qry(i+1,h[pos][v[i]^1]);
    else
        return qry(i+1,h[pos][v[i]]);
}

int main()
{
    int q;
    cin>>q;
    while(q--)
    {
        int tt;
        cin>>tt;
        if(tt==1)
        {
            int p;
            cin>>p;
            bil(p);
            add(0,0);
        }
        else if(tt==2)
        {
            int p;
            cin>>p;
            bil(p);
            rem(0,0);
        }
        else
        {
            int p,l;
            cin>>p>>l;
            bil(p);
            bil1(l);
            cout<<qry(0,0)<<endl;
        }
    }
    return 0;
}