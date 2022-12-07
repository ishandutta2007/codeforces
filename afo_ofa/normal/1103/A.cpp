#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool Finish_read;
template<class T>inline void read(T &x){Finish_read=0;x=0;int f=1;char ch=getchar();while(!isdigit(ch)){if(ch=='-')f=-1;if(ch==EOF)return;ch=getchar();}while(isdigit(ch))x=x*10+ch-'0',ch=getchar();x*=f;Finish_read=1;}
template<class T>inline void print(T x){if(x/10!=0)print(x/10);putchar(x%10+'0');}
template<class T>inline void writeln(T x){if(x<0)putchar('-');x=abs(x);print(x);putchar('\n');}
template<class T>inline void write(T x){if(x<0)putchar('-');x=abs(x);print(x);}
/*================Header Template==============*/
char s[1005];
int n,vis[5][5],c0,c1;
int main() {
	scanf("%s",s+1),n=strlen(s+1);
	for(int i=1;i<=n;++i) {
		if(s[i]=='0') {
			if(c0&1)
				puts("3 1");
			else
				puts("1 1");
			c0++;
		}
		else {
			if(c1&1)
				puts("4 1");
			else
				puts("4 3");
			c1++;
		}
	}
}