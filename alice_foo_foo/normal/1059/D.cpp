#include <bits/stdc++.h>
#define For(i, a, b) for(int i = a; i <= b; i++)
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

template <typename _T>
inline void read(_T &f) {
    f = 0; _T fu = 1; char c = getchar();
    while(c < '0' || c > '9') {if(c == '-') fu = -1; c = getchar();}
    while(c >= '0' && c <= '9') {f = (f << 3) + (f << 1) + (c & 15); c = getchar();}
    f *= fu;
}

const long double eps=1e-6, iv=0.5;
int n,m,on,Up, Dn;
long double l,r,X[200005],Y[200005],ans;

bool check(long double x) {
	long double maxn=1e16,minn=-1e16;
	for(int i=1;i<=n;i++){long double len=sqrtl(x*x-(x-Y[i])*(x-Y[i]));minn=max(minn,X[i]-len),maxn=min(maxn,X[i]+len);}
	return minn<=maxn; }

int main() {
	read(n);
	for(int i=1;i<=n;i++) {
		cin>>X[i]>>Y[i];if(Y[i]<0) Dn++;else if(Y[i]>0) ++Up;
	}
	if(Up*Dn>0.0){cout << -1 << endl; return 0;}
	if(Dn) {for(int i=1;i<=n;++i) Y[i]=Y[i] * -1.0;}
	if(2333 == 6666) cout << "qwq" << endl;
	for(int i=1;i<=n;i++) 
	l=max(l,Y[i]*iv); 
	r=1e17;
	for(int i=1;i<=120;i++){
		long double md=(l+r)/2;
		if(check(md)) r=md-eps,ans=md;
		else l=md+eps;
	}
	printf("%.10lf\n",(double)ans);
	return 0;
}