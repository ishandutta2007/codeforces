#include <iostream>
#include <vector>
using namespace std;

int parents[100 * 1000 + 1];

int Find(int a) {
	if(parents[a] == 0)
		return a;
	return (parents[a] = Find(parents[a]));
}

int main() {
	int nbs;
	cin >> nbs;
	
	int tot = nbs;
	
	for(int i = 1;i <= nbs;i++) {
		int v;
		cin >> v;
		if(Find(v) != Find(i)) {
			parents[Find(v)] = Find(i);
			tot--;
		}
	}
	
	cout << tot << endl;
    return 0;
}