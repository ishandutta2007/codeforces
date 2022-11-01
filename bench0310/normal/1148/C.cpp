#include <bits/stdc++.h>

using namespace std;
const int N=300005;

int n,arr[N],pos[N];
vector<pair<int,int> > v;

void swaps(int a,int b)
{
    if(a==b) return;
    int one=arr[a];
    int two=arr[b];
    arr[a]=two;
    arr[b]=one;
    pos[one]=b;
    pos[two]=a;
    v.push_back(make_pair(a,b));
}

void solve(int i)
{
    if(i<=n/2)
    {
        if(pos[i]>n/2) swaps(pos[i],1);
        swaps(pos[i],n);
        swaps(i,pos[i]);
    }
    else
    {
        if(pos[i]<=n/2) swaps(pos[i],n);
        swaps(pos[i],1);
        swaps(pos[i],i);
    }
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
    {
        scanf("%d",&arr[i]);
        pos[arr[i]]=i;
    }
    for(int i=1;i<=n/2;i++)
    {
        solve(n/2-i+1);
        solve(n/2+i);
    }
    printf("%d\n",v.size());
    for(int i=0;i<(int)v.size();i++) printf("%d %d\n",v[i].first,v[i].second);
	return 0;
}