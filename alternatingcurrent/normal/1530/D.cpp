#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

int T;
int n;
int a[200200], from[200200], b[200200];
bool yes[200200];

int main(){
	ios::sync_with_stdio(false);
	cin >> T;
	while(T--){
		cin >> n;
		rep(i, n) cin >> a[i], a[i]--;
		rep(i, n) yes[i] = 0, from[i] = -1;
		rep(i, n){
			if(from[a[i]] >= 0) yes[from[a[i]]] = 0;
			from[a[i]] = i;
			yes[i] = 1;
		}
		int nowpos = 0;
		int ans = 0;
		rep(i, n){
			ans += yes[i];
			if(!yes[i]){
				while(from[nowpos] >= 0){
					nowpos++;
				}
				from[nowpos] = i;
				if(nowpos == i)
					swap(from[nowpos], from[a[i]]);
			}
		}
		rep(i, n)
			b[from[i]] = i;
		cout << ans << endl; 
		rep(i, n)
			cout << b[i] + 1 << " ";
		cout << endl;
	}
	return 0;
}