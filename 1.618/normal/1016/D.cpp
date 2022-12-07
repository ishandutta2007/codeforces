#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
#include <utility>
#define maxn 105
using namespace std;
typedef long long ll;
int n,m,a[maxn],b[maxn];
bool ans[35][maxn][maxn],aa[maxn],bb[maxn];
int main(){
	memset(ans,0,sizeof(ans));
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=m;i++) scanf("%d",&b[i]);
	for(int w=0;w<30;w++){
		int sa,sb,fira = -1,fira0 = -1,firb = -1,firb0 = -1;
		sa = sb = 0;
		for(int i=1;i<=n;i++){
			aa[i] = (a[i] >> w & 1);
			sa += aa[i];
			if(aa[i]) fira = i;
			else fira0 = i;
		}
		for(int j=1;j<=m;j++){
			bb[j] = (b[j] >> w & 1);
			sb += bb[j];
			if(bb[j]) firb = j;
			else firb0 = j;
		}
		if((sa & 1) != (sb & 1)){
			puts("NO");
			return 0;
		}
		if(sa == 0){
			for(int i=1;i<=m;i++){
				if(bb[i]){
					ans[w][fira0][i] = 1;
				}
			}
		}else if(sb == 0){
			for(int i=1;i<=n;i++){
				if(aa[i]){
					ans[w][i][firb0] = 1;
				}
			}
		}else{
			vector <int> a1,b1;
			for(int i=1;i<=n;i++){
				if(aa[i]){
					a1.push_back(i);
				}
			}
			for(int i=1;i<=m;i++){
				if(bb[i]){
					b1.push_back(i);
				}
			}
			if(sa <= sb){
				for(int i=0;i<sa;i++){
					ans[w][a1[i]][b1[i]] = 1;
				}
				for(int i=sa;i<sb;i++){
					ans[w][fira][b1[i]] = 1;
				}
			}else{
				for(int i=0;i<sb;i++){
					ans[w][a1[i]][b1[i]] = 1;
				}
				for(int i=sb;i<sa;i++){
					ans[w][a1[i]][firb] = 1;
				}
			}
		}
	}
	puts("YES");
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			int res = 0;
			for(int w=0;w<30;w++){
				res += ans[w][i][j] * (1 << w);
			}
			printf("%d",res);
			if(j == m) printf("\n");
			else printf(" ");
		}
	}
	return 0;
}