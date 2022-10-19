#include<cstdio>
#define min(a,b) ((a)<(b)?(a):(b))
using namespace std;
int n,m,k,x,y,z,f1[1000039],f2[1000039],a[5][1000039],flag,ans1,ans2,ans3,ans4,fs1[5][1000039],fs2[5][1000039],fs3[5][1000039],fs4[5][1000039];
char s;
inline void swap(int &x,int &y){x^=y^=x^=y;}
int main(){
//	freopen("1.in","r",stdin);
	register int i,j;
	scanf("%d%d",&n,&m);
	if(n>=4&&m>=4) {printf("-1\n");return 0;}
	if(n==1||m==1){printf("0\n");return 0;}
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++) {
			s=getchar();
			if(s<'0'||s>'9') s=getchar();
			if(n==min(n,m))a[i][j]=s-'0';
			else a[j][i]=s-'0';
		}
	}
	if(n>m) swap(n,m);
	if(n==2){
		for(i=1;i<=m;i++) f1[i]=f2[i]=(a[1][i]+a[2][i])%2;
		f1[1]^=1;ans1=1;
		for(i=2;i<=m;i++){
			if((f1[i]+f1[i-1])%2==0) f1[i]^=1,ans1++;
			if((f2[i]+f2[i-1])%2==0) f2[i]^=1,ans2++;
		}
		printf("%d\n",min(ans1,ans2));
	}
	else{
		for(i=2;i<=n;i++) {
			for(j=1;j<=m;j++){
				fs1[i][j]=fs2[i][j]=fs3[i][j]=fs4[i][j]=(a[i][j]+a[i-1][j])%2;
			}
		}
		ans1=ans2=ans3=1;fs1[2][1]^=1;fs2[3][1]^=1;fs3[2][1]^=1;fs3[3][1]^=1;
		for(i=2;i<=m;i++){
			if((fs1[2][i]+fs1[2][i-1])%2==0||(fs1[3][i]+fs1[3][i-1])%2==0) {
				ans1++;
				if((fs1[2][i]+fs1[2][i-1])%2==0)fs1[2][i]^=1;
				if((fs1[3][i]+fs1[3][i-1])%2==0)fs1[3][i]^=1;
			}
			if((fs2[2][i]+fs2[2][i-1])%2==0||(fs2[3][i]+fs2[3][i-1])%2==0){
				ans2++;
				if((fs2[2][i]+fs2[2][i-1])%2==0)fs2[2][i]^=1;
				if((fs2[3][i]+fs2[3][i-1])%2==0)fs2[3][i]^=1;
			} 
			if((fs3[2][i]+fs3[2][i-1])%2==0||(fs3[3][i]+fs3[3][i-1])%2==0){
				ans3++;
				if((fs3[2][i]+fs3[2][i-1])%2==0)fs3[2][i]^=1;
				if((fs3[3][i]+fs3[3][i-1])%2==0)fs3[3][i]^=1;
			} 
			if((fs4[2][i]+fs4[2][i-1])%2==0||(fs4[3][i]+fs4[3][i-1])%2==0){
				ans4++;
				if((fs4[2][i]+fs4[2][i-1])%2==0)fs4[2][i]^=1;
				if((fs4[3][i]+fs4[3][i-1])%2==0)fs4[3][i]^=1;
			} 
		}
		printf("%d\n",min(min(ans1,ans2),min(ans3,ans4)));
	}
}