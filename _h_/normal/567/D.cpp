#include <iostream>
#include <vector>
#include <random>
#include <set>
#include <map> 
#include <algorithm>
using namespace std;
#define rep(i,a,b) for(int i = int(a); i < (b); ++i)

int main(){
	int n,k,a,m;
	cin >> n >> k >> a >> m;
	int maxskepp = (n+1)/(a+1);
	set<int> giss;
	giss.insert(0), giss.insert(n+1);
	rep(i,0,m){
		int x;
		cin >> x;
		auto it = giss.upper_bound(x);
		int u = *it;
		int l = *(--it);
		maxskepp -= (u-l)/(a+1);
		maxskepp += (x-l)/(a+1);
		maxskepp += (u-x)/(a+1);
		giss.insert(x);
		if(maxskepp < k){
			cout << i+1 << endl;
			return 0;
		}
	}
	cout << -1 << endl;
}