#include<stdio.h>
#include<math.h>
double Y1,Y2,yw,xb,yb,r,p,t,c,A,B,C,pp,p1,p2,Y;
int main(){
	scanf("%lf%lf%lf%lf%lf%lf",&Y1,&Y2,&yw,&xb,&yb,&r);
	if(xb<=r){printf("-1\n");return 0;}
	c=yw*2-Y2-r*2;
	A=-xb*xb+r*r;
	B=2*(xb*yb-xb*c);
	C=-c*c+2*c*yb-yb*yb+r*r;
	p=(-B-sqrt(B*B-4*A*C))/(2.0*A);
	pp=(-B+sqrt(B*B-4*A*C))/(2.0*A);
	if(p>pp)p=pp;
	p1=p;
	c=yw*2-(Y1+r)-r*2;
	p2=(yb-c)/xb;
	if(p2>=p1){
		printf("-1\n");
	}
	else{
		Y=yw-r;
		p=(p1+p2)/2;
		printf("%.10lf\n",(Y+p*xb-yb)/p);
	}
}
//(xb+pyb-pc)^2-(p^2+1)(xb^2+c^2+2cyb+yb^2-r^2)=0
//-p^2(xb^2+c^2+2cyb+yb^2-r^2+yb^2+c^2-2ybc)+2p(xbyb-xbc)+xb^2-(xb^2+c^2+2cyb+yb^2-r^2)=0