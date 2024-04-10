#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

int n;
int a[111];
int sum;
bool isok(int val){
	for(int i = 2; i * i <= val; i++)
		if(val % i == 0)
			return 1;
	return 0;
}

int main(){
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	while(T--){
		cin >> n;
		rep(i, n)
			cin >> a[i];
		sum = 0;
		rep(i, n)
			sum += a[i];
		if(isok(sum)){
			cout << n << endl;
			rep(i, n)
				cout << i + 1<<" ";
			cout << endl;
		} else {
			bool ok = 0;
			rep(i, n)
				if(isok(sum - a[i])){
					cout << n - 1 << endl;
					rep(j, n)
						if(j != i)
							cout << j + 1 <<" ";
					cout << endl;
					ok = 1;
					break;
				}
			if(!ok){
				rep(i, n){
					rep(j, n){
						if(isok(sum - a[i] - a[j])){
							cout << n - 2 << endl;
							rep(k, n)
								if(k != i && k != j)
									cout << k + 1 <<" ";
							cout << endl;
							ok = 1;
							break;
						}
					}
					if(ok)
						break;
				}
			}
		}
	}
	return 0;
}