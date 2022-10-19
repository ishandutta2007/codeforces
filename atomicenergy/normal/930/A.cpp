#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> l;
	map<int, int> c;
	l.push_back(0);
	c[0]++;
	for(int i=0; i<n -1; i++){
		int x;
		cin >> x;
		int y = l[x-1] + 1;
		l.push_back(y);
		c[y]++;
	}
	int ans = 0;
	for(auto p : c){
		if(p.second %2 == 1){
			
			ans++;
		}
	}
	cout << ans << endl;
	return 0;
}