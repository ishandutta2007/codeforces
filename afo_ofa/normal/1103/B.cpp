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
char op[10];
inline int Query(int x,int y) {
	printf("? %d %d\n",x,y),fflush(stdout),scanf("%s",op);
	return op[0]=='x';
}
inline void Answer(int x) {
	printf("! %d\n",x),fflush(stdout);
}
int main() {
	while(~scanf("%s",op)&&strcmp(op,"end")) {
		if(op[0]=='m')
			return 0;
		int g=0;
		for(int i=1;i<=1e9;i<<=1) {
			int p=Query(i,i<<1);
			if(p) {
				g=i;
				break;
			}
		}
		if(!g)
			Answer(1);
		else {
			int ans=-1;
			for(int l=g,r=g<<1,mid;l<=r;Query(mid=(l+r)>>1,g<<1)?l=mid+1:(r=mid-1,ans=mid));
			if(~ans)
				Answer(ans);
			else
				Answer(Query(g<<1,g)?g:g<<1);
		}
	}
}