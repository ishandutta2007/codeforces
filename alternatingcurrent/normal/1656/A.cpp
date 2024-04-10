#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

int T;
int n;
int a[200200];

int main(){
	ios::sync_with_stdio(false);
	cin >> T;
	while(T--){
		cin >> n;
		rep(i, n)
			cin >> a[i];
		int mn = 0, mx = 0;
		rep(i, n){
			if(a[i] < a[mn])
				mn = i;
			if(a[i] > a[mx])
				mx = i;
		}
		cout << mn + 1 << " " << mx + 1 << endl;
	}
	return 0;
}