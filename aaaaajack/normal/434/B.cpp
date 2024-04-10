#include<cstdio>
#include<vector>
#include<set>
#include<algorithm>
#define N 1010
#define M 1010
using namespace std;
set<int> h[N],v[M]; 
int a[N][M]={0};
int main(){
	int i,j,n,m,q,op,x,y,pre,l,r,area;
	set<int>::iterator it;
	scanf("%d%d%d",&n,&m,&q);
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			scanf("%d",&a[i][j]);
		}
	}
	for(i=1;i<=n;i++){
		pre=0;
		for(j=1;j<=m+1;j++){
			if(a[i][j]!=pre) h[i].insert(j);
			pre=a[i][j];
		}
	}
	for(j=1;j<=m;j++){
		pre=0;
		for(i=1;i<=n+1;i++){
			if(a[i][j]!=pre) v[j].insert(i);
			pre=a[i][j];
		}
	}
	while(q--){
		scanf("%d%d%d",&op,&x,&y);
		if(op==1){
			if(!a[x][y]){
				a[x][y]=1;
				if(a[x][y-1]&&a[x][y+1]){
					h[x].erase(y);
					h[x].erase(y+1);
				}
				else if(a[x][y-1]){
					h[x].erase(y);
					h[x].insert(y+1);
				}
				else if(a[x][y+1]){
					h[x].erase(y+1);
					h[x].insert(y);
				}
				else{
					h[x].insert(y);
					h[x].insert(y+1);
				}
				if(a[x-1][y]&&a[x+1][y]){
					v[y].erase(x);
					v[y].erase(x+1);
				}
				else if(a[x-1][y]){
					v[y].erase(x);
					v[y].insert(x+1);
				}
				else if(a[x+1][y]){
					v[y].erase(x+1);
					v[y].insert(x);
				}
				else{
					v[y].insert(x);
					v[y].insert(x+1);
				}
			}
			else{
				a[x][y]=0;
				if(a[x][y-1]&&a[x][y+1]){
					h[x].insert(y);
					h[x].insert(y+1);
				}
				else if(a[x][y-1]){
					h[x].erase(y+1);
					h[x].insert(y);
				}
				else if(a[x][y+1]){
					h[x].erase(y);
					h[x].insert(y+1);
				}
				else{
					h[x].erase(y);
					h[x].erase(y+1);
				}
				if(a[x-1][y]&&a[x+1][y]){
					v[y].insert(x);
					v[y].insert(x+1);
				}
				else if(a[x-1][y]){
					v[y].erase(x+1);
					v[y].insert(x);
				}
				else if(a[x+1][y]){
					v[y].erase(x);
					v[y].insert(x+1);
				}
				else{
					v[y].erase(x);
					v[y].erase(x+1);
				}
			}
		}
		else{
			/*for(i=1;i<=n;i++){
				for(j=1;j<=m;j++){
					printf("%d ",a[i][j]);
				}
				puts("");
			}*/
			area=0;
			l=1;
			r=m+1;
			for(i=x;i>0&&a[i][y];i--){
				//printf("y=%d",y);
				//for(it=h[i].begin();it!=h[i].end();it++) printf("%d",*it);
				//puts("");
				l=max(*(--h[i].upper_bound(y)),l);
				r=min(*(h[i].upper_bound(y)),r);
				//printf("now1:%d %d %d\n",i,l,r);
				if((x-i+1)*(r-l)>area) area=(x-i+1)*(r-l);
			}
			l=1;
			r=m+1;
			for(i=x;i<=n&&a[i][y];i++){
				l=max(*(--h[i].upper_bound(y)),l);
				r=min(*(h[i].upper_bound(y)),r);
				//printf("now2:%d %d %d\n",i,l,r);
				if((i-x+1)*(r-l)>area) area=(i-x+1)*(r-l);
			}
			l=1;
			r=n+1;
			for(i=y;i>0&&a[x][i];i--){
				l=max(*(--v[i].upper_bound(x)),l);
				r=min(*(v[i].upper_bound(x)),r);
				//printf("now3:%d %d %d\n",i,l,r);
				if((y-i+1)*(r-l)>area) area=(y-i+1)*(r-l);
			}
			l=1;
			r=n+1;
			for(i=y;i<=m&&a[x][i];i++){
				l=max(*(--v[i].upper_bound(x)),l);
				r=min(*(v[i].upper_bound(x)),r);
				//printf("now4:%d %d %d\n",i,l,r);
				if((i-y+1)*(r-l)>area) area=(i-y+1)*(r-l);
			}
			printf("%d\n",area);
		}
	}
	return 0;
}