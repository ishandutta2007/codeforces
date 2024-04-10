#include <iostream>
#include <vector>
#include <algorithm>
#define fastio cin.tie(0);ios_base::sync_with_stdio(0);

using namespace std;

int main(){
	fastio;
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<long long> a(n),b(n),c(n),d(n);
		long long int x,xp=0;
		for(int i=0;i<n;i++){
			cin >> a[i];
			d[i]=a[i];
			xp=0;
			for(int j=0;j<a[i];j++){
				cin >> x;
				xp=max(xp,x-j+1);
			}
			b[i]=xp;
			c[i]=b[i];
		}
		long long int ans=0,cur=0;
		sort(b.begin(),b.end());
		vector<int> v(n);
		for(int i=0;i<n;i++){
			v[i]=i;
		}
		for(int i=0;i<n;i++){
			int k=lower_bound(b.begin(),b.end(),c[i])-b.begin();
			d[v[k]]=a[i];
			v[k]++;
		}
		ans=b[0];
		cur=b[0];
		for(int i=0;i<n;i++){
			ans+=d[i];
			if(i<n-1 && ans<b[i+1]){
				cur+=(b[i+1]-ans);
				ans=b[i+1];
			}
		}
		cout << cur << "\n";
	}
	return 0;
}