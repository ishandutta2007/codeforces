#include <cstdio>
#include <algorithm>
#include <utility>
#include <vector>
#include <stack>
#include <cstring>

using namespace std;

int n,m,oadj[401][401],adj[401][401],l,vis[401],chk[201];
char sn[201],str[201];

int get_node(int val,char ch) {
	if(ch=='V') return val;
	else return val+n;
}
int rev(int val) {
	if(val<n) return val+n;
	else return val-n;
}

stack<int> stk;
void dfs(int cur) {
	vis[cur]=1;
	for(int i=0;i<n*2;i++) if(adj[cur][i] && !vis[i]) dfs(i);
	stk.push(cur);
}
void rdfs(int cur,int g) {
	vis[cur]=g;
	for(int i=0;i<n*2;i++) if(adj[i][cur] && !vis[i]) rdfs(i,g);
}
bool proc(int idx,char ch) {
	for(int i=0;i<n*2;i++) for(int j=0;j<n*2;j++) adj[i][j] = oadj[i][j];
	for(int i=0;i<n;i++) if(chk[i]) {
		adj[rev(get_node(i,sn[str[i]-'a']))][get_node(i,sn[str[i]-'a'])]=1;
	}
	if(idx!=-1) adj[rev(get_node(idx,ch))][get_node(idx,ch)]=1;
	
	/*
	for(int i=0;i<n*2;i++) {
		for(int j=0;j<n*2;j++) printf("%d ",adj[i][j]);
		puts("");
	}
	*/

	while(!stk.empty()) stk.pop();
	fill(vis,vis+n+n,0);
	for(int i=0;i<n*2;i++) if(!vis[i]) dfs(i);
	fill(vis,vis+n+n,0);
	
	int g=1;
	while(!stk.empty()) {
		int cur=stk.top();stk.pop();
		if(!vis[cur]) rdfs(cur,g++);
	}
	for(int i=0;i<n;i++) if(vis[i]==vis[i+n]) return false;

	return true;
}
int main() {
	scanf("%s",sn);
	l=strlen(sn);
	scanf("%d%d",&n,&m);
	
	bool ccf=false, vvf=false;
	for(int i=0;i<l;i++) if(sn[i]=='C') ccf=true;
						else vvf=true;
	for(int i=0;i<m;i++) {
		int a,b;
		char ca,cb;
		scanf("%d %c %d %c",&a,&ca,&b,&cb);
		oadj[get_node(a-1,ca)][get_node(b-1,cb)] = 1;
		oadj[rev(get_node(b-1,cb))][rev(get_node(a-1,ca))] = 1;
		if((cb=='V'&&ca=='C'&&!vvf) || (cb=='C'&&ca=='V'&&!ccf)) {
			puts("-1");
			return 0;
		}
	}
	
	scanf("%s",str);
	for(int i=0;i<n;i++) chk[i] = 1;
	
	if(proc(-1,'A')) {
		puts(str);
		return 0;
	}
	

	for(int i=n-1;i>=0;i--) {
		chk[i]=0;
		bool f1=proc(i,'C'),f2=proc(i,'V');
		for(int j=str[i]-'a'+1;j<l;j++) if((vvf&&sn[j]=='V'&&f2)||(ccf&&sn[j]=='C'&&f1)) {
			str[i]=j+'a';
			chk[i]=1;

			char lc=-1,lv=-1;
			for(int k=0;k<l;k++){
				if(sn[k]=='C' && lc==-1) lc=k;
				else if(sn[k]=='V' && lv==-1) lv=k;
			}
			lc+='a'; lv+='a';
			for(int k=i+1;k<n;k++) {
				f1=proc(k,'C'), f2=proc(k,'V');
				if(ccf&&sn[0]=='C') {
					if(f1) str[k]=lc;
					else str[k]=lv;
				} else {
					if(f2) str[k]=lv;
					else str[k]=lc;
				}
				chk[k]=1;
			}
			printf("%s\n",str);
			return 0;
		}
	}
	puts("-1");
	
	return 0;
}