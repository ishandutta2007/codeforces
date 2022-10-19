#include <vector>
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
#include<algorithm>
#include<map>
#include<bitset>
#define I inline
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define l(x) x<<1
#define r(x) x<<1|1
#define re register
#define ll long long
#define db long double
#define N 3000
#define eps (1e-6)
#define mod 1000000007
#define ba 1039
using namespace std;
int n,m,k,a[N+5];ll ans,now;map<ll,int> s;
I ll calc(int *a){ans=0;for(int i=1;i<=2*n;i++) ans=(ans*ba+a[i])%mod;return ans;}
I void swap(int &x,int &y){x^=y^=x^=y;}
struct ques{int a[N+5],w;}tmp;
queue<ques> q;
int main(){
	re int i;scanf("%d",&n);for(i=1;i<=2*n;i++) tmp.a[i]=i;tmp.w=1;s[calc(tmp.a)]=1;q.push(tmp);
	while(!q.empty()){
		tmp=q.front();q.pop();tmp.w++;
		for(i=1;i<=n;i++) swap(tmp.a[i],tmp.a[i+n]);now=calc(tmp.a);!s[now]&&(q.push(tmp),s[now]=tmp.w);
		for(i=1;i<=n;i++) swap(tmp.a[i],tmp.a[i+n]);for(i=1;i<=n;i++) swap(tmp.a[i*2-1],tmp.a[i*2]);now=calc(tmp.a);!s[now]&&(q.push(tmp),s[now]=tmp.w);
	}
	for(i=1;i<=2*n;i++)scanf("%d",&a[i]);printf("%d\n",s[calc(a)]-1);
}