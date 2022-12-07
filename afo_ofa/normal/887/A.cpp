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
string s;
int main() {
	cin>>s;
	if(s.length()<7) {
		puts("no");
		return 0;
	}
	int tot=-1;
	for(int i=0;i<s.length();i++) {
		if(s[i]=='1'&&tot==-1)
			tot=0;
		if(tot==-1)
			continue;
		if(s[i]=='0')
			tot++;
	}
	if(tot<6) {
		puts("no");
		return 0;
	}
	puts("yes");
	return 0;
}