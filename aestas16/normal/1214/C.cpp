#include <cstdio>
#include <stack>
 
using namespace std;
 
template<class T>void fr(T &a) {
	T s=0,w=1;a=0;char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-')w=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
	a=w*s;
}
template<class T>T in() {T a;fr(a);return a;}
#define R() in<int>()
 
stack<char>s;
 
char str[200010];
 
int main() {
	int n,f=0;scanf("%d\n\n",&n);
	if(n%2)return !printf("No");
	scanf("%s",str);
	for(int i=0;i<n;i++) {
		char c=str[i];
		if(c==')') {
			if(s.empty()&&!f)f=1;
			else if(s.empty()&&f)return !printf("No");
			else s.pop();
		}
		else s.push(c);
	}
	if(s.size()>1)return !printf("No");
	return !printf("Yes");
}