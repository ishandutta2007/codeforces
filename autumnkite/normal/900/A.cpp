#include <cstdio>

using namespace std;

int main(){
	int n,s1=0,s2=0,x,y;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&x,&y);
		if(x>0) s1++; else s2++;
	}
	printf((s1<2||s2<2)?"Yes":"No");
	return 0;
}