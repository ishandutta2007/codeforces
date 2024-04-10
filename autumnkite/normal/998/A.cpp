#include <cstdio>
#include <algorithm>
using namespace std;
const int N=15;
int n,s1,s2;
struct node{
	int v,id;
	bool operator <(const node&b)const{return v<b.v;}
}a[N];
int main(){
	scanf("%d",&n);
	for (register int i=1;i<=n;++i) scanf("%d",&a[i].v),a[i].id=i;
	sort(a+1,a+1+n),s1=a[1].v;
	for (register int i=2;i<=n;++i) s2+=a[i].v;
	if (s1==s2||!s2) printf("-1");else printf("1\n%d",a[1].id);
}