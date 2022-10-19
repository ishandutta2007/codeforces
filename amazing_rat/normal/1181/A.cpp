#include <bits/stdc++.h>
#define dbug(x) cout<<#x<<"="<<x<<endl
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while ('0'>ch||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do {(t*=10)+=ch-'0';ch=getchar();} while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
ll x,y,z,ans;
int main() {
	//freopen("1.txt","r",stdin);
	read(x); read(y); read(z);
	ans=(x+y)/z;
	printf("%lld ",ans);
	if (x/z+y/z==ans) printf("0\n");
	else printf("%lld\n",min(z-x%z,z-y%z));
	return 0;
}