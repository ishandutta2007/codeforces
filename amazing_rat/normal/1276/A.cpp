#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
const int maxn=(2e5)+10;
int T,n;
char s[maxn];
int l[maxn],r[maxn];
vector<int> ans;
bool ck1(int i) {
	return 2<=i&&i<n&&s[l[i]]=='o'&&s[i]=='n'&&s[r[i]]=='e';
}
bool ck2(int i) {
	return 2<=i&&i<n&&s[l[i]]=='t'&&s[i]=='w'&&s[r[i]]=='o';	
}
void del(int i) {
	r[l[i]]=r[i];
	l[r[i]]=l[i];
	ans.push_back(i);
}
int main() {
	//freopen("1.txt","r",stdin);
	read(T);
	while (T--) {
		scanf("%s",s+1);
		n=strlen(s+1);
		for (int i=1;i<=n;i++) l[i]=i-1,r[i]=i+1;
		ans.clear();
		for (int i=2;i<n;i++) {
			if (ck2(i)&&ck1(i+2)) del(i+1);
			else if (ck1(i)||ck2(i)) del(i);
		}
		printf("%d\n",ans.size());
		sort(ans.begin(),ans.end());
		for (int i=0;i<ans.size();i++) printf("%d ",ans[i]);
		printf("\n");
	}
	return 0;
}
/*
  REMEMBER:
  1. Think TWICE, Code ONCE!
  Are there any counterexamples to your algo?
    
  2. Be careful about the BOUNDARIES!
  N=1? P=1? Something about 0?
    
  3. Do not make STUPID MISTAKES!
  Array size? Integer overflow? Time complexity? Memory usage? Precision error?
*/