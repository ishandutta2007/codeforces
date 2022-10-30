#include<cstdio>
#define N 310
bool r[N][N];
bool used[N];
int a[N];
int main(){
	int i,j,k,n,l;
	bool space=false;
	char s[N];
	scanf("%d",&n);
	for(i=0;i<n;i++) scanf("%d",&a[i]);
	for(i=0;i<n;i++){
		scanf("%s",s);
		for(j=0;j<n;j++) r[i][j]=(s[j]=='1');
		r[i][i]=true;
	}
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			for(k=0;k<n;k++){
				if(r[j][i]&&r[i][k]) r[j][k]=true;
			}
		}
	}
	for(i=0;i<n;i++){
		if(space) putchar(' ');
		else space=true;
		l=-1;
		for(j=0;j<n;j++){
			if(used[j]||!r[i][j]) continue;
			if(l==-1||a[j]<a[l]) l=j;
		}
		used[l]=true;
		printf("%d",a[l]);
	}
	putchar('\n');
	return 0;
}