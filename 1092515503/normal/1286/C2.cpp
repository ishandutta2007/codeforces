#include<bits/stdc++.h>
using namespace std;
int n,c[110][26],S,to[3][110];
char s[110],t[110],id[3][110];
void query(int tp,int l,int r){
	if(l>r)return;
	printf("? %d %d\n",l,r),fflush(stdout);
	int len=(r-l+1);
	for(int i=1;i<=len*(len+1)/2;i++){
		scanf("%s",s),S=strlen(s);
		if(S<=((len+1)>>1))for(int j=0;j<S;j++)c[S][s[j]-'a']++;
	}
	for(int i=0;i<26;i++)for(int j=(len+1)>>1;j;j--)c[j][i]-=c[j-1][i];
	for(int i=0;i<26;i++)for(int j=1;j<=((len+1)>>1);j++)c[j][i]-=c[j+1][i];
	if(len&1)for(int j=0;j<26;j++)if(c[(len+1)>>1][j]){t[(l+r)>>1]='a'+j;break;}
	for(int j=len>>1;j;j--){
		vector<int>v;
		for(int i=0;i<26;i++)while(c[j][i])v.push_back(i),c[j][i]--;
//		printf("%d+%d=%c+%c\n",l+j-1,r-j+1,v[0]+'a',v[1]+'a');
		to[tp][l+j-1]=r-j+1,to[tp][r-j+1]=l+j-1;
		id[tp][l+j-1]=v[0]+'a',id[tp][r-j+1]=v[1]+'a';
	}
	memset(c,0,sizeof(c));
}
queue<int>q;
void bfs(){
	while(!q.empty()){
		int x=q.front();q.pop();
		for(int i=0;i<2;i++){
			if(to[i][x]==-1)continue;
			if(t[to[i][x]])continue;
			if(t[x]==id[i][x])t[to[i][x]]=id[i][to[i][x]];
			else t[to[i][x]]=id[i][x];
			q.push(to[i][x]);
		}
	}
} 
int main(){
	scanf("%d",&n);
	int p=n/3+1;
	memset(to,-1,sizeof(to));
	query(0,p,n),query(1,p,n-1);
	q.push((p+n)>>1),bfs();
	query(2,1,(p-1)<<1);
	for(int i=1;i<p;i++){
		if(t[to[2][i]]==id[2][i])t[i]=id[2][to[2][i]];
		else t[i]=id[2][i];
	}
	printf("! %s\n",t+1);
	return 0;
}