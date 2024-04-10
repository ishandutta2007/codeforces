#include<cstdio>
#include<cstring>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define min(a,b) ((a)<(b)?(a):(b))
int a[200005]; 
int main(){
	int n; scanf("%d",&n);
	rep(i,1,n)scanf("%d",&a[i]);
	rep(i,1,n){
		if(a[i]<0){puts("NO"); return 0;}
		if(a[i]&1)a[i+1]--;
	}
	if(a[n+1])puts("NO");
	else puts("YES");
	return 0;
}