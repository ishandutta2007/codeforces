#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;

int T;
int n, m;
int a[200200];
int b[200200];

int main(){
	ios::sync_with_stdio(false);
	cin >> T;
	while(T--){
		cin >> n >> m;
		rep(i, n * m)
			cin >> a[i], b[i] = a[i];
		rep(i, n)
			sort(b + i * m, b + (i + 1) * m);
		int ind0 = -1, ind1 = -1;
		rep(i, n){
			vector<int> diff;
			rep(j, m)
				if(a[i * m + j] != b[i * m + j]){
					diff.push_back(j);
				}
			if((int)diff.size() > 2){
				ind0 = ind1 = -2;
				break;
			} else if((int)diff.size() == 2){
				if(ind0 < 0){
					ind0 = diff[0], ind1 = diff[1];
				} else {
					if(ind0 != diff[0] || ind1 != diff[1]){
						ind0 = ind1 = -2;
						break;
					}
				}
			} else {
				if(ind0 >= 0){
					if(a[i * m + ind0] != a[i * m + ind1]){
						ind0 = ind1 = -2;
						break;
					}
				}
			}
		}
		if(ind0 >= 0){
			bool ok = 1;
			rep(i, n){
				swap(a[i * m + ind0], a[i * m + ind1]);
				rep(j, m - 1)
					if(a[i * m + j] > a[i * m + j + 1])
						ok = 0;
				if(!ok)
					break;
			}
			if(!ok)
				ind0 = ind1 = -2;
		}
		if(ind0 == -2)
			cout << "-1" << endl;
		else if(ind0 == -1)
			cout << "1 1" << endl;
		else
			cout << ind0 + 1 << " " << ind1 + 1 << endl;
	}
	return 0;
}