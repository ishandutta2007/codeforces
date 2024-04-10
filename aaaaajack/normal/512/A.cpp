#include<cstdio>
#include<vector>
#define N 150
#define M 26
using namespace std;
char s[N][N];
vector<int> g[M],stk;
bool in[M],out[M];
bool check(int now){
	in[now]=true;
	for(int i=0;i<g[now].size();i++){
		if(in[g[now][i]]){
			if(!out[g[now][i]]) return true;
		}
		else if(check(g[now][i])) return true;
	}
	out[now]=true;
	stk.push_back(now);
	return false;
}
int main(){
	int n,i,j;
	bool imp=false;
	scanf("%d",&n);
	for(i=0;i<n;i++) scanf("%s",s[i]);
	for(i=1;i<n;i++){
		for(j=0;s[i-1][j]&&s[i][j];j++){
			if(s[i-1][j]!=s[i][j]){
				g[s[i-1][j]-'a'].push_back(s[i][j]-'a');
				break;
			}
		}
		if(s[i][j]==0&&s[i-1][j]!=0){
			imp=true;
		}
	}
	for(i=0;i<26;i++){
		if(!out[i]){
			if(check(i)) imp=true;
		}
	}
	if(imp) puts("Impossible");
	else{
		for(i=stk.size()-1;i>=0;i--){
			putchar('a'+stk[i]);
		}
		putchar('\n');
	}
	return 0;
}