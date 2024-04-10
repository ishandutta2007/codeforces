#include<bits/stdc++.h>

using namespace std;

#define int long long

signed main(){
	ios::sync_with_stdio(false); cin.tie(0);
	int s, b; cin>>s>>b;
	vector<int> a(s);
	for(int i = 0; i < s; i++) cin>>a[i];
	vector<pair<int, int> > c(b);
	for(int i = 0; i < c.size(); i++){
		cin>>c[i].first>>c[i].second;
	}
	vector<int> pref(c.size());
	sort(c.begin(), c.end());
	pref[0] = c[0].second;
		for(int i = 1; i < c.size(); i++){
		pref[i] = pref[i-1] + c[i].second;
	}
	for(int i = 0; i < s; i++){
		int low = 0, high = b-1, mid;
		while(low < high){
			mid = (low + high+1)/2;
			if(c[mid].first <= a[i]){
				low = mid;
			}else{
				high = mid-1;
			}
		}
		mid = (low + high + 1)/2;
		if(c[mid].first > a[i]){
			cout<<0<<" ";
		}else{
			cout<<pref[mid]<<" ";
		}
	}
	cout<<endl;
}