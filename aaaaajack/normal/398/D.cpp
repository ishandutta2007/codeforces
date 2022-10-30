#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
#define N 50010
#define S 1500
using namespace std;
struct{
	char tp;
	int op[2];
}qry[S];
struct edge{
	int x;
	int y;
	edge(int _x,int _y):x(_x),y(_y){}
};
bool on[N];
int cnt[N];
int num[N];
int ans[S];
vector<edge> pos,neg;
vector<int> nb[N];
vector<int> ask[N],ch[N];
vector<int> pg[N],ng[N];
void build(){
	memset(cnt,0,sizeof(cnt));
	for(int i=0;i<pos.size();i++){
		cnt[pos[i].x]+=on[pos[i].y];
		cnt[pos[i].y]+=on[pos[i].x];
	}
}
void refresh(int n){
	memset(num,0,sizeof(num));
	for(int i=0;i<pos.size();i++){
		pg[pos[i].x].push_back(pos[i].y);
	}
	for(int i=0;i<neg.size();i++){
		ng[neg[i].x].push_back(neg[i].y);
	}
	pos.clear();
	neg.clear();
	for(int i=1;i<=n;i++){
		for(int j=0;j<pg[i].size();j++) num[pg[i][j]]++;
		for(int j=0;j<ng[i].size();j++) num[ng[i][j]]--;
		for(int j=0;j<pg[i].size();j++){
			if(num[pg[i][j]]){
				pos.push_back(edge(i,pg[i][j]));
				num[pg[i][j]]=0;
			}
		}
		pg[i].clear();
		ng[i].clear();
	}
}
void fix(){
	for(int i=0;i<pos.size();i++){
		if(!ask[pos[i].x].empty()&&!ch[pos[i].y].empty()){
			for(int j=0;j<ask[pos[i].x].size();j++){
				for(int k=0;k<ch[pos[i].y].size();k++){
					int an=ask[pos[i].x][j],cn=ch[pos[i].y][k];
					if(cn>an) break;
					if(qry[cn].tp=='O') ans[an]++;
					else ans[an]--;
				}
			}
		}
		if(!ask[pos[i].y].empty()&&!ch[pos[i].x].empty()){
			for(int j=0;j<ask[pos[i].y].size();j++){
				for(int k=0;k<ch[pos[i].x].size();k++){
					int an=ask[pos[i].y][j],cn=ch[pos[i].x][k];
					if(cn>an) break;
					if(qry[cn].tp=='O') ans[an]++;
					else ans[an]--;
				}
			}
		}
	}
}
void fix_edge(int s,int e,int sign){
	for(int i=s+1;i<=e;i++){
		if(qry[i].tp=='O') on[qry[i].op[0]]=1;
		else if(qry[i].tp=='F') on[qry[i].op[0]]=0;
		else if(qry[i].tp=='C'){
			if(qry[i].op[0]==qry[s].op[0]){
				ans[i]+=sign*on[qry[s].op[1]];
			}
			else if(qry[i].op[0]==qry[s].op[1]){
				ans[i]+=sign*on[qry[s].op[0]];
			}
		}
	}
	for(int i=e;i>s;i--){
		if(qry[i].tp=='O') on[qry[i].op[0]]=0;
		else if(qry[i].tp=='F') on[qry[i].op[0]]=1;
	}
}
int main(){
	int n,m,q,i,j,k,x,y,o;
	scanf("%d%d%d",&n,&m,&q);
	scanf("%d",&o);
	while(o--){
		scanf("%d",&x);
		on[x]=1;
	}
	while(m--){
		scanf("%d%d",&x,&y);
		if(x>y) swap(x,y);
		pos.push_back(edge(x,y));
	}
	build();
	for(i=0;i<q;i++){
		scanf(" %c",&qry[i%S].tp);
		if(qry[i%S].tp=='O'||qry[i%S].tp=='F'||qry[i%S].tp=='C'){
			scanf("%d",&qry[i%S].op[0]);
		}
		else{
			scanf("%d%d",&qry[i%S].op[0],&qry[i%S].op[1]);
			if(qry[i%S].op[0]>qry[i%S].op[1]) swap(qry[i%S].op[0],qry[i%S].op[1]);
		}
		if(i%S==S-1||i==q-1){
			for(j=0;j<=i%S;j++){
				if(qry[j].tp=='O'||qry[j].tp=='F'){
					ch[qry[j].op[0]].push_back(j);
				}
				else if(qry[j].tp=='C'){
					ask[qry[j].op[0]].push_back(j);
					ans[j]=cnt[qry[j].op[0]];
				}
			}
			fix();
			for(j=0;j<=i%S;j++){
				if(qry[j].tp=='O') on[qry[j].op[0]]=1,ch[qry[j].op[0]].clear();
				else if(qry[j].tp=='F') on[qry[j].op[0]]=0,ch[qry[j].op[0]].clear();
				else if(qry[j].tp=='A'){
					pos.push_back(edge(qry[j].op[0],qry[j].op[1]));
					fix_edge(j,i%S,1);
				}
				else if(qry[j].tp=='D'){
					neg.push_back(edge(qry[j].op[0],qry[j].op[1]));
					fix_edge(j,i%S,-1);
				}
				else{
					printf("%d\n",ans[j]);
					ask[qry[j].op[0]].clear();
				}
			}
			refresh(n);
			build();
		}
	}
	return 0;
}