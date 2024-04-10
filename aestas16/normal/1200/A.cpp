//qaqaqwqwq
#include <cstdio>

#define N 100000

template<class T>void fr(T &a) {
    T s=0,w=1;a=0;char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-')w=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
    a=w*s;
}
template<class T>T in() {T a;fr(a);return a;}

char str[N+10];
bool book[15];

int main() {
	int n=in<int>();
	for(int i=1;i<=n;i++) scanf("%c",&str[i]);
	for(int i=1;i<=n;i++) 
		if(str[i]=='L') {
			for(int i=0;i<=9;i++)
				if(!book[i]){book[i]=true;break;}
		} else if(str[i]=='R') {
			for(int i=9;i>=0;i--)
				if(!book[i]) {book[i]=true;break;}
		} else book[str[i]-'0']=false;
	for(int i=0;i<=9;i++) printf("%d",book[i]);
	return 0;
}