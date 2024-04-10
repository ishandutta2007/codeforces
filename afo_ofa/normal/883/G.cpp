#include<bits/stdc++.h>
using namespace std;

int n,m,st;
struct R{
	int to,nex,id,dir;
}r[606000];
int hea[303000],cnt=1,used[303000],die[606000];
vector<int>uu,vv;
int s1[303000];
string s2;int an1=0,an2=0;

void ddd(int x){
	used[x]=1; an2++;
	int y; 
	for (int i=hea[x];i>0;i=r[i].nex) if (r[i].id==-1){
		y=r[i].to;
		if (!used[y]) ddd(y);
	}
}

void dfs(int x){
	used[x]=1; an1++;
	int y;
	for (int i=hea[x];i>0;i=r[i].nex){
		y=r[i].to; if (used[y]) continue;
		if (~r[i].id){
			if (die[i]) continue;
			s1[r[i].id]=r[i].dir;
			die[i]=die[i^1]=1;
		}
		dfs(y);
	}
}

int main(){
	scanf("%d%d%d",&n,&m,&st);
	int t,x,y;
	for (int i=1;i<=m;i++){
		scanf("%d%d%d",&t,&x,&y);
		if (t==1){
			r[++cnt]=(R){y,hea[x],-1,-1}; hea[x]=cnt;
			cnt++;
		}else{
			uu.push_back(x); vv.push_back(y);
			r[++cnt]=(R){y,hea[x],uu.size()-1,1}; hea[x]=cnt;
			r[++cnt]=(R){x,hea[y],uu.size()-1,0}; hea[y]=cnt;
		}
	}
	ddd(st);
	for (int i=0;i<(int)uu.size();i++){
		if (used[uu[i]]&&!used[vv[i]]) s2+='-';
		else s2+='+';
	}
	memset(used,0,sizeof used);
	dfs(st);
	
	printf("%d\n",an1); for (int i=0;i<(int)uu.size();i++) printf("%c",s1[i]?'+':'-');
	printf("\n%d\n",an2); cout<<s2;
}