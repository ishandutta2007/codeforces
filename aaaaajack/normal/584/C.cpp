#include<cstdio>
#define N 100100
using namespace std;
char a[N],b[N];
int main(){
	int n,t,cnt=0,diff,now=0;
	scanf("%d%d",&n,&t);
	t=n-t;
	scanf("%s%s",a,b);
	for(int i=0;i<n;i++){
		if(a[i]==b[i]) cnt++;
	}
	diff=t-cnt;
	if(n-cnt<diff*2){
		puts("-1");
		return 0;
	}
	for(int i=0;i<n;i++){
		if(a[i]==b[i]){
			if(t){
				t--;
				putchar(a[i]);
			}
			else{
				char c;
				for(c='a';c==a[i]||c==b[i];c++);
				putchar(c);
			}
		}
		else if(diff>0){
			if(now==0) putchar(a[i]);
			else{
				putchar(b[i]);
				diff--;
			}
			now^=1;
		}
		else{
			char c;
			for(c='a';c==a[i]||c==b[i];c++);
			putchar(c);
		}
	}
	return 0;
}