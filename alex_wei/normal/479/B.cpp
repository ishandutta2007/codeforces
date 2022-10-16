#include <bits/stdc++.h>
using namespace std;
int n,k,a,l=1e9,r;
vector <int> buc[12345],al,ar;
int main(){
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a,buc[a].push_back(i),l=min(l,a),r=max(r,a);
	while(k&&l+1<r){
		int val=min(k,(int)min(buc[l].size(),buc[r].size()));
		k-=val;
		while(val--){
			al.push_back(buc[r].back());
			ar.push_back(buc[l].back());
			buc[r-1].push_back(buc[r].back());
			buc[l+1].push_back(buc[l].back());
			buc[l].pop_back();
			buc[r].pop_back();
		}
		if(!buc[l].size())l++;
		if(!buc[r].size())r--;
	}
	cout<<r-l<<" "<<ar.size()<<endl;
	for(int i=0;i<ar.size();i++)cout<<al[i]<<" "<<ar[i]<<endl;
	return 0;
}