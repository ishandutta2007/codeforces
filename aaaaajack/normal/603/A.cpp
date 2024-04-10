#include<cstdio>
#include<algorithm>
#define N 100100
using namespace std;
char s[N];
int main(){
	int n,now=1,add=0;
	scanf("%d",&n);
	scanf("%s",s);
	for(int i=1;i<n;i++){
		if(s[i]!=s[i-1]) now++;
		else add++;
	}
	printf("%d\n",now+min(add,2));
	return 0;
}