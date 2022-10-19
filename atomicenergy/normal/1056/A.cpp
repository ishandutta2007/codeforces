#include <iostream>
#include <set>
using namespace std;

int main() {
	int n;
	cin >> n;
	set<int> poss;
	for(int i=0; i<n; i++){
		int m;
		cin >> m;
		set<int> s;
		for(int j=0; j<m; j++){
			int x;
			cin >> x;
			if(i==0 || poss.count(x)){
				s.insert(x);
			}
		}
		poss = s;
	}
	for(int x : poss){
		cout << x << " ";
	}
	return 0;
}