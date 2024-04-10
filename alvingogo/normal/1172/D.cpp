#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define AquA cin.tie(0);ios_base::sync_with_stdio(0);
#define fs first
#define sc second
#define p_q priority_queue
using namespace std;

int main(){
    AquA;
	int n;
	cin >> n;
	vector<int> v(n),w(n);
	vector<int> r(n),c(n);
	for(int i=0;i<n;i++){
		int a;
		cin >> a;
		a--;
		v[a]=i;
		r[i]=a;
	}
	for(int i=0;i<n;i++){
		int a;
		cin >> a;
		a--;
		w[a]=i;
		c[i]=a;
	}
	vector<pair<pair<int,int>,pair<int,int> > > ans;
	for(int i=0;i<n;i++){
		if(w[i]==i && v[i]==i){
			continue;
		}
		ans.push_back({{i,w[i]},{v[i],i}});
		int z=v[i];
		v[r[i]]=v[i];
		r[z]=r[i];
		z=w[i];
		w[c[i]]=w[i];
		c[z]=c[i];
	}
	cout << ans.size() << "\n";
	for(auto h:ans){
		cout << h.fs.fs+1 << " " << h.fs.sc+1 << " " << h.sc.fs+1 << " " << h.sc.sc+1 << "\n";
	}
    return 0;
}