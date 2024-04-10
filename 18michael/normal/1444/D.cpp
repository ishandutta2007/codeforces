#include<cstdio>
#include<bitset>
#include<vector>
#include<algorithm>
using namespace std;
int h,v,t0,t1,sumh,sumv,nowx,nowy,Test_num;
int H[1002],V[1002];
bitset<1000002> bs[1002];
vector<int> vec[4];
inline void mv(int x,int y)
{
	printf("%d %d\n",nowx+=x,nowy+=y);
}
inline void solve()
{
	sumh=nowx=0,vec[0].clear(),vec[1].clear(),scanf("%d",&h);for(int i=1;i<=h;++i)scanf("%d",&H[i]),sumh+=H[i];
	sumv=nowy=0,vec[2].clear(),vec[3].clear(),scanf("%d",&v);for(int i=1;i<=v;++i)scanf("%d",&V[i]),sumv+=V[i];
	if(h!=v || (sumh&1) || (sumv&1))return (void)puts("No");
	bs[0].reset(),bs[0][0]=1;for(int i=1;i<=h;++i)bs[i]=(bs[i-1]|(bs[i-1]<<H[i]));if(!bs[h][sumh>>=1])return (void)puts("No");
	for(int i=h;i;--i)if(sumh>=H[i] && bs[i-1][sumh-H[i]])sumh-=H[i],vec[0].push_back(H[i]);else vec[1].push_back(H[i]);
	bs[0].reset(),bs[0][0]=1;for(int i=1;i<=v;++i)bs[i]=(bs[i-1]|(bs[i-1]<<V[i]));if(!bs[v][sumv>>=1])return (void)puts("No");
	for(int i=v;i;--i)if(sumv>=V[i] && bs[i-1][sumv-V[i]])sumv-=V[i],vec[2].push_back(V[i]);else vec[3].push_back(V[i]);
	puts("Yes"),sort(vec[0].begin(),vec[0].end()),sort(vec[1].begin(),vec[1].end()),sort(vec[2].begin(),vec[2].end()),sort(vec[3].begin(),vec[3].end());
	if(vec[0].size()>vec[1].size())swap(vec[0],vec[1]);if(vec[2].size()<vec[3].size())swap(vec[2],vec[3]);
	for(t0=vec[0].size()-1,t1=0;~t0;--t0,++t1)mv(vec[0][t0],0),mv(0,vec[2][t1]);
	for(t0=0,t1=vec[2].size()-1;t1>=(int)(vec[0].size());++t0,--t1)mv(-vec[1][t0],0),mv(0,vec[2][t1]);
	for(t0=vec[1].size()-1,t1=0;t1<vec[3].size();--t0,++t1)mv(-vec[1][t0],0),mv(0,-vec[3][t1]);
}
int main()
{
	scanf("%d",&Test_num);
	while(Test_num--)solve();
	return 0;
}