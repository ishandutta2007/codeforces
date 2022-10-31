#include<cstdio>
#define N 200100
using namespace std;
int a[N],b[N];
int main(){
	int n,st;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
		if(!a[i]) n--,i--;
	}
	n++;
	for(int i=0;i<n;i++){
		scanf("%d",&b[i]);
		if(!b[i]) n--,i--;
		if(b[i]==a[0]) st=i;
	}
	bool flag=true;
	for(int i=0;i<n;i++){
		if(a[i]!=b[(st+i)%n]) flag=false;
	}
	if(flag) puts("YES");
	else puts("NO");
	return 0;
}