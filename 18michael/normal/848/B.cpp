#include<bits/stdc++.h>
#define Mx 200000
using namespace std;
int n,w,h;
int ansx[100002],ansy[100002];
struct aaa
{
	int x,y,t,id;
};
vector<aaa> vec[200002],vec1[200002];
inline bool cmp(aaa a,aaa b)
{
	return (a.x==b.x)? ((a.x==2)? (a.y>b.y):(a.y<b.y)):(a.x>b.x);
}
inline bool cmp1(aaa a,aaa b)
{
	return (a.x==b.x)? ((a.x==2)? (a.y>b.y):(a.y<b.y)):(a.x<b.x);
}
int main()
{
	scanf("%d%d%d",&n,&w,&h);
	for(int i=1,x,y,z;i<=n;++i)scanf("%d%d%d",&x,&y,&z),vec[y+(Mx>>1)-z].push_back((aaa){x,y,z,i}),vec1[y+(Mx>>1)-z].push_back((aaa){x,y,z,i});
	for(int i=1;i<=Mx;++i)
	{
		sort(vec[i].begin(),vec[i].end(),cmp),sort(vec1[i].begin(),vec1[i].end(),cmp1);
		for(int j=0;j<vec[i].size();++j)
		{
			if(vec1[i][j].x==1)ansx[vec[i][j].id]=vec1[i][j].y,ansy[vec[i][j].id]=h;
			else ansx[vec[i][j].id]=w,ansy[vec[i][j].id]=vec1[i][j].y;
		}
	}
	for(int i=1;i<=n;++i)printf("%d %d\n",ansx[i],ansy[i]);
	return 0;
}