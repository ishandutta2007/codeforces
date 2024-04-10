#include<bits/stdc++.h>
using namespace std;
int n,m,q;
bool ans[600002];
char s[502][502];
bitset<502> bs[502][502];
struct aaa
{
	int sx,sy,ex,ey,id;
};
vector<aaa> vec;
inline void solve(int l,int r,vector<aaa> &vec)
{
	int mid=((l+r)>>1);
	vector<aaa> vl,vr;
	for(int i=l;i<=r;++i)for(int j=1;j<=m;++j)bs[i][j].reset();
	for(int i=m;i;--i)if(s[mid][i]=='.')bs[mid][i].set(i);
	for(int i=mid+1;i<=r;++i)for(int j=1;j<=m;++j)if(s[i][j]=='.')bs[i][j]=bs[i-1][j]|bs[i][j-1];
	for(int i=m;i;--i)if(s[mid][i]=='.')bs[mid][i]|=bs[mid][i+1];
	for(int i=mid-1;i>=l;--i)for(int j=m;j;--j)if(s[i][j]=='.')bs[i][j]=bs[i+1][j]|bs[i][j+1];
	for(int i=0;i<vec.size();++i)
	{
		if(vec[i].sx<mid && vec[i].ex<=mid)vl.push_back(vec[i]);
		else if(vec[i].sx>mid)vr.push_back(vec[i]);
		else ans[vec[i].id]=(bs[vec[i].sx][vec[i].sy]&bs[vec[i].ex][vec[i].ey]).count();
	}
	if(vl.size())solve(l,mid,vl);
	if(vr.size())solve(mid+1,r,vr);
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)scanf("%s",s[i]+1);
	scanf("%d",&q);
	for(int i=1,sx,sy,ex,ey;i<=q;++i)scanf("%d%d%d%d",&sx,&sy,&ex,&ey),vec.push_back((aaa){sx,sy,ex,ey,i});
	solve(1,n,vec);
	for(int i=1;i<=q;++i)puts(ans[i]? "Yes":"No");
	return 0;
}