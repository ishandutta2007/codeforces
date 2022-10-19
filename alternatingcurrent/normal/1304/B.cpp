#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

int n, m;
string s[111];
vector< pair<int, int> > v;
string ansl, ansr, ansmid;

int main(){
	cin >> n >> m;
	rep(i, n) cin >> s[i];
	rep(i, n){
		rep(j, i+1){
			bool ok = 1;
			rep(k, m){
				if(s[i][k] != s[j][m-k-1]) ok = 0;
			}
			if(ok) v.push_back(make_pair(i, j));
		}
	}
	ansl = ansr = ansmid = "";
	rep(i, v.size()){
		if(v[i].first == v[i].second){
			if(ansmid == "") ansmid = s[v[i].first];
			continue;
		}
		ansl = ansl + s[v[i].first];
		ansr = s[v[i].second] + ansr;
	}
	cout << (ansl.size() + ansmid.size() + ansr.size()) << endl;
	cout << ansl << ansmid << ansr; 
	return 0;
}