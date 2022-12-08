#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long lint;
int q;
lint a=34LL,b=32LL,c=2LL;
lint f[100001];
string A = "What are you doing while sending $";
string B = "$? Are you busy? Will you send $";
string C = "$?";
string f0 = "What are you doing at the end of the world? Are you busy? Will you save us?";
lint min(lint a, lint b) {
    return a < b? a : b;}
void LEN() {
	f[0] = 75LL;
	for(int i = 1; i <= 100000; i++) f[i] = min((lint)1e18+1LL, a + f[i-1] + b + f[i-1] + c);
}
char find(lint n, lint k) {
	if(k >= f[n]) return '.';
	if(n == 0LL) return f0[k];
	if(k < a) return A[k];
	if(k < a + f[n-1]) return find(n-1, k-a);
	if(k < a + f[n-1] + b) return B[k-a-f[n-1]];
	if(k < a + f[n-1] + b + f[n-1]) return find(n-1, k-a-f[n-1]-b);
	return C[k-a-f[n-1]-b-f[n-1]];
}
int main() {
	LEN();
	cin >> q;
	while(q--) {
		lint n, k;
		cin >> n >> k;
		char ans = find(n, k-1LL);
		cout << (ans == '$' ? '"' : ans);
	}
	return 0;
}