#include<cstdio>
#define N 1010
#define M 1010
using namespace std;
int a[N],b[M];
bool used[N];
int pos[N];
int main(){
	int i,j,n,m,cnt=0,w=0;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	for(i=0;i<m;i++){
		scanf("%d",&b[i]);
		if(!used[b[i]]){
			pos[cnt++]=b[i];
			used[b[i]]=true;
		}
	}
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			if(pos[j]!=b[i]){
				w+=a[pos[j]];
			}
			else{
				break;
			}
		}
		for(;j;j--) pos[j]=pos[j-1];
		pos[0]=b[i];
	}
	printf("%d\n",w);
	return 0;
}