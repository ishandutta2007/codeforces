#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

int T;
int n, k;
int a[100100];
map<int, int> cnt;

int main(){
	ios::sync_with_stdio(false);
	cin >> T;
	while(T--){
		cin >> n >> k;
		rep(i, n)
			cin >> a[i];
		sort(a, a + n);
		int nowpos = -1;
		int nowneed = 0;
		bool ok = 0;
		rep(i, n){
			if(nowpos < a[i])
				nowneed += a[i] - nowpos - 1;
			nowpos = a[i];
//			cout << ": "  << i << endl;
			if(nowneed > k){
				cnt.clear();
				for(int j = i; j < n; j++)
					cnt[a[j]]++;
				vector<int> v;
				for(map<int, int>::iterator it = cnt.begin(); it != cnt.end(); it++)
					v.push_back(it->second);
				sort(v.begin(), v.end());
				int sumcnt = 0;
				bool done = 0;
				rep(j, (int)v.size()){
					if(sumcnt + v[j] > k){
						cout << (int)v.size() - j << endl;
						done = 1;
						break;
					} 
					sumcnt += v[j];
				}
				if(!done)
					cout << "0" << endl;
				ok = 1;
				break;
			} else if(nowneed > n - i){
				cout << "0" << endl;
				ok = 1;
				break;
			}
		}
		if(!ok)
			cout << "0" << endl;
	}
	return 0;
}