#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair <int,int>
#define fi first
#define se second
#define pb push_back
#define all(x) x.begin(),x.end()
#define sort(x) sort(all(x))
#define rev(x) reverse(all(x))
#define mem(x,v) memset(x,v,sizeof(x))

char buf[1<<21],*p1=buf,*p2=buf,obuf[1<<23],*O=obuf;

#ifdef __WIN64
	#define gc getchar()
#else
	#define gc (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<20,stdin),p1==p2)?EOF:*p1++)
#endif
#define pc(x) (*O++=x)
#define flush() fwrite(obuf,O-obuf,1,stdout)

inline int read(){
	int x=0,sign=0; char s=getchar();
	while(!isdigit(s))sign|=s=='-',s=getchar();
	while(isdigit(s))x=(x<<1)+(x<<3)+(s-'0'),s=getchar();
	return sign?-x:x;
}
void print(int x){
	if(x>9)print(x/10);
	pc(x%10+'0');
}

const int N=5e3+5;

double x[N],y[N],z[N],p[N],ans=1e9;
double dis(double a,double b,double c){return sqrt(a*a+b*b+c*c);}

int n;

int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x[i]>>y[i]>>z[i],p[i]=dis(x[i]-x[1],y[i]-y[1],z[i]-z[1]);
		for(int j=2;j<i;j++){
			double d=dis(x[i]-x[j],y[i]-y[j],z[i]-z[j]);
			ans=min(ans,(p[i]+d+p[j])/2);
		}
	}
	printf("%.10lf",ans);
	return 0;
}