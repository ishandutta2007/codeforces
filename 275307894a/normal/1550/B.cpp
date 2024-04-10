#include<bits/stdc++.h>
#define I inline
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define abs(x) ((x)>0?(x):-(x))
#define re register
#define ll long long
#define db double
#define N 200000
#define M 50000
#define mod 1000000000
#define mod2 39989
#define eps (1e-7)
#define U unsigned int
#define it iterator
#define Gc() getchar() 
#define Me(x,y) memset(x,y,sizeof(x))
#define R(x) (rand()*rand()%x+1)
using namespace std;
int T,n,a,b,now,tot,pus;char s[N+5];
int main(){
//	freopen("1.in","r",stdin);
	re int i;scanf("%d",&T);while(T--){
		scanf("%d%d%d",&n,&a,&b);scanf("%s",s+1);
		if(b>0) printf("%d\n",(a+b)*n);
		else{
			tot=0;for(i=2;i<=n;i++)tot+=(s[i]!=s[i-1]);tot++;printf("%d\n",a*n+b*(tot/2+1)); 
		}
	}
}