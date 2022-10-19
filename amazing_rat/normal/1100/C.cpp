#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while ('0'>ch||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do {(t*=10)+=ch-'0';ch=getchar();} while ('0'<=ch&&ch<='9'); t*=f;
}
const double pi=asin(1.0);
double n,r,x,ans;
int main() {
	//freopen("1.txt","r",stdin);
	scanf("%lf %lf",&n,&r);
	x=sin(pi*2.0/n);
	ans=r*x/(1.0-x);
	printf("%.8lf\n",ans);
	return 0;
}