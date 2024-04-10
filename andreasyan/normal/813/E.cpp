#include <bits/stdc++.h>
using namespace std;
const int N=100005;

int n,k;
int a[N];

vector<int> v[N];

int b[N];

vector<int> t[N*4];
void bil(int tl,int tr,int pos)
{
    if(tl==tr)
    {
        t[pos].push_back(b[tl]);
        return;
    }
    int m=(tl+tr)/2;
    bil(tl,m,pos*2);
    bil(m+1,tr,pos*2+1);
    if(tl==1 && tr==6)
        cout<<"";
    int j=0;
    for(int i=0;i<t[pos*2].size();++i)
    {
        while(1)
        {
            if(j==t[pos*2+1].size())
                break;
            if(t[pos*2+1][j]<t[pos*2][i])
            {
                t[pos].push_back(t[pos*2+1][j]);
                ++j;
            }
            else
                break;
        }
        t[pos].push_back(t[pos*2][i]);
    }
    for(;j<t[pos*2+1].size();++j)
        t[pos].push_back(t[pos*2+1][j]);
}

int qry(int tl,int tr,int l,int r,int x,int pos)
{
    if(tl==l && tr==r)
    {
        /*for(int i=0;i<t[pos].size();++i)
            cout<<t[pos][i]<<' ';
        cout<<endl;*/
        return lower_bound(t[pos].begin(),t[pos].end(),x)-t[pos].begin();
    }
    int m=(tl+tr)/2;
    if(r<=m)
        return qry(tl,m,l,r,x,pos*2);
    if(l>m)
        return qry(m+1,tr,l,r,x,pos*2+1);
    return qry(tl,m,l,m,x,pos*2)+qry(m+1,tr,m+1,r,x,pos*2+1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin>>n>>k;
    for(int i=1;i<=n;++i)
    {
        cin>>a[i];
        v[a[i]].push_back(i);
    }
    for(int i=1;i<N;++i)
    {
        for(int j=0;j<v[i].size();++j)
        {
            if(j-k<0)
                b[v[i][j]]=-1;
            else
                b[v[i][j]]=v[i][j-k];
        }
    }
    bil(1,n,1);
    int q;
    cin>>q;
    int last=0;
    while(q--)
    {
        int x,y;
        cin>>x>>y;
        int l=((x+last)%n)+1;
        int r=((y+last)%n)+1;
        if(l>r)
            swap(l,r);
        last=qry(1,n,l,r,l,1);
        cout<<last<<endl;
    }
    return 0;
}