#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
#define SZ(x) (int)(x).size()
typedef long long ll;
typedef pair<int,int> pii;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	set<int> asdf;
	vector<bool> change(n,false);
	int even=0,odd=0;
	for(int i=0; i<n; i++) {
		cin>>a[i];
		if(asdf.find(a[i])==asdf.end()) {
			asdf.insert(a[i]);
			if(a[i]%2==0)even++;
			else odd++;
		} else
			change[i]=true;
	}
	vector<int> ans(n);
	int ie=2,io=1,cnt=0;
	for(int i=0; i<n; i++)
		if(change[i]) {
			cnt++;
			if(even<odd) {
				while(asdf.find(ie)!=asdf.end())ie+=2;
				if(ie>m)return cout<<-1,0;
				ans[i]=ie;
				ie+=2;
				even++;
			} else {
				while(asdf.find(io)!=asdf.end())io+=2;
				if(io>m)return cout<<-1,0;
				ans[i]=io;
				io+=2;
				odd++;
			}
		} else {
			if(a[i]%2==0&&even>n/2) {
				cnt++;
				while(asdf.find(io)!=asdf.end())io+=2;
				if(io>m)return cout<<-1,0;
				ans[i]=io;
				io+=2;
				even--; odd++;
			} else if(a[i]%2==1&&odd>n/2) {
				cnt++;
				while(asdf.find(ie)!=asdf.end())ie+=2;
				if(ie>m)return cout<<-1,0;
				ans[i]=ie;
				ie+=2;
				even++; odd--;
			} else
				ans[i]=a[i];
		}
	cout<<cnt<<"\n";
	for(int i=0; i<n; i++) cout<<ans[i]<<' ';
}