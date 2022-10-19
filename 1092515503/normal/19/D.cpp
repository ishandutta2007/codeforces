#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
int n,val[200100],m;
set<pii>s[200100];
struct opt{
	int tp,x,y;
}q[200100];
inline void read(int &x){
	x=0;
	register char c=getchar();
	while(c>'9'||c<'0')c=getchar();
	while(c>='0'&&c<='9')x=(x<<3)+(x<<1)+(c^48),c=getchar();
}
inline void print(int x){
	if(x<=9)putchar('0'+x);
	else print(x/10),putchar('0'+x%10);
}
void ins(int x,pii k){
	while(x)s[x].insert(k),x-=x&-x;
} 
void del(int x,pii k){
	while(x)s[x].erase(k),x-=x&-x;
}
pii ask(int x,pii k){
	pii res=make_pair(0x3f3f3f3f,0x3f3f3f3f);
	while(x<=m)res=min(res,*s[x].lower_bound(k)),x+=x&-x;
	return res;
}
int main(){
	read(n);
	for(register int i=1;i<=n;i++){
		char str[10];
		scanf("%s",str),read(q[i].x),read(q[i].y);
		if(str[0]=='a')q[i].tp=1;
		if(str[0]=='r')q[i].tp=2;
		if(str[0]=='f')q[i].tp=3,q[i].x++,q[i].y++;
		val[++m]=q[i].y;
	}
	sort(val+1,val+m+1),m=unique(val+1,val+m+1)-val+1;
	for(int i=1;i<=m;i++)s[i].insert(make_pair(0x3f3f3f3f,0x3f3f3f3f));
	for(register int i=1;i<=n;i++){
		if(q[i].tp==1)ins(lower_bound(val+1,val+m,q[i].y)-val,make_pair(q[i].x,q[i].y));
		if(q[i].tp==2)del(lower_bound(val+1,val+m,q[i].y)-val,make_pair(q[i].x,q[i].y));
		if(q[i].tp==3){
			register pii tmp=ask(lower_bound(val+1,val+m,q[i].y)-val,make_pair(q[i].x,q[i].y));
			if(tmp==make_pair(0x3f3f3f3f,0x3f3f3f3f))putchar('-'),putchar('1'),putchar('\n');
			else print(tmp.first),putchar(' '),print(tmp.second),putchar('\n');
		}
	}
	return 0;
}