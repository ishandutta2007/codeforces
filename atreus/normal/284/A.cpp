#include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define MP make_pair


using namespace std;

bool root (int x, int p){
	long long k = 0;
	for (int i = 1; i <= p - 2; i++){
		k *= x;
		k += x - 1;
		k %= p;
		if (k == 0)
			return false;
	}
	k *= x;
	k += x - 1;
	k %= p;
	if (k != 0)
		return false;
	return true;
}

int main (){
	ios_base::sync_with_stdio(false);
	int p;
	cin >> p;
	int cnt = 0;
	for (int i = 1; i < p; i++){
		if (root(i, p)){
			cnt ++;
//			cout << i << " ";
		}
	}
	cout << cnt << endl;
}