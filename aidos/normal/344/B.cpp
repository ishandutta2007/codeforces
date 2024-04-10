#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int a, b[4][4];
	vector < pair < int, int > > v;
	for(int i = 0; i<3; i++){
		cin >> a;
		v.push_back(make_pair(a, i));
	}
	sort(v.begin(), v.end());
	if(v[2].first <= v[1].first + v[0].first && (v[1].first + v[0].first + v[2].first) % 2 ==0){
		int x = (v[1].first + v[0].first - v[2].first)/2;
		b[v[1].second][v[0].second] = x; 
		b[v[0].second][v[1].second] = x; 
		b[v[2].second][v[1].second] = v[1].first - x; 
		b[v[1].second][v[2].second] = v[1].first - x; 
		b[v[2].second][v[0].second] = v[0].first - x; 
		b[v[0].second][v[2].second] = v[0].first - x; 
		cout << b[0][1] << " " << b[1][2] << " " << b[2][0];
	}
	else  cout << "Impossible";
	return 0;
}