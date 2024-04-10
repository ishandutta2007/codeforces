#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>

using namespace std;

#define MP make_pair
#define PB push_back
#define L first
#define R second

typedef pair<int, int> pie;

bool check(vector <int> a){
	sort(a.begin(), a.end());
	if (a[3] - a[0] != 1.0 * (a[1] + a[2]) / 2)
		return false;
	if (a[3] - a[0] != 1.0 * (a[0] + a[1] + a[2] + a[3]) / 4)
		return false;
	return true;
}

vector <int> v;

int main(){
	int n;
	cin >> n;
	if (n == 0){
		cout << "YES" << endl << 1 << endl << 1 << endl << 3 << endl << 3;
		return 0;
	}
	for (int i = 0; i < n; i++){
		int a;
		cin >> a;
		v.push_back(a);
	}
	sort(v.begin(), v.end());
	if (n == 1){
		cout << "YES" << endl << 2 * v[0] << endl << 2 * v[0] << endl << 3 * v[0] << endl;
		return 0;
	}
	if (n == 4){
		if (check(v))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
		return 0;
	}
	if (n == 3){
		vector <int> s = v;
		for (int i = 1; i <= 3000; i++){
			s.push_back(i);
			if (check(s)){
				cout << "YES" << endl << i << endl;
				return 0;
			}
			s.pop_back();
		}
		cout << "NO" << endl;
	}
	if (n == 2){
		if (3 * v[0] < v[1]){
            cout << "NO" << endl;
            return 0;
		}
		cout << "YES" << endl << 4 * v[0] - v[1] << endl << 3 * v[0] << endl;
		return 0;
	}
}