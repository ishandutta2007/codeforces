#include<cstdio>
using namespace std;
int x,y,z,t,fs[27],n;
char s;
int main(){
//	freopen("1.in","r",stdin);
	register int i;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(i=0;i<26;i++) fs[i]=0;
		while(n--){
			s=getchar();
			while(s<'a'||s>'z') s=getchar();
			fs[s-'a']++;
		}
		for(i=0;i<26;i++) while(fs[i]--) putchar(i+97);putchar('\n');
	}
}