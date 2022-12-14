#include <bits/stdc++.h>

using namespace std;

const int maxn = 5e3 + 100;
stack <int> v[maxn];
int a[maxn];

int main(){
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	sort (a + 1, a + n + 1);
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			if (v[j].empty() || v[j].top() < a[i]){
				v[j].push(a[i]);
				break;
			}
		}
	}
	int cnt = 0;
	for (int i = 1; i <= n; i++){
		if (!v[i].empty()){
			cnt ++;
		}
	}	
	cout << cnt << endl;
}