#include<bits/stdc++.h>
#define Mx 100000000
using namespace std;
vector<int> vec,vecx,vecy;
inline int query(int x,int y)
{
	int t;
	printf("0 %d %d\n",x,y),fflush(stdout),scanf("%d",&t);
	return t;
}
inline void solve(int l,int r)
{
	if(l>r)return ;
	int mid=((l+r)>>1),t=query(mid,mid);
	if(!t)vec.push_back(mid),solve(l,mid-1),solve(mid+1,r);
	else
	{
		if(mid-t>=l && !query(mid-t,mid-t))vec.push_back(mid-t),solve(l,mid-t-1),solve(mid+t,r);
		else
		{
			solve(l,mid-t-1);
			if(mid+t<=r)vec.push_back(mid+t),solve(mid+t+1,r);
		}
	}
}
int main()
{
	solve(-Mx,Mx),sort(vec.begin(),vec.end());
	for(int i=0;;++i)
		if(vec[i]!=i-Mx)
		{
			for(int j=0;j<vec.size();++j)
			{
				if(!query(vec[j],i-Mx))vecx.push_back(vec[j]);
				if(!query(i-Mx,vec[j]))vecy.push_back(vec[j]);
			}
			break;
		}
	printf("1 %d %d\n",vecx.size(),vecy.size());
	for(int i=0;i<vecx.size();++i)printf("%d ",vecx[i]);puts("");
	for(int i=0;i<vecy.size();++i)printf("%d ",vecy[i]);
	return 0;
}