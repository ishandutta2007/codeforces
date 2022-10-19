/*
Criteria:
1.read the problem carefully; WRITE DOWN SPECIAL CONSTRAINTS when the problem is long;
2.consider special situations/constraints to get observations;
3.think of everything throughout before coding;
4.return to the initial list of notifications after coding.

CONSTRAINTS:

OBSERVATIONS:

OTHER NOTIFICATIONS:

THINK CAREFULLY AND CODE DETERMINEDLY!
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ld eps=1e-9;
int cmp(ld x){if(x>eps)return 1;if(x<-eps)return -1;return 0;}
struct VI{
    int x,y;
    VI(){}
    VI(int X,int Y){x=X,y=Y;}
    friend VI operator+(const VI&u,const VI&v){return VI(u.x+v.x,u.y+v.y);}
    friend VI operator-(const VI&u,const VI&v){return VI(u.x-v.x,u.y-v.y);}
    void read(){scanf("%d%d",&x,&y);}
    void print()const{printf("(%d,%d)",x,y);}
    friend ll operator&(const VI&u,const VI&v){return 1ll*u.x*v.y-1ll*u.y*v.x;}
    bool operator!()const{return x>0||x==0&&y>=0;}
    friend bool operator<(const VI&u,const VI&v){if((!u)!=(!v))return(!u)<(!v);return(u&v)>0;}
}r[200100],O;
struct VD{
	ld x,y;
    VD(){}
    VD(ld X,ld Y){x=X,y=Y;}
    VD(VI P){x=P.x,y=P.y;}
    void read(){scanf("%Lf%Lf",&x,&y);}
    void print()const{printf("(%Lf,%Lf)",x,y);}
    friend VD operator+(const VD&u,const VD&v){return VD(u.x+v.x,u.y+v.y);}
    friend VD operator-(const VD&u,const VD&v){return VD(u.x-v.x,u.y-v.y);}
    friend ld operator&(const VD&u,const VD&v){return u.x*v.y-u.y*v.x;}
    friend VD operator*(const VD&u,const ld&v){return VD(u.x*v,u.y*v);}
    friend VD operator/(const VD&u,const ld&v){return VD(u.x/v,u.y/v);}
}p[600100];
typedef VI PI;
typedef VD PD;
struct Line{//the left side of the line indicates the semiplane
    PI x,y;
    VI z;
    Line(){}
    Line(PI X,PI Y){x=X,y=Y,z=y-x;}
    friend PD operator&(const Line&u,const Line&v){
    	VD UX(u.x),UZ(u.z),VX(v.x),VZ(v.z);
		return UX+UZ*(VZ&(UX-VX)/(UZ&VZ));
	}
    friend bool operator&(const Line&u,const PD&v){return cmp((v-u.x)&u.z)!=1;}
    friend bool operator|(const Line&u,const Line&v){return!(u.z<v.z)&&!(v.z<u.z);}//whether two lines have same slopes
    friend bool operator<(const Line&u,const Line&v){if(u|v)return (u.z&(v.y-u.x))<0;return u.z<v.z;}
    friend bool operator/(const Line&u,const Line&v){return !(u.z&v.z);}
    void print()const{x.print(),y.print(),z.print(),puts("");}
}l[600100];
int T,n,m,q[600100],L,R;
ld area(int _){ld ret=0;for(int i=0;i<_;i++)ret+=p[i]&p[(i+1)%_];return fabs(ret)/2;}
ld Semiplane_Intersection(){
    // printf("%d\n",n);
//    for(int i=0;i<n;i++)l[i].print();
    sort(l,l+n);
    q[L=R=0]=0;
    for(int i=1;i<n;i++){
        if(l[i]|l[i-1])continue;
        if(L<R&&( (l[q[L]]/l[q[L+1]]) || (l[q[R]]/l[q[R-1]]) ))return 0;
        while(L<R&&!(l[i]&p[R-1]))R--;
        while(L<R&&!(l[i]&p[L]))L++;
        q[++R]=i;
        if(L!=R)p[R-1]=(l[q[R]]&l[q[R-1]])/*,printf("%d,%d:",q[R-1],q[R]),p[R-1].print(),puts("")*/;
    }
    // for(int i=L;i<=R;i++)printf("%d ",q[i]);puts("");
    while(L<R&&!(l[q[L]]&p[R-1]))R--;
    while(L<R&&!(l[q[R]]&p[L]))L++;
    if(R-L+1<=2)return 0;
    int _=0;
    for(int i=L;i<R;i++)p[_++]=l[q[i]]&l[q[i+1]];
    p[_++]=l[q[R]]&l[q[L]];
    return area(_);
}
void insert(int i,int j){if((r[i]&r[j])>0)l[n++]=Line(r[i]+O,r[j]+O);else l[n++]=Line(r[j]+O,r[i]+O);}
void mina(){
	scanf("%d",&m),n=0,O.read(),m--;
	for(int i=0;i<m;i++)r[i].read(),r[i]=r[i]-O;
//	for(int i=0;i<m;i++)r[i].print();puts("");
	sort(r,r+m);
//	for(int i=0;i<m;i++)r[i].print();puts("");
	for(int i=0,j=1;i<m;i++){
		if(!(r[i]&r[(i+1)%m])){puts("0");return;}
		insert(i,(i+1)%m);
		while((r[i]&r[j])>0)(++j)%=m;
//		printf("GUGU:%d,%d,%lld\n",i,j,(r[i]&r[j]));
		if(i==j)continue;
		if(!(r[i]&r[j])){puts("0");return;}
		insert(i,j);
//		if((j+m-1)%m!=i)insert(i,(j+m-1)%m);
	}
	PI A(1e6,1e6),B(-1e6,1e6),C(-1e6,-1e6),D(1e6,-1e6);
	l[n++]=Line(A,B);
	l[n++]=Line(B,C);
	l[n++]=Line(C,D);
	l[n++]=Line(D,A);
	printf("%Lf\n",Semiplane_Intersection());
}
int main(){scanf("%d",&T);while(T--)mina();return 0;}
/*
1
5
1 3
5 2
6 1
4 4
-3 3
*/