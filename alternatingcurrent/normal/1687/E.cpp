#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; ++i)
using namespace std;

int n;
int a[100100];

vector<int> choosesub(const vector<int> &id){
	if((int)id.size() == 0)
		return {};
	
	int x = a[id[0]];
	vector<int> p;
	static int mn[12], tmn[12];
	for(int i = 2; i * i <= x; ++i)
		if(x % i == 0){
			while(x % i == 0)
				x /= i, ++mn[(int)p.size()];
			p.push_back(i);
		}
	if(x != 1)
		mn[(int)p.size()] = 1, p.push_back(x);
	memcpy(tmn, mn, sizeof(mn));
	
	static int has[12][100100];
	rep(i, (int)id.size()){
		int nval = a[id[i]];
		rep(j, (int)p.size()){
			has[j][i] = 0;
			while(nval % p[j] == 0)
				nval /= p[j], ++has[j][i];
			tmn[j] = min(tmn[j], has[j][i]);
		}
	}
	
	vector<int> ret;
	rep(j, (int)p.size()) for(int i = 1; i < (int)id.size(); ++i){
		if(has[j][i] == tmn[j] && mn[j] != tmn[j]){ 
			ret.push_back(id[i]); // id[j] -> id[i]
			rep(k, (int)p.size())
				mn[k] = min(mn[k], has[k][i]);
		}
	}
	
//	rep(i, (int)ret.size())
//		cout << ret[i] << " ";
//	cout << endl;
	
	if((int)ret.size() < 7)
		ret.push_back(id[0]);
	
	return ret;
}

int main(){
	ios::sync_with_stdio(false);
	
	cin >> n;
	rep(i, n)
		cin >> a[i];
	
	vector<int> id;
	rep(i, n)
		id.push_back(i);
	vector<int> ret = choosesub(id);
	
//	rep(i, (int)ret.size())
//		cout << ret[i] << " ";
//	cout << endl;
	
	static bool in[100100];
	rep(i, (int)ret.size())
		in[ret[i]] = 1;
	
	id.clear();
	rep(i, n)
		if(!in[i])
			id.push_back(i);
	ret = choosesub(id);
	rep(i, (int)ret.size())
		in[ret[i]] = 1;
	
	vector<int> res;
	rep(i, n)
		if(in[i])
			res.push_back(i);
	
//	rep(i, (int)res.size())
//		cout << res[i] << " ";
//	cout << endl;
	
	vector< pair<int, vector<int> > > opt;
	for(int mask = 1; mask < 1 << (int)res.size(); ++mask){
		vector<int> tmp;
		rep(i, (int)res.size())
			if(mask & (1 << i))
				tmp.push_back(res[i]);
		
		int sz = __builtin_popcount(mask);
		int tp = sz & 1, cnt = sz - 2;
		if(sz == 1)
			tp = 0, cnt = 1;
		
//		cout << tp << " " << cnt << ": "; rep(i, sz) cout << res[i] << " "; cout << endl;
		
		rep(i, cnt)
			opt.emplace_back(tp, tmp);
	}
	
	cout << (int)opt.size() << "\n";
	rep(i, (int)opt.size()){
		cout << opt[i].first << " ";
		vector<int> &v = opt[i].second;
		cout << (int)v.size() << " ";
		rep(j, (int)v.size())
			cout << v[j]+1 << " ";
		cout << "\n";
	}
	
	return 0;
}