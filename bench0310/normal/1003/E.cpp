#include <bits/stdc++.h>

using namespace std;

int n,d,k;
int idx=1;
vector<pair<int,int>> res;

void solve(int v,int depth,int lim,int degree)
{
    if(idx==n+1) return;
    if(depth>=lim) return;
    for(int i=0;i<(k-degree)&&idx<=n;i++)
    {
        res.push_back(make_pair(v,idx));
        idx++;
        solve(idx-1,depth+1,lim,1);
    }
}

int main()
{
	scanf("%d%d%d",&n,&d,&k);
	d++;
	if(d>2&&k==1)
    {
        printf("NO\n");
        return 0;
    }
    for(int i=1;i<d;i++) res.push_back(make_pair(i,i+1));
    idx=d+1;
    for(int i=2;i<=d-1;i++) solve(i,0,min(i-1,d-i),2);
    if((int)res.size()==n-1)
    {
        printf("YES\n");
        for(int i=0;i<n-1;i++) printf("%d %d\n",res[i].first,res[i].second);
    }
    else printf("NO\n");
	return 0;
}