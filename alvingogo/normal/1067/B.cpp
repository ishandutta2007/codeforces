#include <bits/stdc++.h>
#define AquA cin.tie(0);ios_base::sync_with_stdio(0);
#define fs first
#define sc second
#define cd complex<double>
#define p_q priority_queue
using namespace std;

vector<set<int> > e;
int main(){
	AquA;
	int n,k;
	cin >> n >> k;
	e.resize(n);
	vector<int> deg(n);
	for(int i=1;i<n;i++){
		int a,b;
		cin >> a >> b;
		a--;
		b--;
		e[a].insert(b);
		e[b].insert(a);
		deg[a]++;
		deg[b]++;
	}
	if(n<=2){
		cout << "No\n";
		return 0;
	}
	for(int i=0;i<n;i++){
		if(deg[i]==2){
			cout << "No\n";
			return 0;
		}
	}
	int cnt=0;
	for(int i=0;i<n;i++){
		if(deg[i]==3){
			cnt++;
		}
	}
	if(cnt>=2){
		cout << "No\n";
		return 0;
	}
	queue<int> q;
	vector<int> tmp(n,-1),dg(n,0);
	for(int i=0;i<n;i++){
		if(deg[i]==1){
			q.push(i);
			tmp[i]=0;
			dg[i]=8e7;
		}
	}
	while(q.size()){
		auto h=q.front();
		q.pop();
		if(e[h].empty()){
			break;
		}
		auto a=*e[h].begin();
		if(tmp[a]!=-1){
			if(tmp[a]!=tmp[h]+1){
				cout << "No\n";
				return 0;
			}
			else{
				dg[a]++;
				e[a].erase(h);
				deg[a]--;
				if(deg[a]==1){
					q.push(a);
				}
			}
		}
		else{
			tmp[a]=tmp[h]+1;
			e[a].erase(h);
			dg[a]++;
			deg[a]--;
			if(deg[a]==1){
				q.push(a);
			}
		}
	}
	for(int i=0;i<n;i++){
		if(dg[i]<3){
			//cout << i << " " << dg[i] << "\n";
			cout << "No" << "\n";
			return 0;
		}
		else if(e[i].empty()){
			if(tmp[i]!=k){
				cout << "No\n";
				return 0;
			}
		}
	}
	cout << "Yes\n";
	return 0;
}