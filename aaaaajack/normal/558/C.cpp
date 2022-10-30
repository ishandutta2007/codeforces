#include<cstdio>
#include<cstdlib>
#include<algorithm>
#define M 100100
#define S 20
using namespace std;
int cnt[M],op[M];
int main(){
	int n,x,y,s,i,j,pre,ans=1023456789;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&x);
		pre=0;
		while(x){
			s=0;
			while(x%2==0){
				x>>=1;
				s++;
			}
			y=x;
			j=0;
			while(y<M){
				cnt[y]++;
				op[y]+=pre+abs(j-s);
				j++;
				y<<=1;
			}
			pre+=s+1;
			x>>=1;
		}
	}
	for(i=1;i<M;i++){
		if(cnt[i]==n&&op[i]<ans) ans=op[i];
	}
	printf("%d\n",ans);
	return 0;
}