#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <cstdio>
using namespace std;
const int N=300003,m=31;

int n;
int a[N],p[N];

vector<bool> ta[N],tp[N];
void erkp(int i)
{
    int x=p[i];
    while(x)
    {
        tp[i].push_back(x%2);
        x/=2;
    }
    while(tp[i].size()<m)
    {
        tp[i].push_back(0);
    }
    reverse(tp[i].begin(),tp[i].end());
}
void erka(int i)
{
    int x=a[i];
    while(x)
    {
        ta[i].push_back(x%2);
        x/=2;
    }
    while(ta[i].size()<m)
    {
        ta[i].push_back(0);
    }
    reverse(ta[i].begin(),ta[i].end());
}

int z;
int b[N*m][2];
int h[N*m][2];
vector<bool> v;
void ad(int i,int pos)
{
    if(i==m)
        return;
    if(!b[pos][v[i]])
        b[pos][v[i]]=++z;
    h[pos][v[i]]++;
    ad(i+1,b[pos][v[i]]);
}
/*void rem(int i,int pos)
{
    if(i==m)
        return;
    h[pos][v[i]]++;
    rem(i+1,b[pos][v[i]]);
}*/
vector<bool> ans;
void qry(int i,int pos)
{
	if(i==m)
		return;
    if(v[i]==0)
    {
        if(h[pos][0])
        {
			h[pos][0]--;
            ans.push_back(0);
            qry(i+1,b[pos][0]);
        }
        else
        {
			h[pos][1]--;
            ans.push_back(1);
            qry(i+1,b[pos][1]);
        }
    }
    else
    {
        if(h[pos][1])
        {
			h[pos][1]--;
            ans.push_back(0);
            qry(i+1,b[pos][1]);
        }
        else
        {
			h[pos][0]--;
            ans.push_back(1);
            qry(i+1,b[pos][0]);
        }
    }
}

int main()
{
    cin>>n;
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
        erka(i);
    }
    for(int i=0;i<n;++i)
    {
        cin>>p[i];
        erkp(i);
    }
    for(int i=0;i<n;++i)
    {
        v=tp[i];
        ad(0,0);
    }
    for(int i=0;i<n;++i)
    {
        v=ta[i];
        ans.clear();
        qry(0,0);
        //rem(0,0);
        int t=0;
        for(int j=m-1;j>=0;--j)
            t+=((1<<(m-j-1))*(ans[j]));
        cout<<t<<' ';
    }
    cout<<endl;
    return 0;
}