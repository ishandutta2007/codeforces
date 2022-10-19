#include<cstdio>
using namespace std;
int n,x,a,f[400039],ans,head;
inline void read(int &x){
	char s=getchar();x=0;
	while(s<'0'||s>'9') s=getchar();
	while(s>='0'&&s<='9') x=(x<<3)+(x<<1)+(s^48),s=getchar();
}
inline void print(int x){
	if(x>9) print(x/10);
	putchar(x%10+48);
}
int main(){
	register int i;
	scanf("%d%d",&n,&x);
	for(i=1;i<=n;i++){
		read(a);
		f[a%x]++;
		while(f[head%x]>head/x) head++;
		print(head);putchar('\n');
	}
	return 0;
}