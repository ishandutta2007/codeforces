#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
int qmin(int a, int b){
	return (a < b) ? a : b;
}

int n, k;
int pos[300300];
int dpl[300300], dpr[300300];

int main(){
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	while(T--){
		cin >> n >> k;
		rep(i, n) dpl[i] = dpr[i] = 0x3f3f3f3f;
		rep(i, k){
			cin >> pos[i];
			pos[i]--;
		} 
		rep(i, k){
			int tmp;
			cin >> tmp;
			dpl[pos[i]] = qmin(dpl[pos[i]], tmp);
			dpr[pos[i]] = qmin(dpr[pos[i]], tmp);
		}
		for(int i = 1; i < n; i++)
			dpl[i] = qmin(dpl[i], dpl[i - 1] + 1);
		for(int i = n - 2; i >= 0; i--)
			dpr[i] = qmin(dpr[i], dpr[i + 1] + 1);
		rep(i, n)
			cout << qmin(dpl[i], dpr[i]) << " ";
		cout << endl;
	}
	return 0;
}