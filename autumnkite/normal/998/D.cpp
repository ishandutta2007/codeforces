#include <cstdio>
using namespace std;
int n;
int ans[12]={0,4,10,20,35,56,83,116,155,198,244,292};
int main(){
	scanf("%d",&n);
	n<12?printf("%d",ans[n]):printf("%I64d",292+1ll*(n-11)*49);
}