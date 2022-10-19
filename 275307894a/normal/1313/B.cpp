#include<cstdio>
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
using namespace std;
int t,n,m,k;
inline void read(int &x){
	char s=getchar();x=0;
	while(s<'0'||s>'9') s=getchar();
	while(s>='0'&&s<='9') x=(x<<3)+(x<<1)+(s^48),s=getchar();
}
int main(){
	scanf("%d",&t);
	while(t--){
		read(n);read(m);read(k);
		printf("%d %d\n",min(max(m+k-n+1,1),n),min(n,m+k-1));
	}
}