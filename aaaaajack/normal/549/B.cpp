#include<cstdio>
#define N 110
using namespace std;
int a[N][N],s[N];
bool pick[N];
int main(){
	int n,i,j,cnt=0;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			scanf("%1d",&a[i][j]);
		}
	}
	for(i=0;i<n;i++) scanf("%d",&s[i]);
	bool cont=true;
	while(cont){
		cont=false;
		for(i=0;i<n;i++){
			if(s[i]==0){
				cont=true;
				cnt++;
				pick[i]=true;
				for(j=0;j<n;j++){
					s[j]-=a[i][j];
				}
			}
		}
	}
	printf("%d\n",cnt);
	for(i=0;i<n;i++){
		if(pick[i]) printf("%d ",i+1);
	}
	return 0;
}