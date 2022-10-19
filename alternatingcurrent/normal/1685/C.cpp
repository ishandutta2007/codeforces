#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

int n;
string s;
vector< pair<int, int> > mx;

int main(){
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	while(T--){
		cin >> n >> s;
		mx.clear();
		int sum = 0;
		int nowmx = 0, mxpos = -1;
		rep(i, (int)s.size()){
			sum += ((s[i] == '(') - (s[i] == ')'));
			if(sum < 0 && nowmx >= 0){
				mx.push_back(make_pair(nowmx, mxpos));
				nowmx = -1;
			}
			if(sum > nowmx)
				nowmx = sum, mxpos = i;
		}
		mx.push_back(make_pair(nowmx, mxpos));
		int mxind = 0;
		rep(i, (int)mx.size())
			if(mx[i].first > mx[mxind].first)
				mxind = i;
		if((int)mx.size() == 1){
			cout << "0" << endl;
		} else if(mx[0].first + mx[(int)mx.size() - 1].first >= mx[mxind].first){
			cout << "1" << endl;
			cout << mx[0].second + 1 + 1 << " " << mx[(int)mx.size() - 1].second + 1 << endl;
		} else {
			cout << "2" << endl;
			cout << mx[0].second + 1 + 1 << " " << mx[mxind].second + 1 << endl;
			cout << mx[mxind].second + 1 + 1 << " " << mx[(int)mx.size() - 1].second + 1 << endl;
		}
	}
	return 0;
}