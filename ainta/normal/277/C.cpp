#include<stdio.h>
#include<algorithm>
using namespace std;
struct Xseg{
	int y,x1,x2;
	bool operator <(const Xseg &p)const{
		return y!=p.y?y<p.y:x1<p.x1;
	}
}X[101000];
struct Yseg{
	int x,y1,y2;
	bool operator <(const Yseg &p)const{
		return x!=p.x?x<p.x:y1<p.y1;
	}
}Y[101000];
int n,m,k,CX,CY,ccx,ccy,P,cx[101000],cy[101000],Mn,Mm;
void DoX(int a){
	int i,x1=0,x2,s=0,o=cx[a]-(cx[a]^P),t=0;
	x2=o;
	for(i=0;i<CX;i++)if(X[i].y==a)break;
	for(i=i;i<CX;i++){
		if(t<X[i].x1)s+=X[i].x1-t;
		if(t<X[i].x2)t=X[i].x2;
		if(s>=o){
			x2=X[i].x1+o-s;
			break;
		}
		if(X[i].y!=X[i+1].y){
			x2=t+o-s;
			break;
		}
	}
	printf("%d %d %d %d\n",x1,a,x2,a);
}
void DoY(int a){
	int i,y1=0,y2,s=0,o=cy[a]-(cy[a]^P),t=0;
	y2=o;
	for(i=0;i<CY;i++)if(Y[i].x==a)break;
	for(i=i;i<CY;i++){
		if(t<Y[i].y1)s+=Y[i].y1-t;
		if(t<Y[i].y2)t=Y[i].y2;
		if(s>=o){
			y2=Y[i].y1+o-s;
			break;
		}
		if(Y[i].x!=Y[i+1].x){
			y2=t+o-s;
			break;
		}
	}
	printf("%d %d %d %d\n",a,y1,a,y2);
}
int main(){
	int xx1,xx2,yy1,yy2,t=0,s=0,i;
	scanf("%d%d%d",&n,&m,&k);
	Mn=n,Mm=m;
	if(Mn>100000)Mn=k+2;
	if(Mm>100000)Mm=k+2;
	for(i=0;i<k;i++){
		scanf("%d%d%d%d",&xx1,&yy1,&xx2,&yy2);
		if(xx1>xx2)swap(xx1,xx2);
		if(yy1>yy2)swap(yy1,yy2);
		if(xx1==xx2)Y[CY].x=xx1,Y[CY].y1=yy1,Y[CY++].y2=yy2;
		else X[CX].y=yy1,X[CX].x1=xx1,X[CX++].x2=xx2;
	}
	sort(X,X+CX);
	sort(Y,Y+CY);
	ccx=m-1,ccy=n-1,t=0;
	for(i=1;i<Mm;i++)cx[i]=n;
	for(i=1;i<Mn;i++)cy[i]=m;
	for(i=0;i<CX;i++){
		if(t<X[i].x1)s+=X[i].x1-t;
		if(t<X[i].x2)t=X[i].x2;
		if(X[i].y!=X[i+1].y){
			ccx--;
			if(X[i].y<Mm)cx[X[i].y]=s+n-t;
			P^=(s+n-t);
			s=0,t=0;
		}
	}
	for(i=0;i<CY;i++){
		if(t<Y[i].y1)s+=Y[i].y1-t;
		if(t<Y[i].y2)t=Y[i].y2;
		if(Y[i].x!=Y[i+1].x){
			ccy--;
			if(Y[i].x<Mn)cy[Y[i].x]=s+m-t;
			P^=(s+m-t);
			s=0,t=0;
		}
	}
	if(ccx&1)P^=n;
	if(ccy&1)P^=m;
	if(P){
		printf("FIRST\n");
		for(i=1;i<Mm;i++)if((cx[i]^P)<cx[i])break;
		if(i<Mm){
			DoX(i);
			return 0;
		}
		for(i=1;i<Mn;i++)if((cy[i]^P)<cy[i])break;
		DoY(i);
	}
	else printf("SECOND\n");
}