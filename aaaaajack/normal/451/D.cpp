#include<cstdio>
#include<algorithm>
#include<cstring>
#define N 100100
using namespace std;
char s[N];
int main(){
	scanf("%s",s);
	long long a[2]={},b[2]={};
	long long ecnt=0,ocnt=0;
	int i;
	for(i=0;s[i];i++){
		if(s[i]=='a'){
			a[i&1]++;
			ocnt+=a[i&1];
			ecnt+=a[(i&1)^1];
		}
		else{
			b[i&1]++;
			ocnt+=b[i&1];
			ecnt+=b[(i&1)^1];
		}
	}
	printf("%I64d %I64d\n",ecnt,ocnt);
	return 0;
}