#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define maxn 105
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
int n,dif1[5],dif2[5];
bool a[5][maxn][maxn],should1[maxn][maxn];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=4;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				char c;
				for(c=getchar();c!='0'&&c!='1';c=getchar());
				if(c=='1') a[i][j][k] = true;
				else a[i][j][k] = false;
			}
		}
	}
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++){
		should1[i][j] = ((i+j)%2==0);
	}
	for(int i=1;i<=4;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				dif1[i] += (a[i][j][k]==should1[j][k]);
			}
		}
		dif2[i] = n*n-dif1[i];
	}
	int ans = inf;
	for(int i=1;i<=3;i++){
		for(int j=i+1;j<=4;j++){
			int res=0;
			for(int k=1;k<=4;k++){
				if(i==k||j==k) res += dif1[k];
				else res += dif2[k];
			}
			ans = min(ans,res);
		}
	}
	printf("%d\n",ans);
	return 0;
}