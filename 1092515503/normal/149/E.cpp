#include<bits/stdc++.h>
using namespace std;
struct Suffix_Automaton{
	struct SAM{int ch[26],len,fa;}t[400100];
	int cnt;
	vector<int>v[400100];
	Suffix_Automaton(){cnt=1;}
	int Add(int x,int c){
		int xx=++cnt;t[xx].len=t[x].len+1;
		for(;x&&!t[x].ch[c];x=t[x].fa)t[x].ch[c]=xx;
		if(!x){t[xx].fa=1;return xx;}
		int y=t[x].ch[c];
		if(t[y].len==t[x].len+1){t[xx].fa=y;return xx;}
		int yy=++cnt;t[yy]=t[y],t[yy].len=t[x].len+1;
		t[xx].fa=t[y].fa=yy;
		for(;x&&t[x].ch[c]==y;x=t[x].fa)t[x].ch[c]=yy;
		return xx;
	}
	void fin(){
//		for(int i=1;i<=cnt;i++)for(int j=0;j<26;j++)if(t[i].ch[j])printf("%d %d %c\n",i,t[i].ch[j],'a'+j);puts("");
		for(int i=2;i<=cnt;i++)v[t[i].fa].push_back(i);
	}
}sam[2];
int mx[400100],mn[400100],pre[400100],suf[400100],q,res,S;
char s[200100];
void chmn(int &x,int y){if(y<x)x=y;}
void chmx(int &x,int y){if(y>x)x=y;}
void dfs0(int x){for(auto y:sam[0].v[x])dfs0(y),chmn(mn[x],mn[y]);}
void dfs1(int x){for(auto y:sam[1].v[x])dfs1(y),chmx(mx[x],mx[y]);}
int main(){
	memset(mn,0x3f,sizeof(mn)),memset(mx,-1,sizeof(mx));
	scanf("%s%d",s,&q),S=strlen(s);
	for(int i=0,las=1;i<S;i++)chmn(mn[las=sam[0].Add(las,s[i]-'A')],i);
	for(int i=S-1,las=1;i>=0;i--)chmx(mx[las=sam[1].Add(las,s[i]-'A')],i);
	sam[0].fin(),sam[1].fin();
	dfs0(1),dfs1(1);
	while(q--){
		scanf("%s",s),S=strlen(s);
		for(int i=0;i<S;i++)pre[i]=0x3f3f3f3f,suf[i]=-1;
		for(int i=0,x=1;i<S;i++)if(sam[0].t[x].ch[s[i]-'A'])x=sam[0].t[x].ch[s[i]-'A'],pre[i]=mn[x];else break;
		for(int i=S-1,x=1;i>=0;i--)if(sam[1].t[x].ch[s[i]-'A'])x=sam[1].t[x].ch[s[i]-'A'],suf[i]=mx[x];else break;
//		for(int i=0;i<S;i++)printf("%d ",pre[i]);puts("");
//		for(int i=0;i<S;i++)printf("%d ",suf[i]);puts("");
		for(int i=1;i<S;i++)if(pre[i-1]<suf[i]){res++;break;}
	}
	printf("%d\n",res);
	return 0;
}
/*
AABACAACABBABBBCBAABBBABABABBCBACABAAABBCCAAACBBAAACCBCAAAABBABBACBACCABAABABCCBCCBACCCABBACACABAAAACCACBAABACCCAABCBCCBACABABCBCBAABACABABBABCBBBBACCCBBBC
1
ABAAABBCBA
*/