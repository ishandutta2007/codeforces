#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <set>
#include <map>
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;

#define mp make_pair
#define pb push_back



int p[1000];
int pinv[1000];
vector<set<int>> v;
vi x;
vi y;

int swp(int a, int b){
	//cout << p[0] << p[1] << p[2] << p[3] << p[4] << endl;
	int z = p[a];
	v[a].erase(b);
	p[a] = p[b];
	p[b] = z;
	pinv[p[a]] = a;
	pinv[p[b]] = b;
	x.pb(a);
	y.pb(b);
}

int main() {
	int n;
	cin >> n;
	v = vector<set<int>>(n, set<int>());
	if(n%4==2 || n%4==3) {
		cout << "NO" << endl;
		return 0;
	}
	for(int i=0; i<n; i++){
		p[i] = i;
		pinv[i] = i;
	}
	for(int i=0; i<n; i++){
		for(int j=i+1; j<n; j++){
			v[i].insert(j);
		}
	}
	for(int i=0; i<n; i++){
		int z = 0;
		if(v[i].size()==0) continue;
		while(v[i].size()>1){
			auto it = v[i].begin();
			if(pinv[i] == *it) it++;
			swp(i, *it);
		}
		if(pinv[i] != *(v[i].begin())){
			
			if(pinv[i] < *(v[i].begin())) swp(pinv[i], *(v[i].begin()));
			else swp(*(v[i].begin()), pinv[i]);
		}
		
		swp(i, *(v[i].begin()));
	}
	cout << "YES" << endl;
	for(int i =0; i<x.size(); i++){
		cout << x[i]+1 << " " << y[i]+1 << endl;
	}
}