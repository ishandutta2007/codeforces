#include <stdio.h>

typedef long long lli;

const lli MOD=1e9+7;

int n;
lli cache[5011][26], sum[5011];
lli combi[5011][5011];
char str[5011];
int main()
{
	scanf("%d",&n);
	scanf("%s",str+1);

	for(int i=0;i<=n;i++) {
		for(int j=0;j<=i;j++) {
			if(j==0||j==i) combi[i][j]=1;
			else combi[i][j]=(combi[i-1][j-1]+combi[i-1][j])%MOD;
		}
	}

	sum[0]=1;
	for(int i=1;i<=n;i++) {
		int ch=str[i]-'a';
		for(int j=i;j>0;j--){
			int d=(sum[j-1]-cache[j-1][ch]-cache[j][ch]+3*MOD)%MOD;
			cache[j][ch]=(cache[j][ch]+d)%MOD;
			sum[j]=(sum[j]+d)%MOD;
		}	
	}

	lli res=0;
	for(int i=1;i<=n;i++) {
		res=(res+sum[i]*combi[n-1][i-1])%MOD;
	}
	printf("%lld\n",res);

	return 0;
}