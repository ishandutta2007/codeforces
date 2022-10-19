#include<bits/stdc++.h>
using namespace std;
struct Suffix_Automaton{
	int ch[26],mn,mx,len,fa;
	Suffix_Automaton(){mn=0x3f3f3f3f,mx=-1;}
}t[400100];
int cnt=1;
int Add(int x,int c){
	if(t[x].ch[c]){
		int y=t[x].ch[c];
		if(t[y].len==t[x].len+1)return y;//(x,c) has been added into the tree already.
		int yy=++cnt;t[yy]=t[y];
		t[yy].len=t[x].len+1,t[y].fa=yy;
		for(;x&&t[x].ch[c]==y;x=t[x].fa)t[x].ch[c]=yy;
		return yy;
	}
	int xx=++cnt;t[xx].len=t[x].len+1;
	for(;x&&!t[x].ch[c];x=t[x].fa)t[x].ch[c]=xx;
	if(!x){t[xx].fa=1;return xx;}
	int y=t[x].ch[c];
	if(t[y].len==t[x].len+1){t[xx].fa=y;return xx;}
	int yy=++cnt;t[yy]=t[y];
	t[yy].len=t[x].len+1;
	t[y].fa=t[xx].fa=yy;
	for(;x&&t[x].ch[c]==y;x=t[x].fa)t[x].ch[c]=yy;
	return xx;
}
vector<int>v[400100];
char s[100100];
int S;
void chmn(int &x,int y){if(y<x)x=y;}
void chmx(int &x,int y){if(y>x)x=y;}
void dfs(int x){for(auto y:v[x])dfs(y),chmn(t[x].mn,t[y].mn),chmx(t[x].mx,t[y].mx);}
struct dat{
	int x,y,z;
	dat(){x=y=z=0;}
	dat(int X,int Y,int Z){x=X,y=Y,z=Z;}
	friend bool operator<(const dat&p,const dat&q){return p.z<q.z;}
}bit[100100];
bool cmp(dat&p,dat&q){return p.x<q.x;}
void ADD(int x,dat d){
	x++;
	while(x)bit[x]=max(bit[x],d),x-=x&-x;
}
dat SUM(int x){
	x++;
	dat ret;
	while(x<=S)ret=max(ret,bit[x]),x+=x&-x;
	return ret;
}
vector<dat>p,q;
int rad[100100];
void Manacher(){
	int Rpos=-1,Centre=-1;
	for(int i=0;i<S;i++){
		if(i<Rpos)rad[i]=min(Rpos-i,rad[2*Centre-i]);
		while(i-rad[i]>=0&&i+rad[i]<S&&s[i-rad[i]]==s[i+rad[i]])rad[i]++;
		if(i+rad[i]>Rpos)Rpos=i+rad[i],Centre=i;
		q.push_back(dat(i-rad[i],i+rad[i],rad[i]*2-1));
	}
}
vector<int>rs;
int mx;
int main(){
	scanf("%s",s),S=strlen(s);
	for(int i=0,las=1;i<S;i++)chmn(t[las=Add(las,s[i]-'a')].mn,i);
	for(int i=S-1,las=1;i>=0;i--)chmx(t[las=Add(las,s[i]-'a')].mx,i);
	for(int i=2;i<=cnt;i++)v[t[i].fa].push_back(i);
	dfs(1);
	for(int i=1;i<=cnt;i++)if(t[i].mn<t[i].mx&&(t[i].mx+t[i].len==S))p.push_back(dat(t[i].mn,t[i].mx,t[i].len));
	Manacher();
	sort(p.begin(),p.end(),cmp),sort(q.begin(),q.end(),cmp);
	for(int i=0,j=0;i<q.size();i++){
		while(j<p.size()&&p[j].x<=q[i].x)ADD(p[j].y,p[j]),j++;
		if(mx<q[i].z)mx=q[i].z,rs={q[i].x+1,q[i].y-1};
		dat tmp=SUM(q[i].y);
		if(mx<q[i].z+2*tmp.z)mx=q[i].z+2*tmp.z,rs={tmp.x-tmp.z+1,tmp.x,q[i].x+1,q[i].y-1,tmp.y,tmp.y+tmp.z-1};
	}
	printf("%d\n",rs.size()/2);
	for(int i=0;i<rs.size();i+=2)printf("%d %d\n",rs[i]+1,rs[i+1]-rs[i]+1);
	return 0;
}