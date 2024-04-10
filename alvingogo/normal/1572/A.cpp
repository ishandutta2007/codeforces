#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>
#include <bitset>
#define fastio cin.tie(0);ios_base::sync_with_stdio(0);

using namespace std;

int main(){
	fastio;
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<int> v(n);
		//vector<pair<int,int> > e;
		vector<vector<int> > ve(n);
		
		priority_queue<long long,vector<long long>,greater<long long> > pq;
		
		const long long mod=1000000;
		vector<int> vis(n,mod);
		for(int i=0;i<n;i++){
			cin >> v[i];
			int y=0;
			if(v[i]==0){
				pq.push(mod+i);
				vis[i]=1;
			}
			for(int j=0;j<v[i];j++){
				cin >> y;
				y--;
				//e.push_back(make_pair(y,i));
				ve[y].push_back(i);
			}
		}
		/*
		for(int i=0;i<n;i++){
			for(int j=0;j<ve[i].size();j++){
				cout << ve[i][j] << " ";
			}
			cout << endl;
		}
		*/
		int flag=0;
		if(pq.empty()){
			flag=1;
		}
		while(!pq.empty()){
			long long x=pq.top();
			pq.pop();
			int y=x%mod;
			//cout << y << endl;
			int z=ve[y].size();
			for(int i=0;i<z;i++){
				if(vis[ve[y][i]]!=mod){
					flag=1;
					break;
				}
				v[ve[y][i]]--;
				if(v[ve[y][i]]>0){
					continue;
				}
				if(ve[y][i]>y){
					vis[ve[y][i]]=vis[y];
					//cout << y << ve[y][i] << endl;
					pq.push(ve[y][i]+vis[ve[y][i]]*mod);
				}
				else{
					vis[ve[y][i]]=vis[y]+1;
					//cout << y << ve[y][i] << endl;
					pq.push(ve[y][i]+vis[ve[y][i]]*mod);
				}
			}
			if(flag==1){
				break;
			}
		}
		/*
		for(int i=0;i<n;i++){
			cout << vis[i] << " ";
		}
		cout << endl;
		*/
		for(int i=0;i<n;i++){
			if(vis[i]==mod){
				//cout << i << endl;
				flag=1;
				break;
			}
		}
		if(flag==1){
			cout << -1 << "\n";
			continue;
		}
		int maxx=0;
		for(int i=0;i<n;i++){
			maxx=max(maxx,vis[i]);
		}
		
		cout << maxx << "\n";
	}
	//cout << "2\n-1\n1\n2\n5\n";
	return 0;
}