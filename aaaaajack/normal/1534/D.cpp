#include<bits/stdc++.h>
#define N 2010
using namespace std;
int ea[N],eb[N],dis[N],cnt;
vector<int> br[N];
bool vis[N],del[N];
void add(int x,int y){
	ea[cnt]=x;
	eb[cnt]=y;
	cnt++;
}
int main(){
	int n;
	scanf("%d",&n);
	printf("? 1\n");
	fflush(stdout);
	int c[2]={},ch;
	for(int i=1;i<=n;i++){
		scanf("%d",&dis[i]);
		if(i>1) c[dis[i]&1]++;
		if(dis[i]==1) add(1,i);
	}
	if(c[0]<c[1]) ch=0;
	else ch=1;
	for(int i=2;i<=n;i++){
		if((dis[i]&1)==ch){
			printf("? %d\n",i);
			fflush(stdout);
			int x;
			for(int j=1;j<=n;j++){
				scanf("%d",&x);
				if(x==1 && j>1) add(i,j);
			}
		}
	}
	puts("!");
	for(int i=0;i<cnt;i++) printf("%d %d\n",ea[i],eb[i]);
	fflush(stdout);
	return 0;
}