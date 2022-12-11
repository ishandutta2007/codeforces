#include <iostream>
using namespace std;

int nbReqs;

int tree[(1 << 21)];

int update(int node, long long num, int aj, int prof) {
	tree[node] += aj;
	if(num == 0 && prof <= 0)
		return tree[node];	
	return update(node * 2 + (num % 2), num / 10, aj, prof - 1);
}

int main() {
	cin >> nbReqs;
	
	for(int iReq = 0;iReq < nbReqs;iReq++) {
		char type;
		long long arg;
		cin >> type >> arg;
		if(type == '+') {
			update(1, arg, 1, 20);
		}
		else if(type == '-') {
			update(1, arg, -1, 20);
		}
		else {
			cout << update(1, arg, 0, 20) << endl;
		}
	}
	return 0;
}