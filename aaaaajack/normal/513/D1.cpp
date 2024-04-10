#include<cstdio>
#include<vector>
#define N 110
using namespace std;
vector<int> gl[N],gr[N];
bool check[N][N];
bool first=true;
int can[N][N];
int f(int rt,int ed){
	if(check[rt][ed]) return can[rt][ed];
	check[rt][ed]=1;
	if(rt==ed) return can[rt][ed]=1;
	int i,j;
	bool flag;
	for(i=rt+1;i<=ed;i++){
		flag=true;
		for(j=0;j<gl[rt].size();j++){
			if(gl[rt][j]<=rt||gl[rt][j]>=i) flag=false;
		}
		for(j=0;j<gr[rt].size();j++){
			if(gr[rt][j]<i||gr[rt][j]>=ed) flag=false;
		}
		if(flag&&f(rt+1,i)&&f(i,ed)) return can[rt][ed]=i;
	}
	return can[rt][ed]=0;
}
void print(int rt,int ed){
	if(rt==ed) return;
	print(rt+1,can[rt][ed]);
	if(first) first=false;
	else putchar(' ');
	printf("%d",rt);
	print(can[rt][ed],ed);
}
int main(){
	char s[30];
	int n,m,a,b;
	scanf("%d%d",&n,&m);
	while(m--){
		scanf("%d%d%s",&a,&b,s);
		if(s[0]=='L') gl[a].push_back(b);
		else gr[a].push_back(b);
	}
	if(f(1,n+1)){
		print(1,n+1);
		putchar('\n');
	}
	else puts("IMPOSSIBLE");
	return 0;
}