#include<bits/stdc++.h>
#define I inline
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define abs(x) ((x)>0?(x):-(x))
#define re register
#define ll long long
#define db double
#define N 250000
#define mod 998244353
#define eps (1e-5)
#define U unsigned int
#define it iterator
#define Gc() getchar() 
#define Me(x,y) memset(x,y,sizeof(x))
#define d(x,y) (n*(x-1)+(y))
using namespace std;
int T,W,H,nx,ny,mx,my,w,h,Ans; 
int main(){
//	freopen("1.in","r",stdin);
	scanf("%d",&T);while(T--){
		scanf("%d%d",&W,&H);scanf("%d%d%d%d",&nx,&ny,&mx,&my);scanf("%d%d",&w,&h);
		if(W<w+mx-nx&&H<h+my-ny){printf("-1\n");continue;}
		Ans=1e9;if(W>=w+mx-nx){
			Ans=min(Ans,min(max(w-nx,0),max(w-(W-mx),0)));
		}
		if(H>=h+my-ny){
			Ans=min(Ans,min(max(h-ny,0),max(h-(H-my),0)));
		}printf("%.9lf\n",1.0*Ans);
	}
}