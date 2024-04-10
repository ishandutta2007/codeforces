#include<bits/stdc++.h>
#define I inline
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define abs(x) ((x)>0?(x):-(x))
#define re register
#define RI re int
#define ll long long
#define db double
#define lb long db
#define N 100000
#define M 5
#define mod 1000000007
#define Mod 998244352
#define eps (1e-4)
#define U unsigned int
#define it iterator
#define Gc() getchar() 
#define Me(x,y) memset(x,y,sizeof(x))
#define d(x,y) (n*(x-1)+(y))
#define R(n) (rand()*rand()%(n)+1)
using namespace std;
int W=1<<7,Ans,n=100,x;
int main(){
	RI i;printf("? ");for(i=0;i<n;i++) printf("%d ",i);cout<<endl;
	scanf("%d",&x);Ans+=(x>>7)<<7;printf("? ");for(i=1;i<=n;i++) printf("%d ",i<<7);cout<<endl;
	scanf("%d",&x);Ans+=(x&(W-1));printf("! %d\n",Ans);cout<<endl;
}