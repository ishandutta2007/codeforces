#include<stdio.h>
#include<map>
#include<algorithm>
#define it register int
#define ct const int
#define il inline
using namespace std;
const int N=1000005;
int x[5],y[5];
map<int,int> mp;
int main(){
	scanf("%d%d",&x[1],&y[1]),mp[x[1]]=y[1];
	scanf("%d%d",&x[2],&y[2]),mp[x[2]]=y[2];
	scanf("%d%d",&x[3],&y[3]),mp[x[3]]=y[3];
	std::sort(x+1,x+1+3),std::sort(y+1,y+1+3);
	printf("%d\n",x[3]-x[1]+y[3]-y[1]+1);
	for(it i=x[1];i<x[2];++i) printf("%d %d\n",i,mp[x[1]]);
	for(it i=x[3];i>x[2];--i) printf("%d %d\n",i,mp[x[3]]);
	for(it i=y[1];i<=y[3];++i) printf("%d %d\n",x[2],i);
	return 0;
}