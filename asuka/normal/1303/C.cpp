#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<bitset>
#include<queue>
#include<cstdlib>
#include<cmath>
#include<set>
#include<list>
#include<deque>
#include<map>
#define ll long long
#define N 205
using namespace std;
int t,du[26];
char s[N]; 
bool vis[26][26],used[26];
vector<int> a[26],ans;
void dfs(int u){
	used[u] = 1;
	ans.push_back(u);
	for(int i = 0;i < a[u].size();++i){
		int v = a[u][i];
		if(!used[v]) dfs(v);
	}
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%s",s);
		int l = strlen(s);
		memset(vis,0,sizeof(vis));
		memset(used,0,sizeof(used));
		memset(du,0,sizeof(du));
		ans.clear();
		for(int i = 0;i <= 25;++i) a[i].clear();
		for(int i = 1;i < l;++i){
			int t1 = s[i]-'a',t2 = s[i-1]-'a';
			if(!vis[t1][t2]) a[t1].push_back(t2),a[t2].push_back(t1),du[t1]++,du[t2]++;
			vis[t1][t2] = vis[t2][t1] = 1;
		}
		//for(int i = 0;i < 26;++i) printf("%d",du[i]);
	//	puts("");
		for(int i = 0;i <= 25;++i){
			if(du[i]==0) ans.push_back(i);
			if(du[i]==1&&!used[i]) dfs(i);
			if(du[i]>2){
			//	cout << "du > 2" << endl;
				goto tag;
			}
		 	//for(int i = 0;i < ans.size();++i) printf("%c",ans[i]+'a');
		//	puts("");
		}
		if(ans.size() != 26) goto tag; 
		puts("YES");
		for(int i = 0;i <= 25;++i) printf("%c",ans[i]+'a');
		puts("");
		continue;
		tag: puts("NO");
	}
    return 0;
}