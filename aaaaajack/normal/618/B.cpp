#include<cstdio>
using namespace std;
bool del[100];
int a[100][100];
int ans[100];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			scanf("%d",&a[i][j]);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<n;j++){
			if(del[j]) continue;
			bool sm=true;
			for(int k=0;k<n;k++){
				if(del[k]||j==k) continue;
				if(a[j][k]!=i){
					sm=false;
					break;
				}
			}
			if(sm){
				del[j]=true;
				ans[j]=i;
				break;
			}
		}
	}
	for(int i=0;i<n;i++) printf("%d ",ans[i]);
	return 0;
}