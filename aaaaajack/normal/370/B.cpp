#include<cstdio>
using namespace std;
int main(){
	int i,j,k,n,num[100],tnum[100];
	bool con[100][101]={false},temp[100][101];
	int card[100][100];
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&num[i]);
		for(j=0;j<num[i];j++){
			scanf("%d",&card[i][j]);
			con[i][card[i][j]]=true;
		}
	}
	for(i=0;i<n;i++){
		bool win=true;
		for(j=0;j<n;j++){
			tnum[j]=num[j];
			for(k=0;k<101;k++){
				temp[j][k]=con[j][k];
			}
		}
		for(j=0;j<num[i];j++){
			for(k=0;k<n;k++){
				if(temp[k][card[i][j]]){
					temp[k][card[i][j]]=false;
					tnum[k]--;
				}
			}
		}
		for(j=0;j<n;j++){
			if(j==i) continue;
			if(tnum[j]==0) win=false;
		}
		if(win) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}