#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;

const int MAXN=200 * 1000 + 10;

int n, a, b;
ll ans;

map<int, ll> mp1, mp2;
map<pii, ll> mp3;

int main(){
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	for (int i=0; i<n; i++){
		cin>>a>>b;
		mp1[a]++;
		mp2[b]++;
		mp3[{a, b}]++;
	}
	for (auto i : mp1){
		ans+=i.second*(i.second-1)/2;
	}
	for (auto i : mp2){
		ans+=i.second*(i.second-1)/2;
	}
	for (auto i : mp3){
		ans-=i.second*(i.second-1)/2;
	}
	
	cout<<ans<<endl;
	
	return 0;
}