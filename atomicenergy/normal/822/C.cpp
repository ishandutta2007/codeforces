#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;



int main() {
	int n, x;
	cin >> n >> x;
	map<int, vector<pair<int, long long> > > r;
	map<int, vector<pair<int, long long> > > l;
	for(int i=0; i<n; i++){
		long long q, w, e;
		cin >> q >> w >> e;
		r[w-q+1].push_back(make_pair(w, e));
		l[w-q+1].push_back(make_pair(q, e));
	}
	for(auto p: r){
		sort(r[p.first].begin(), r[p.first].end());
		sort(l[p.first].begin(), l[p.first].end());
	}
	for(auto p: r){
		long long minsofar = -1;
		for(int i=l[p.first].size()-1; i>=0; i--){
			if(minsofar == -1 || l[p.first][i].second < minsofar){
				minsofar = l[p.first][i].second;
			}
			l[p.first][i].second = minsofar;
		}
	}
	long long best = -1;
	for(auto p:r){
		if(r.count(x-p.first) == 0) continue;
		vector<pair<int, long long> > u, v;
		u = p.second;
		v = l[x-p.first];
		int ind = 0;
		for(int i=0; i<u.size(); i++){
			while(ind < v.size() && u[i].first >= v[ind].first){
				ind++;
			}
			if(ind!=v.size()){
				long long news = u[i].second + v[ind].second;
				if(best == -1 || news < best){
					best = news;
				}
			}
		}
	}
	cout << best << endl;
}