#include <iostream>
#include <algorithm>
#include <cstring>
#include <map>
#include <vector>
#include <set>
#include <queue>
#include <fstream>
#include <stack>

#define F first
#define S second
#define PB push_back
using namespace std;

const int maxn = 2e5 + 100;
bool mark[maxn];
vector <int> v;
stack <int> s;
set <int> a;

int main(){
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++){
		int k;
		cin >> k;
		v.PB(k);
		mark[k] = 1;
	}
	for (int i = 1; i <= n; i++)
		if (!mark[i])
			a.insert(i);
	int idx = 0, mex = 1;
	for (int i = 0; i < m; i++){
		if (!s.empty() and v[i] > s.top())
			return cout << -1 << endl, 0;
		s.push(v[i]);
		while (s.size() > 0 and s.top() == mex){
			s.pop();
			mex ++;
		}
	}
	for (int i = m; i < n; i++){
		if (s.size() == 0){
			set<int>::iterator it = a.end();
			it --;
			v.push_back(*it);
			s.push(*it);
			a.erase(it);
		}
		else {
			set<int>::iterator it = a.lower_bound(s.top());
			if  (it == a.begin()){
				return cout << -1 << endl, 0;
			}
			it --;
			v.push_back(*it);
			s.push(*it);
			a.erase(it);
		}
		while (s.size() > 0 and s.top() == mex){
			s.pop();
			mex ++;
		}
	}
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << " ";
}