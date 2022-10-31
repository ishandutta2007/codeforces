#include<cstdio>
#include<bitset>
#define N 510
using namespace std;
bitset<N> con[N];
int f[N];
int find(int x){
	if(f[x]==x) return x;
	return f[x]=find(f[x]);
}
void uni(int x,int y){
	if(find(x)!=find(y)) f[f[x]]=f[y];
}
int main(){
	int n,m,x,y,cnt=0,deg[N]={},r[N];
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) con[i][i]=true,f[i]=i;
	for(int i=0;i<m;i++){
		scanf("%d%d",&x,&y);
		con[x][y]=con[y][x]=true;
	}
	for(int i=2;i<=n;i++){
		for(int j=1;j<i;j++){
			if(con[i]==con[j]){
				uni(i,j);
				break;
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(f[i]!=i) continue;
		r[cnt++]=i;
	}
	if(cnt>3) puts("No");
	else{
		for(int i=0;i<cnt;i++){
			for(int j=0;j<cnt;j++){
				if(j!=i&&con[r[i]][r[j]]) deg[i]++;
			}
		}
		bool wrong=false;
		char ans[N];
		if(cnt==3){
			if(deg[0]==1&&deg[1]==2&&deg[2]==1){
				ans[r[0]]='a';
				ans[r[1]]='b';
				ans[r[2]]='c';
			}
			else if(deg[0]==2&&deg[1]==1&&deg[2]==1){
				ans[r[0]]='b';
				ans[r[1]]='a';
				ans[r[2]]='c';
			}
			else if(deg[0]==1&&deg[1]==1&&deg[2]==2){
				ans[r[0]]='a';
				ans[r[1]]='c';
				ans[r[2]]='b';
			}
			else wrong=true;
		}
		else if(cnt==2){
			if(deg[0]==deg[1]){
				if(deg[0]==0){
					ans[r[0]]='a';
					ans[r[1]]='c';
				}
				else{
					ans[r[0]]='a';
					ans[r[1]]='b';
				}
			}
			else wrong=true;
		}
		else if(cnt==1){
			ans[r[0]]='a';
		}
		if(wrong) puts("No");
		else{
			puts("Yes");
			for(int i=1;i<=n;i++){
				putchar(ans[find(i)]);
			}
			putchar('\n');
		}
	}
}