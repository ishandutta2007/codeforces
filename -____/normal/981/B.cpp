//CF 981B
#include<iostream>
#include<cstdio>
#include<fstream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<bitset>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef long long LL;
typedef double DB;
map<int,int> M;
map<int,int>::iterator it;
int main()
{
	int n,i,x,y;
	LL ans=0;
	scanf("%d",&n);
	for(i=1;i<=n;i=i+1){
		scanf("%d%d",&x,&y);
		if(M[x]<y)
			M[x]=y;
	}
	scanf("%d",&n);
	for(i=1;i<=n;i=i+1){
		scanf("%d%d",&x,&y);
		if(M[x]<y)
			M[x]=y;
	}
	for(it=M.begin();it!=M.end();it++)
		ans+=(*it).second;
	cout<<ans;
	return 0;
}