#include <iostream>
#include <vector>
#include <map>
using namespace std;



int main() {
	int n;
	int m;
	cin >> n >> m;
	vector<int> b;
	vector<int> found;
	int cnt = 0;
	for(int i=0; i<m; i++){
		b.push_back(-1);
	}
	map<int, vector<int> > fi;
	map<int, vector<int> > ti;
	vector< vector<int> > gg;
	for(int i=0; i<n; i++){
		int x;
		cin >> x;
		vector<int> v;
		for(int i=0; i<x; i++){
			int y;
			cin >> y;
			y--;
			v.push_back(y);
		}
		gg.push_back(v);
	}
	for(int i=0; i<n-1; i++){
		vector<int> u = gg[i];
		vector<int> v = gg[i+1];
		int ind = 0;
		while(ind<u.size() && ind<v.size() && u[ind] == v[ind]){
			ind++;
		}
		if(ind == u.size()) continue;
		if(ind == v.size()){
			cout << "No" << endl;
			return 0;
		}
		int x = u[ind];
		int y = v[ind];
		if(x>y){
			if(b[x] == 0 || b[y] == 1){
				printf("No\n");
				return 0;	
			}
			if(b[x] == -1) found.push_back(x);
			if(b[y] == -1) found.push_back(y);
			b[x] = 1;
			b[y] = 0;
			
		}
		if(x<y){
			ti[y].push_back(x);
			fi[x].push_back(y);
		}
	}
	while(found.size()>0){
		int x = found[found.size()-1];
		found.pop_back();
		if(b[x]){
			for(int y : ti[x]){
				if(b[y] == 0){
					printf("No\n");
					return 0;	
				}
				if(b[y] == -1) found.push_back(y);
				b[y] = 1;
			}
		}else{
			for(int y : fi[x]){
				if(b[y] == 1){
					printf("No\n");
					return 0;	
				}
				if(b[y] == -1) found.push_back(y);
				b[y] = 0;
			}
		}
	}
	printf("Yes\n");
	for(int i=0; i<m; i++){
		if(b[i] == 1) cnt++;
	}
	printf("%d\n", cnt);
	for(int i=0; i<m; i++){
		if(b[i] == 1) printf("%d ", (i+1));
	}
	printf("\n");
}