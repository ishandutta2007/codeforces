#include <bits/stdc++.h>
using namespace std;

#define int long long

int a[1502][1502];
int nrcol[1502], nrrow[1502];

int32_t main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int n;
	cin>>n;
	vector<pair<int, pair<int, int>>> v;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			cin>>a[i][j];
			v.push_back({a[i][j], {i, j}});
		}
	}
	sort(v.begin(), v.end());
	long long sol=0;
	for(auto it:v){
		auto c=it.second;
		int scol, bcol, srow, brow;
		scol=nrcol[c.second];
		bcol=n-1-scol;
		srow=nrrow[c.first];
		brow=n-1-srow;
		sol+=scol*brow+srow*bcol;
		nrrow[c.first]++, nrcol[c.second]++;
	}
	cout<<sol/2<<"\n";
}