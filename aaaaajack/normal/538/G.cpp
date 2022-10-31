#include<cstdio>
#include<algorithm>
#define L 2000100
#define N 200100
using namespace std;
int l;
struct shot{
	long long x;
	long long y;
	long long t;
	bool operator<(shot rhs)const{return t%l<rhs.t%l;}
}a[N];
inline long long downdiv(long long n,long long d){
	if(n<0&&n%d) return n/d-1;
	else return n/d;
}
inline long long updiv(long long n,long long d){
	if(n%d==0||n<0) return n/d;
	else return n/d+1;
}
char s[L];
int main(){
	int n,i,j,k,d,st,et;
	long long xpy[2],xmy[2];
	long long mx,my,tx,ty,r;
	bool wrong=false;
	scanf("%d%d",&n,&l);
	xpy[1]=xmy[1]=l;
	xpy[0]=xmy[0]=-l;
	for(i=1;i<=n;i++){
		scanf("%I64d%I64d%I64d",&a[i].t,&a[i].x,&a[i].y);
		if((a[i].t+a[i].x+a[i].y)&1) wrong=true;
	}
	sort(a+1,a+n+1);
	for(i=1;i<=n;i++){
		d=a[i].t%l-a[i-1].t%l;
		r=a[i].t/l-a[i-1].t/l;
		mx=a[i].x-a[i-1].x;
		my=a[i].y-a[i-1].y;
		if(r==0){
			if(abs(mx)+abs(my)>d) wrong=true;
		}
		else if(r>0){
			xpy[0]=max(xpy[0],updiv(mx+my-d,r));
			xpy[1]=min(xpy[1],downdiv(mx+my+d,r));
			xmy[0]=max(xmy[0],updiv(mx-my-d,r));
			xmy[1]=min(xmy[1],downdiv(mx-my+d,r));
		}
		else{
			xpy[0]=max(xpy[0],updiv(-mx-my-d,-r));
			xpy[1]=min(xpy[1],downdiv(-mx-my+d,-r));
			xmy[0]=max(xmy[0],updiv(-mx+my-d,-r));
			xmy[1]=min(xmy[1],downdiv(-mx+my+d,-r));
		}
	}
	d=l-a[n].t%l;
	r=a[n].t/l+1;
	mx=a[n].x;
	my=a[n].y;
	if(r==0){
		if(abs(mx)+abs(my)>d) wrong=true;
	}
	else if(r>0){
		xpy[0]=max(xpy[0],updiv(mx+my-d,r));
		xpy[1]=min(xpy[1],downdiv(mx+my+d,r));
		xmy[0]=max(xmy[0],updiv(mx-my-d,r));
		xmy[1]=min(xmy[1],downdiv(mx-my+d,r));
	}
	else{
		xpy[0]=max(xpy[0],updiv(-mx-my-d,-r));
		xpy[1]=min(xpy[1],downdiv(-mx-my+d,-r));
		xmy[0]=max(xmy[0],updiv(-mx+my-d,-r));
		xmy[1]=min(xmy[1],downdiv(-mx+my+d,-r));
	}
	if((xpy[0]+l)&1){
		if(xpy[0]<xpy[1]) xpy[0]++;
		else wrong=true;
	}
	if((xmy[0]+l)&1){
		if(xmy[0]<xmy[1]) xmy[0]++;
		else wrong=true;
	}
	if(wrong||xpy[0]>xpy[1]||xmy[0]>xmy[1]){
		puts("NO");
	}
	else{
		tx=(xmy[0]+xpy[0])/2;
		ty=(xpy[0]-xmy[0])/2;
		for(i=1;i<=n;i++){
			st=a[i-1].t%l;
			et=a[i].t%l;
			mx=(a[i].x-a[i].t/l*tx)-(a[i-1].x-a[i-1].t/l*tx);
			my=(a[i].y-a[i].t/l*ty)-(a[i-1].y-a[i-1].t/l*ty);
			for(j=st;j<et;j++){
				if(mx>0) putchar('R'),mx--;
				else if(mx<0) putchar('L'),mx++;
				else if(my>0) putchar('U'),my--;
				else if(my<0) putchar('D'),my++;
				else{
					putchar('L');
					putchar('R');
					j++;
				}
			}
		}
		st=a[n].t%l;
		et=l;
		mx=tx-(a[n].x-a[n].t/l*tx);
		my=ty-(a[n].y-a[n].t/l*ty);
		for(i=st;i<et;i++){
			if(mx>0) putchar('R'),mx--;
			else if(mx<0) putchar('L'),mx++;
			else if(my>0) putchar('U'),my--;
			else if(my<0) putchar('D'),my++;
			else{
				putchar('L');
				putchar('R');
				i++;
			}
		}
		putchar('\n');
	}
	return 0;
}