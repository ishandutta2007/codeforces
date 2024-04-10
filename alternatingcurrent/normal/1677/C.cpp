#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

int T;
int n;
int a[100100], b[100100];
int to[100100];
bool done[100100];

int main(){
	ios::sync_with_stdio(false);
	cin >> T;
	while(T--){
		cin >> n;
		rep(i, n)
			cin >> a[i], a[i]--;
		rep(i, n)
			cin >> b[i], b[i]--;
		rep(i, n)
			to[a[i]] = b[i];
		rep(i, n)
			done[i] = 0;
		int cntodd = 0;
		rep(i, n){
			if(!done[i]){
				int nowpos = i;
				int cnt = 0;
				do{
					done[nowpos] = 1;
					cnt++;
					nowpos = to[nowpos];
				}while(nowpos != i);
				cntodd += cnt & 1;
			}
		}
		int len = (n - cntodd) >> 1;
		long long ans = 0;
		for(int i = n; i >= n - len + 1; i--)
			ans += i + i;
		for(int i = 1; i <= len; i++)
			ans -= i + i;
		cout << ans << endl;
	}
	return 0;
}