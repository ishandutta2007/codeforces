#pragma GCC optimize(3)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool Finish_read;
template<class T>inline void read(T &x){Finish_read=0;x=0;int f=1;char ch=getchar();while(!isdigit(ch)){if(ch=='-')f=-1;if(ch==EOF)return;ch=getchar();}while(isdigit(ch))x=x*10+ch-'0',ch=getchar();x*=f;Finish_read=1;}
template<class T>inline void print(T x){if(x/10!=0)print(x/10);putchar(x%10+'0');}
template<class T>inline void writeln(T x){if(x<0)putchar('-');x=abs(x);print(x);putchar('\n');}
template<class T>inline void write(T x){if(x<0)putchar('-');x=abs(x);print(x);}
/*================Header Template==============*/
int a,q;
ll ans;
char s[105];
int main() {
	scanf("%s",s+1);
	int n=strlen(s+1);
	for(int i=1;i<=n;i++) {
		for(int j=i+1;j<=n;j++) {
			for(int k=j+1;k<=n;k++) {
				if(s[i]=='Q'&&s[j]=='A'&&s[k]=='Q')
					ans++;
			}
		}
	}
	writeln(ans);
}