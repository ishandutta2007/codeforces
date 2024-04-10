#include<stdio.h>
__int64 n,c,x,y,b,e,m,SS,t,R;
struct A{
	__int64 x,y;
}p,q,r,s;
int main()
{
	scanf("%I64d%I64d%I64d%I64d",&n,&x,&y,&c);
	b=0,e=2000000001;
	while(b<=e){
		m=(b+e+1)/2;
		p.x=x,p.y=y+m;
		q.x=x,q.y=y-m;
		r.x=x+m,r.y=y;
		s.x=x-m,s.y=y;
		SS=(m+1)*(m+1)+m*m;
		t=0;if(p.y>n)t=p.y-n;
		SS-=t*t;
		t=0;if(q.y<1)t=1-q.y;
		SS-=t*t;
		t=0;if(r.x>n)t=r.x-n;
		SS-=t*t;
		t=0;if(s.x<1)t=1-s.x;
		SS-=t*t;
		t=0;if(p.x+p.y>2*n)t=p.x+p.y-2*n;
		SS+=t*(t-1)/2;
		t=0;if(q.x+q.y<2)t=2-q.x-q.y;
		SS+=t*(t-1)/2;
		t=0;if(p.y-p.x>=n)t=p.y-p.x-n;
		SS+=t*(t+1)/2;
		t=0;if(q.x-q.y>=n)t=q.x-q.y-n;
		SS+=t*(t+1)/2;
		if(SS>=c){
			R=m,e=m-1;
		}
		else b=m+1;
	}
	printf("%I64d\n",R);
}