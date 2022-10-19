#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;

int n, m;
pair<int, int> val[555];
bool nowhas[555];

int main(){
	ios::sync_with_stdio(false);
	cin >> n >> m;
	rep(i, m){
		cout << "? ";
		rep(j, i)
			cout << "0";
		cout << "1";
		rep(j, m - i - 1)
			cout << "0";
		cout << endl;
		cin >> val[i].first;
		val[i].second = i;
	}
	sort(val, val + m);
	ll nowsum = 0;
	rep(i, m){
		nowhas[val[i].second] = 1;
		cout << "? ";
		rep(i, m)
			cout << nowhas[i];
		cout << endl;
		ll nxtans;
		cin >> nxtans;
		if(nxtans != nowsum + val[i].first){
			nowhas[val[i].second] = 0;
		} else {
			nowsum += val[i].first;
		}
	}
	cout << "! " << nowsum << endl;
	return 0;
}