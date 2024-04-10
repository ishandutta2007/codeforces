#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
int main(){
	char v[30],h[30];
	bool reach[30][30],flag=true;
	int i,j,n,m,k,l;
	scanf("%d%d",&n,&m);
	scanf("%s%s",h,v);
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			memset(reach,0,sizeof(reach));
			queue<int> x,y;
			x.push(i);
			y.push(j);
			reach[i][j]=true;
			while(!x.empty()){
				int nx=x.front();
				int ny=y.front();
				x.pop();
				y.pop();
				if(v[nx]=='v'){
					if(ny<n-1&&!reach[nx][ny+1]){
						reach[nx][ny+1]=true;
						x.push(nx);
						y.push(ny+1);
					}
				}
				else{
					if(ny>0&&!reach[nx][ny-1]){
						reach[nx][ny-1]=true;
						x.push(nx);
						y.push(ny-1);
					}
				}
				if(h[ny]=='>'){
					if(nx<m-1&&!reach[nx+1][ny]){
						reach[nx+1][ny]=true;
						x.push(nx+1);
						y.push(ny);
					}
				}
				else{
					if(nx>0&&!reach[nx-1][ny]){
						reach[nx-1][ny]=true;
						x.push(nx-1);
						y.push(ny);
					}
				}
			}
			for(k=0;k<m;k++){
				for(l=0;l<n;l++){
					if(!reach[k][l]) flag=false;
				}
			}
		}
	}
	if(flag) puts("YES");
	else puts("NO");
	return 0;
}