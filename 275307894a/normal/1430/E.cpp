#include<cstdio>
#include<vector>
using namespace std;
int n,m,k,x,y,z,h[200039],a[200039],f[200039];
vector<int> sf[139];
char s;
long long ans;
inline void get(int x){while(x<=n)f[x]++,x+=x&-x;}
inline int find(int x){int ans=0;while(x) ans+=f[x],x-=x&-x;return ans;}
int main(){
	register int i;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		s=getchar();
		while(s<'a'||s>'z') s=getchar();
		a[n-i+1]=s;sf[s].push_back(i);
	}
	for(i=1;i<=n;i++)a[i]=sf[a[i]][h[a[i]]++];
	for(i=1;i<=n;i++){
		ans+=find(n)-find(a[i]);
		get(a[i]);
	}
	printf("%lld\n",ans);
}