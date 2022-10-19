#include<bits/stdc++.h>
#define I inline
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define abs(x) ((x)>0?(x):-(x))
#define re register
#define ll long long
#define db double
#define lb long db
#define N 200000
#define K 20
#define mod 998244353
#define Mod 998244352
#define eps (1e-4)
#define U unsigned int
#define it iterator
#define Gc() getchar() 
#define Me(x,y) memset(x,y,sizeof(x))
#define d(x,y) (n*(x-1)+(y))
using namespace std;
int T,Ans[N+5],Ah,a,b,c,d;
int main(){
//	freopen("1.in","r",stdin);
	re int i;scanf("%d",&T);while(T--){
		scanf("%d%d",&a,&b);c=(a+b+1>>1);d=a+b-c;
		for(Ah=i=0;i<=c;i++){
			if(i>a) break;if(a-i>d) continue;Ans[++Ah]=a-i+c-i;
		}
		c=(a+b>>1);d=a+b-c;
		for(i=0;i<=c;i++){
			if(i>a) break;if(a-i>d) continue;Ans[++Ah]=a-i+c-i;
		}
		sort(Ans+1,Ans+Ah+1);Ah=unique(Ans+1,Ans+Ah+1)-Ans-1;printf("%d\n",Ah);for(i=1;i<=Ah;i++) printf("%d ",Ans[i]);puts("");
	}
}