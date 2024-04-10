#include<cstdio>
#include<ctime>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<string>
#include<cstring>
#define rg register
#define il inline
#define vd void
#define ll long long
#define For(i,j,k)  for(ll i=j;i<=k;++i)
#define Dow(i,j,k)  for(ll i=k;i>=j;--i)
using namespace std;
il ll max(ll x,ll y){return x>y?x:y;}
il ll min(ll x,ll y){return x<y?x:y;}
il ll read(){
    ll x=0;int ch=getchar(),f=1;
    while (!isdigit(ch)&&(ch!='-')&&(ch!=EOF)) ch=getchar();
    if (ch=='-'){f=-1;ch=getchar();}
    while (isdigit(ch)){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
    return x*f;
}
il vd write(ll x){if(x<0) {putchar('-');write(-x);return;}if(x>=10)    write(x/10);putchar(x%10+'0');}
il vd writeln(ll x){write(x);puts("");}
il vd write_p(ll x){write(x);putchar(' ');}
ll n,x1,x2,tep;
struct node{
	ll v,num;
}a[500001];
bool f;
il bool cmp(node x,node y){return x.v<y.v;}
il vd Solve(){
	tep=0;
	Dow(i,1,n)
		if(a[i].v*(n-i+1)>=x1){
			tep=i;
			break;
		}
	Dow(i,1,tep-1){
		if(a[i].v*(tep-i)>=x2){
			puts("Yes");
			if(f==1){
				write_p(tep-i),writeln(n-tep+1);
				For(j,i,tep-1) write_p(a[j].num);puts("");
				For(j,tep,n) write_p(a[j].num);puts("");
				exit(0);
			}
			else{
				write_p(n-tep+1);writeln(tep-i);
				For(j,tep,n) write_p(a[j].num);puts("");
				For(j,i,tep-1) write_p(a[j].num);puts("");
				exit(0);
			}
		}
	}
}
int main(){
	n=read(),x1=read(),x2=read();
	For(i,1,n) a[i].v=read(),a[i].num=i;
	sort(a+1,a+n+1,cmp);
	Solve();
	swap(x1,x2);f=1;
	Solve();
	puts("No");
}