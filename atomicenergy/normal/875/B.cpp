#include <iostream>
#include <vector>
#include <map>
using namespace std;



int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;
	cin >> n;
	int mx = n;
	vector<bool> v;
	for(int i=0; i<n; i++){
		v.push_back(false);
	}
	int cnt = n;
	for(int i=0; i<n; i++){
		printf("%d ", mx-cnt+1);
		int x;
		cin >> x;
		v[x-1] = true;
		while(mx > 0 && v[mx-1] == true){
			mx--;
		}
		cnt--;
	}
	printf("1\n");
}