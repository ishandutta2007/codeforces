#include <iostream>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

map<string, int> mp;
pair<string,int> L[10001]; 

int main(){
	int n,tmp,m=0;
	cin>>n;
	for (int i=0; i<n; i++){
		cin>>L[i].first>>tmp;
		mp[L[i].first]+=tmp;
		L[i].second=mp[L[i].first];
	}
	for (int i=0; i<n; i++){
		m=max(m,mp[L[i].first]);
	}
	for (int i=0; i<n; i++){
		if (L[i].second>=m && mp[L[i].first]>=m){
			cout<<L[i].first<<endl;
			return 0;
		}
	}
	
	return 0;
}