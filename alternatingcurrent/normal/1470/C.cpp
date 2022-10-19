#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

int n, k;

int main(){
	ios::sync_with_stdio(false);
	cin >> n >> k;
	int s = sqrt(n);
	cout << "? 1" << endl;
	int a;
	cin >> a;
	for(int now = 0; now < n; now += s){
		cout << "? " << now+1 << endl;
		long long ans;
		cin >> ans;
		if(ans != k){
			if(ans < k){
				for(int j = now+1; ; j = (j + 1) % n){
					cout << "? " << j+1 << endl;
					cin >> ans;
					if(ans == k){
						cout << "! " << j+1 << endl;
						return 0;
					}
				}
			} else {
				for(int j = (now-1 + n) % n; ; j = (j - 1 + n) % n){
					cout << "? " << j+1 << endl;
					cin >> ans;
					if(ans == k){
						cout << "! " << j+1 << endl;
						return 0;
					}
				}
			}
		}
	}
	for(int now = 1; now < n; now += s){
		cout << "? " << now+1 << endl;
		long long ans;
		cin >> ans;
		if(ans != k){
			if(ans < k){
				int nxt = now + s;
				cout << "? " << nxt+1 << endl;
				cin >> ans;
				if(ans < k){
					now = nxt;
					nxt = now + s;
					cout << "? " << nxt+1 << endl;
					cin >> ans;
					if(ans < k) now = nxt;
				}
				for(int j = now+1; ; j = (j + 1) % n){
					cout << "? " << j+1 << endl;
					cin >> ans;
					if(ans == k){
						cout << "! " << j+1 << endl;
						return 0;
					}
				}
			} else {
				for(int j = (now-1 + n) % n; ; j = (j - 1 + n) % n){
					cout << "? " << j+1 << endl;
					cin >> ans;
					if(ans == k){
						cout << "! " << j+1 << endl;
						return 0;
					}
				}
			}
		}
	}
	return 0;
}