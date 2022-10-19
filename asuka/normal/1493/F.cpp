#include<bits/stdc++.h>
#define ll long long
#define N 1015
#define rep(i,a,n) for (int i=a;i<=n;i++)
#define per(i,a,n) for (int i=n;i>=a;i--)
#define inf 0x3f3f3f3f
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define fi first
#define se second
#define lowbit(i) ((i)&(-i))
#define VI vector<int>
using namespace std;
int n,m,low[N];
int ln,lm;
void init(){
	rep(i,1,1000) low[i] = i;
	rep(i,2,1000){
		for(int j = i;j <= 1000;j += i){
			low[j] = min(low[j],i);
		}
	}
}
int query(int h,int w,int i1,int j1,int i2,int j2){
	printf("? %d %d %d %d %d %d\n",h,w,i1,j1,i2,j2);
	fflush(stdout);
	int u; scanf("%d",&u);
	return u;
}
bool checkn(int nn,int d){
	if(nn == 2) return query(d,m,1,1,d+1,1);
	return query(d*(nn/2),m,1,1,(nn/2)*d+1,1)&&query(d*(nn/2),m,1,1,((nn/2)+1)*d+1,1);
}
bool checkm(int mm,int d){
	if(mm == 2) return query(n,d,1,1,1,d+1);
	return query(n,d*(mm/2),1,1,1,(mm/2)*d+1)&&query(n,d*(mm/2),1,1,1,((mm/2)+1)*d+1);
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d%d",&n,&m);
	init();
	// printf("%d %d %d\n",low[10],low[9],low[35]);
	ln = n;lm = m;
	for(int i = n;i > 1;i /= low[i]){
		if(checkn(low[i],ln/low[i])) ln /= low[i];
	}
	for(int i = m;i > 1;i /= low[i]){
		if(checkm(low[i],lm/low[i])) lm /= low[i];
	}
	// printf("%d %d\n",ln,lm);
	ln = n/ln; lm = m/lm;
	int cn,cm; cn = cm = 0;
	rep(i,1,ln) if(ln%i==0) cn++;
	rep(i,1,lm) if(lm%i==0) cm++;
	printf("! %d\n",cn*cm);
	fflush(stdout);
	return 0;
}