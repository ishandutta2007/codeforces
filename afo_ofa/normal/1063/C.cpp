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
int n;
inline int ask(int x,int y) {
	printf("%d %d\n",x,y);
	fflush(stdout);
	char s[6];
	scanf("%s",s+1);
	return s[1]=='b';
}
int main() {
	read(n),n--;
	int flg=ask(0,1),l=0,r=1e9;
	while(n--) {
		int mid=(l+r)>>1;
		ask(mid,1)==flg?l=mid:r=mid;
	}
	printf("%d 0 %d 2\n",l,r);
}