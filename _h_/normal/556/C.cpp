#include <iostream>
using namespace std;
int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	int n,k, l=-1,m,a;
	cin >> n >> k;
	for(int i = 0; i < k; ++i){
		cin >> m >> a;
		if(a == 1){
			for(int j = 1; j < m; ++j){
				cin >> a;
				if(l == -1 && a != j+1){
					l = j;
				}
			}
			if(l == -1)
				l = m;
		} else for(int j = 1; j < m; ++j)
				cin >> a;
	}
	cout << n - k - l + 1 + n - l << endl;
}