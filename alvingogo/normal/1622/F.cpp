#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define AquA cin.tie(0);ios_base::sync_with_stdio(0);
#define fs first
#define sc second
#define cd complex<double>
#define p_q priority_queue
#define int long long
using namespace std;

signed main(){
	AquA;
	int n;
	cin >> n;
	mt19937_64 rnd(time(NULL));
	vector<int> v(n+1),pr(n+1,-1);
	int k=0;
	map<int,int> m;
	for(int i=2;i<=n;i++){
		v[i]=v[i-1];
		if(pr[i]==-1){
			v[i]^=rnd();
			for(int j=i+i;j<=n;j+=i){
				pr[j]=i;
			}
		}
		else{
			v[i]^=v[pr[i]]^v[pr[i]-1];
			v[i]^=v[i/pr[i]]^v[i/pr[i]-1];
		}
		k^=v[i];
		m[v[i]]=i;
	}
	set<int> s;
	for(int i=1;i<=n;i++){
		s.insert(i);
	}
	if(k!=0){
		if(m.find(k)!=m.end()){
			s.erase(m[k]);
		}
		else{
			int flag=0;
			for(int i=2;i<=n;i++){
				if(m.find(k^v[i])!=m.end()){
					s.erase(i);
					s.erase(m[k^v[i]]);
					flag=1;
					break;
				}
			}
			if(flag==0){
				s.erase(n);
				k^=v[n];
				m.erase(v[n]);
				for(int i=2;i<n;i++){
					if(m.find(k^v[i])!=m.end()){
						s.erase(i);
						s.erase(m[k^v[i]]);
						flag=1;
						break;
					}
				}
			}	
		}
	}
	cout << s.size() << "\n";
	for(auto h:s){
		cout << h << " ";
	}
	cout << "\n";
	return 0;
}