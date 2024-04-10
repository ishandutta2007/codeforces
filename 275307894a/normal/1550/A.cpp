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
int T,n;
int main(){
//	freopen("1.in","r",stdin);
	re int i;scanf("%d",&T);while(T--){
		scanf("%d",&n);for(i=1;;i+=2) if((i+1)*(i+1)/4>=n)break;printf("%d\n",(i+1)/2);
	}
}