#include<cstdio>
#include<cctype>
#include<cstring>
#define Q 1000000007
#define S 510
using namespace std;
int tmp[1<<16];
int to[8][16];
struct node{
	node():lc(NULL),rc(NULL){memset(num,0,sizeof(num));}
	int num[1<<16];
	int val;
	node *lc,*rc;
	void build(int x,int coe,int *a){
		for(int j=0;j<16;j++){
			for(int i=0;i<(1<<16);i++){
				if((i&(1<<j))==(x<<j)){
					a[i]+=coe*a[i^(1<<j)];
					if(a[i]>=Q) a[i]-=Q;
					else if(a[i]<0) a[i]+=Q;
				}
			}
		}
	}
	void merge(int x){
		memset(tmp,0,sizeof(tmp));
		build(x,1,lc->num);
		build(x,1,rc->num);
		for(int i=0;i<65536;i++){
			tmp[i]=1LL*lc->num[i]*rc->num[i]%Q;
		}
		build(x,-1,tmp);
		build(x,-1,lc->num);
		build(x,-1,rc->num);
		for(int i=0;i<65536;i++){
			num[i]+=tmp[i];
			if(num[i]>=Q) num[i]-=Q;
		}
	}
	void add(int x){
		int res=0;
		for(int j=0;j<16;j++){
			res|=to[x][j]<<j;
		}
		num[res]++;
	}
};
char s[S];
int parse_tree(node *rt,int now){
	if(s[now]=='('){
		now++;
		rt->lc=new node();
		now=parse_tree(rt->lc,now);
		now++;
		if(s[now]=='?') rt->val=-1;
		else if(s[now]=='|') rt->val=1;
		else rt->val=0;
		now++;
		now++;
		rt->rc=new node();
		now=parse_tree(rt->rc,now);
		now++;
		return now;
	}
	else{
		if(s[now]=='?') rt->val=8;
		else if(isupper(s[now])) rt->val=4+(s[now]-'A');
		else rt->val=s[now]-'a';
		return now+1;
	}
}
void solve(node *rt){
	if(rt->lc){
		solve(rt->lc);
		solve(rt->rc);
		if(rt->val==-1){
			rt->merge(0);
			rt->merge(1);
		}
		else rt->merge(rt->val);
	}
	else{
		if(rt->val==8){
			for(int i=0;i<8;i++) rt->add(i);
		}
		else rt->add(rt->val);
	}
}
int main(){
	for(int i=0;i<8;i++){
		for(int j=0;j<16;j++){
			if(j&(1<<i%4)) to[i][j]=i>=4;
			else to[i][j]=i<4;
		}
	}
	scanf("%s",s);
	node *rt=new node();
	parse_tree(rt,0);
	solve(rt);
	int m,match[16],ans=0;
	scanf("%d",&m);
	for(int i=0;i<16;i++) match[i]=-1;
	for(int i=0;i<m;i++){
		int res=0,x;
		for(int j=0;j<4;j++){
			scanf("%d",&x);
			res|=x<<j;
		}
		scanf("%d",&x);
		match[res]=x<<res;
	}
	for(int i=0;i<65536;i++){
		bool flag=true;
		for(int j=0;j<16;j++){
			if(match[j]==-1) continue;
			if((i&(1<<j))!=match[j]){
				flag=false;
				break;
			}
		}
		if(flag){
			ans+=rt->num[i];
			if(ans>=Q) ans-=Q;
		}
	}
	printf("%d\n",ans);
	return 0;
}