#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ld eps=1e-10;
const int inf=1000000010;
const int mod = 1000 * 1000 * 1000 + 7;
const int MAXN = 120 * 1000 + 10;

int n, tmp;
int A[MAXN];

map<int, bool> mark;
map<int, int> mp;

int main(){
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	for (int i=0; i<n; i++){
		cin>>A[i];
		mark[A[i]]=false;
		for (int j=1; j<=30; j++){
			tmp=1<<j;
			if (mp[tmp-A[i]]){
				//cout<<A[i]<<' '<<tmp-A[i]<<endl;
				mark[A[i]]=mark[tmp-A[i]]=true;
			}
		}
		mp[A[i]]++;
	}
	int ans=n;
	for (auto p : mark){
		//cout<<p.first<<' '<<p.second<<endl;
		if (p.second) ans-=mp[p.first];
	}
	cout<<ans<<endl;
	return 0;
}