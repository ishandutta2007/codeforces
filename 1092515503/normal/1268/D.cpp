/*
Criteria:
1.read the problem carefully; WRITE DOWN SPECIAL CONSTRAINTS when the problem is long;
2.consider special situations/constraints to get observations;
3.think of everything throughout before coding;
4.return to the initial list of notifications after coding.

CONSTRAINTS:

OBSERVATIONS:

OTHER NOTIFICATIONS:

THINK CAREFULLY AND CODE DETEMINEDLY!
*/
#include<bits/stdc++.h>
using namespace std;
typedef bitset<2010> bs;
int n,mn=0x3f3f3f3f,res;
bs g[2010],aug,vis;
char s[2010];
void flip(int x){for(int i=0;i<n;i++)g[i].flip(x),g[x].flip(i);}
vector<int>v;
void dfs(int x){
	vis.set(x);
	while(true){
		int y=(~(vis|g[x]))._Find_first();
		if(y>=n)break;
		dfs(y);
	}
	v.push_back(x);
}
bool check(){
	vis.reset(),v.clear();
	for(int i=0;i<n;i++)if(!vis.test(i))dfs(i);
	vis.reset();
	aug.reset();
	vis.set(v.back());
	while(vis!=aug){
		int x=(vis^aug)._Find_first();
		aug.set(x);
		vis|=g[x];
	}
	return vis.count()==n;
}
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%s",s);
		for(int j=0;j<n;j++)if(s[j]=='1')g[i].set(j);
	}
	if(check()){puts("0 1");return 0;}
	if(n>6){
		for(int i=0;i<n;i++){
			flip(i);
			res+=check();
			flip(i);
		}
		printf("1 %d\n",res);
		return 0;
	}
	for(int i=0;i<(1<<n);i++){
		if(__builtin_popcount(i)>mn)continue;
		for(int j=0;j<n;j++)if(i&(1<<j))flip(j);
		if(check()){
			if(mn==__builtin_popcount(i))res++;
			else mn=__builtin_popcount(i),res=1;
		}
		for(int j=0;j<n;j++)if(i&(1<<j))flip(j);
	}
	if(mn==0x3f3f3f3f){puts("-1");return 0;}
	for(int i=1;i<=mn;i++)res*=i;
	printf("%d %d\n",mn,res);
	return 0;
}