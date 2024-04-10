#pragma comment(linker, "/STACK:16777216")
#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <set>
#include <cstdio>
#define mp make_pair
using namespace std;
const int N=200003;

int n,m;
set<int> a;
map<pair<int,int>,bool> k;
int c[N];
int ans[N];
void dfs(int x,int g)
{
    a.erase(x);
    c[x]=g;
	if(a.empty())
		return;
	for(int h=*a.begin();;)
    {
        if(k.find(mp(x,h))!=k.end())
		{
			set<int>::iterator hh=a.lower_bound(h+1);
			if(hh==a.end())
				break;
			h=*hh;
			continue;
		}
        dfs(h,g);
		set<int>::iterator hh=a.lower_bound(h);
		if(hh==a.end())
			break;
		h=*hh;
    }
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;++i)
        a.insert(i);
    for(int i=0;i<m;++i)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        k[make_pair(x,y)]=true;
        k[make_pair(y,x)]=true;
    }
    int ansn=0;
    for(int i=1;i<=n;++i)
        if(!c[i])
        {
            ++ansn;
            dfs(i,ansn);
        }
    for(int i=1;i<=n;++i)
        ans[c[i]]++;
    cout<<ansn<<endl;
    sort(ans+1,ans+ansn+1);
    for(int i=1;i<=ansn;++i)
        printf("%d ",ans[i]);
    cout<<endl;
    return 0;
}