#include<cstdio>
#include<cstring>
#define M 20
#define N 50
long long check[1<<M];
long long same[N][M];
double ans[1<<M];
int cnt[1<<M];
char s[N][M+10];
int main(){
	int n,m,i,j,k,tmp;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%s",s[i]);
	}
	m=strlen(s[0]);
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			for(k=0;k<m;k++){
				if(s[i][k]==s[j][k]){
					same[i][k]|=1LL<<j;
				}
			}
		}
	}
	for(i=0;i<n;i++){
		check[0]=(1LL<<n)-1;
		for(j=0;j<m;j++){
			check[1<<j]=same[i][j];
		}
		for(j=0;j<(1<<m);j++){
			check[j]=check[j&-j]&check[j^(j&-j)];
			if(check[j]!=(1LL<<i)) cnt[j]++;
		}
	}
	for(i=(1<<m)-1;i>=0;i--){
		tmp=0;
		for(j=0;j<m;j++){
			if(i&(1<<j)) continue;
			ans[i]+=ans[i|(1<<j)];
			tmp++;
		}
		if(tmp) ans[i]/=tmp;
		ans[i]+=1.0*cnt[i]/n;
	}
	printf("%.12f\n",ans[0]);
	return 0;
}