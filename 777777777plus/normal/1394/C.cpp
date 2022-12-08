#include<bits/stdc++.h>
using namespace std;

const double eps=1e-9;
const int N = 3e6+5;

struct node
{
    double  x,y;
    double operator*(const node &b)const
    {return x*b.y-y*b.x;}
    node operator+(const node &b)const 
    {return (node){x+b.x,y+b.y};}
    node operator-(const node &b)const
    {return (node){x-b.x,y-b.y};}
    node operator*(const double b)const
    {return (node){b*x,b*y};}
}S[N],T[N];

struct nodd{node p,v;}Line[N];

int n;
int m,top;

node Intersection(nodd a,nodd b)
{
    double k=((a.p-b.p)*a.v)/(b.v*a.v);
    return b.p+b.v*k;
}
void Cut(nodd D)
{
    int i,j,k=0;
    S[0]=S[top];
    S[top+1]=S[1];
    for(i=1;i<=top;i++)
    {
        if(D.v*(S[i]-D.p)<-eps)
        {
            if(D.v*(S[i-1]-D.p)>-eps)T[++k]=Intersection(D,nodd{S[i-1],S[i]-S[i-1]});
            if(D.v*(S[i+1]-D.p)>-eps)T[++k]=Intersection(D,nodd{S[i],S[i+1]-S[i]});
        }
        else T[++k]=S[i];
    }
    copy(T+1,T+k+1,S+1);top=k;
}
double Garea()
{
    int i,j,k=0;
    S[top+1]=S[1];
    double ans=0;
    for(i=1;i<=top;i++)ans+=S[i]*S[i+1];
    return ans;
}
char s[N];
int X[N],Y[N];
int ansx,ansy;

bool CCC(double x,double y){
	node p;
	p.x=x;
	p.y=y;
	S[top+1]=S[1];
	for(int i=1;i<=top;++i){
		if((p-S[i])*(S[i+1]-S[i])>0)return 0;
	}
	return 1;
}

void CC(double x,double y){
	if(CCC(x,y)&&CCC(x+1,y)&&CCC(x,y+1)&&CCC(x+1,y+1)){
		ansx=x;
		ansy=y;
	}
}

bool Solve(){
	top=0;
    S[++top]=(node){1,0};
    S[++top]=(node){2e9,0};
    S[++top]=(node){2e9,2e9};
    S[++top]=(node){0,2e9};
    S[++top]=(node){0,1};
    for(int i=1;i<=m;i++)Cut(Line[i]);
	ansx=ansy=-1;
	for(int i=1;i<=top;++i){
		CC(S[i].x,S[i].y);
		CC(S[i].x-1,S[i].y);
		CC(S[i].x,S[i].y-1);
		CC(S[i].x-1,S[i].y-1);
	}
    return Garea()>1e-1&&ansx!=-1&&ansy!=-1;
}

bool can(int ans,bool flag){
	m=0;
	node p[6];
	for(int i=1;i<=n;++i){
		double x=X[i],y=Y[i];
		p[0]={x+1+ans,y};
		p[1]={x+1+ans,y+1+ans};
		p[2]={x,y+1+ans};
		p[3]={x-ans,y+1};
		p[4]={x-ans,y-ans};
		p[5]={x+1,y-ans};
		for(int j=0;j<6;++j){
			Line[++m]={p[j],p[(j+1)%6]-p[j]};
		}
	}
	bool ret=Solve();
	if(!flag)return ret;
	for(int i=1;i<=ansx;++i)printf("B");
	for(int i=1;i<=ansy;++i)printf("N");
	return 0;
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%s",s);
		int len=strlen(s);
		for(int j=0;j<len;++j){
			if(s[j]=='B')X[i]++;
			else Y[i]++;
		}
	}
	bool flag=1;
	for(int i=2;i<=n;++i)
	if(X[i]!=X[1]||Y[i]!=Y[1]){
		flag=0;
	}
	if(flag){
		puts("0");
		int len=strlen(s);
		for(int i=0;i<len;++i)printf("%c",s[i]);
		printf("\n");
		return 0;
	}
	int l=1,r=5e5;
	while(l!=r){
		int mid=l+r>>1;
		if(can(mid,0))r=mid;
		else l=mid+1;
	}
	printf("%d\n",l);
	can(l,1);
}