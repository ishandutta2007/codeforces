#define _USE_MATH_DEFINES
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <cfloat>
#include <ctime>
#include <cassert>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <numeric>
#include <list>
#include <iomanip>

using namespace std;
typedef long long ll;
const int MODULO = 1000000007;
const int INF = 100000000; //1e8

using namespace std;

#define FOR(i,n) for(int i = 0; i < (n); i++)

typedef long long ll;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
typedef complex<double> Cd;

//BEGIN!!!

class Bidirectional_map
{
public:
	map<int,int> l_to_r;
	map<int,int> r_to_l;

	void erase(int l,int r){
		l_to_r.erase(l);
		r_to_l.erase(r);
	}

	void insert(int l,int r){
		l_to_r[l] = r;
		r_to_l[r] = l;
	}

	int getRfromL(int l){ return l_to_r[l]; }
	int getLfromR(int r){ return r_to_l[r]; }

	void erase_fromL(int l){ erase(l,l_to_r[l]); }
	void erase_fromR(int r){ erase(r_to_l[r],r); }
};

map<int,set<int> > dist_parkSet;
Bidirectional_map carNum_parkNum;

int n,m;

void insert(int id,int park,int dist){
	carNum_parkNum.insert(id,park);
	dist_parkSet[dist].insert(park);
}

void erase(int dist,int id){
	dist_parkSet[dist].erase(id);
	if(dist_parkSet[dist].size() == 0)
		dist_parkSet.erase(dist);
}

void reset_dist(int r,int md,int id){
	erase(md - r,r);
	dist_parkSet[(md - r)/2].insert(r);
	int l;
	if(md == n){
		l = n+1;
	} else {
		map<int,int>::iterator it = carNum_parkNum.r_to_l.upper_bound(r);
		l = (*it).first;
	}
	insert(id,md,(l-md)/2);
}

int get_maxDist(){ return (*(--dist_parkSet.end())).first; }
int get_firstPark(int dist){ return *(dist_parkSet[dist].begin()); }

int insert(int id){
	if(dist_parkSet.size() == 0){
		int park = 1;
		insert(id,park,n-1);
		return park;
	} else {
		int max_dist = get_maxDist();
		int max_park = get_firstPark(max_dist);
		int nx_number = max_park + max_dist;

		int most_left = (*carNum_parkNum.r_to_l.begin()).first; 
		if(most_left - 1 >= max_dist){
			insert(id,1,(most_left - 1)/ 2);
			return 1;
		}

		reset_dist(max_park,max_park + max_dist,id);

		return nx_number;
	}
}

void erase(int id){
	int md = carNum_parkNum.getRfromL(id);
	map<int,int>::iterator it = carNum_parkNum.r_to_l.find(md);
	if(it == carNum_parkNum.r_to_l.begin()){
		int r;
		++it;
		if(it == carNum_parkNum.r_to_l.end())
			r = n+1;
		else
			r = (*it).first;
		erase(r == n+1 ? n - md : (r-md)/2,md);
	} else {
		int r;
		map<int,int>::iterator r_it = it;
		++r_it;
		if(r_it == carNum_parkNum.r_to_l.end())
			r = n + 1;
		else
			r = (*r_it).first;
		it--;
		int l = (*it).first;
		erase(r == n+1 ? n - md : (r-md)/2,md);
		erase((md-l)/2,l);
		insert(carNum_parkNum.getLfromR(l),l,r == n+1 ? n - l : (r-l)/2);
	}

	carNum_parkNum.erase_fromL(id);
}

void debug(){
	FOR(i,n){
		printf("%c",carNum_parkNum.r_to_l.find(i+1) == carNum_parkNum.r_to_l.end() ? 'o' : 'x');
	}
	puts("");
	for(map<int,set<int> >::iterator it = dist_parkSet.begin(); it != dist_parkSet.end(); ++it){
		cout << (*it).first << " : ";
		for(set<int>::iterator it2 = (*it).second.begin(); it2 != (*it).second.end(); ++it2){
			cout << *it2 << " ";
		}
	}
	puts("");
	puts("");
	puts("");
}

int main()
{
	cin>>n>>m;
	FOR(i,m){
		int t,id; cin>>t>>id;
		if(t == 1){
			int park = insert(id);
			cout << park << endl;
		} else {
			erase(id);
		}
	}

	return 0;
}