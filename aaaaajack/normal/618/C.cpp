#include<cstdio>
#include<cstdlib>
#define N 100100
using namespace std;
long long x[N],y[N];
inline long long len2(int a,int b){
	return (x[a]-x[b])*(x[a]-x[b])+(y[a]-y[b])*(y[a]-y[b]);
}
inline long long cross(int a,int b){
	return abs((x[a]-x[1])*(y[b]-y[1])-(y[a]-y[1])*(x[b]-x[1]));
}
int main(){
	int lst,bst=-1;
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%I64d%I64d",&x[i],&y[i]);
	lst=2;
	for(int i=3;i<=n;i++){
		if(len2(1,i)<len2(1,lst)) lst=i;
	}
	for(int i=2;i<=n;i++){
		if(i==lst) continue;
		else if(bst==-1&&cross(lst,i)>0) bst=i;
		else{
			if(cross(lst,i)>0&&cross(lst,i)<cross(lst,bst)){
				bst=i;
			}
		}
	}
	printf("%d %d %d\n",1,lst,bst);
	return 0;
}