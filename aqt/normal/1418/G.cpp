
// Problem : G. Three Occurrences
// Contest : Codeforces - Educational Codeforces Round 95 (Rated for Div. 2)
// URL : https://codeforces.com/contest/1418/problem/G
// Memory Limit : 512 MB
// Time Limit : 5000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

mt19937 rando(chrono::steady_clock::now().time_since_epoch().count());

int N;
int arr[500005];
int fre[500005];
int coel[500005];
int coer[500005];
long long sd[500005];
map<long long, int> mp;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for(int i = 1; i<=N; i++){
		sd[i] = uniform_int_distribution<long long>(LLONG_MIN, LLONG_MAX)(rando);
		cin >> arr[i];
	}	
	long long hshr = 0, hshl = 0;
	mp[0] = 1;
	long long ans = 0;
	for(int l = 1, r = 1; r<=N; r++){
		hshr -= coer[arr[r]] * sd[arr[r]];
		fre[arr[r]]++;
		coer[arr[r]]++;
		coer[arr[r]] %= 3;
		hshr += coer[arr[r]] * sd[arr[r]];
		while(fre[arr[r]] > 3){
			//cout << l << " " << r << endl;
			mp[hshl]--;
			fre[arr[l]]--;
			hshl -= coel[arr[l]] * sd[arr[l]];
			coel[arr[l]]++;
			coel[arr[l]] %= 3;
			hshl += coel[arr[l]] * sd[arr[l]];
			l++;
		}
		ans += mp[hshr];
		mp[hshr]++;
	}
	cout << ans;
}