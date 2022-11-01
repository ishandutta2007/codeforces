#include<bits/stdc++.h>
#define mod 1000000007
#define ll long long
using namespace std;
int read() {
	char c=getchar();while(c!='-'&&!isdigit(c)) c=getchar();
	int neg=0;if(c=='-') neg=1,c=getchar();
	int num=0;while(isdigit(c)) num=num*10+c-'0',c=getchar();
	return neg?-num:num;
}
ll x[1000001], y[1000001];
ll cross(ll x1, ll y1, ll x2, ll y2) {
	x1 = (x1%mod+mod)%mod, y1 = (y1%mod+mod)%mod;
	x2 = (x2%mod+mod)%mod, y2 = (y2%mod+mod)%mod;
	return ((x1*y2-x2*y1)%mod+mod)%mod;
}
ll nomod_cross(ll x1, ll y1, ll x2, ll y2) {
	return x1*y2 - x2*y1;
}
ll S[1000001], iS[1000001];
ll prex[1000001], prey[1000001];
int main() {
	int n = read();
	x[1] = read(), y[1] = read();
	for (int i = 2; i <= n; i++) x[n-i+2] = read(), y[n-i+2] = read();
	for (int i = 1; i <= n; i++) x[i+n] = x[i], y[i+n] = y[i];
	ll S0 = 0;
	for (int i = 1; i <= n; i++) S0 += nomod_cross(x[i],y[i],x[i+1],y[i+1]);
	for (int i = 1; i < n * 2; i++) S[i] = cross(x[i], y[i], x[i+1], y[i+1]), iS[i] = S[i] * i % mod;
	for (int i = 1; i <= n * 2; i++) prex[i] = (prex[i-1] + mod + x[i]%mod) % mod, prey[i] = (prey[i-1] + mod + y[i]%mod) % mod;
	for (int i = 1; i < n * 2; i++) S[i] = (S[i] + S[i-1]) % mod, iS[i] = (iS[i] + iS[i-1]) % mod;
	int p = 1, ans = 0, cnt = 0;
	long long ns = 0;
	for (int i = 1; i <= n; i++) {
		ll add = nomod_cross(x[p]-x[i],y[p]-y[i],x[p+1]-x[i],y[p+1]-y[i]);
		while (ns+add<(S0+1)/2) ns+=add,++p,add=nomod_cross(x[p]-x[i],y[p]-y[i],x[p+1]-x[i],y[p+1]-y[i]);
		ans = (ans+p*(mod+S[p]-S[i-1])+mod-(mod+iS[p]-iS[i-1])%mod+mod-cross(x[i],y[i],prex[p]-prex[i-1],prey[p]-prey[i-1])%mod)%mod;
		ns -= nomod_cross(x[p]-x[i+1],y[p]-y[i+1],x[i]-x[i+1],y[i]-y[i+1]);
		cnt = (cnt+p-i-1)%mod;
	}
	cout << (S0%mod*cnt%mod+mod-2ll*ans%mod)%mod << endl;
}