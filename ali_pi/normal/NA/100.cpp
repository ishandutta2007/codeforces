#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 1e6, M = 1e5;
bool a[N];
int am[100];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int q; 
	cin >> q;

	for(int i=0; i<q; i++){
		int t;
		cin >> t;

		if(t==1){
			int u;
			cin >> u;
			a[u] = true;

			for(int j=1; j<100; j++)
				if(u%j==0)
					am[j] = max(am[j], u);
		}
		if(t==2){
			int x, k ,s;
			cin >> x >> k >> s;

			int ans = -1;

			if(x%k==0 && k>=100){
				for(int j=k; j+x<=s; j+=k)
					if(a[j])
						ans = max(ans, j^x);
			}
			if(x%k==0 && k<100){
				for(int j=min(am[k]+x, s); j>=0; j--){
					int j1 = j^x;

					if(j1%k==0 && (j1+x)<=s && a[j1]){
						ans = j;
						break;
					}
				}
			}

			if(ans>=0)
				ans ^= x;

			cout << ans << endl;
		}
	}

	return 0;
}