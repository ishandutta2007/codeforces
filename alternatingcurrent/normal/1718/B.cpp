// fuck you
// du cuo ti le
#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;

int fib[222];
int cnt[222];
int has[222];
vector<int> pos[222];

int main(){
	ios::sync_with_stdio(false);
	fib[0] = 0, fib[1] = 1;
	int lmt = 2;
	for(; fib[lmt] <= 1000000000ll; lmt++){
		fib[lmt] = fib[lmt - 1] + fib[lmt - 2];
		if(fib[lmt] > 1000000000ll)
			break;
	}
	int T;
	cin >> T;
	while(T--){
		int k;
		cin >> k;
		rep(i, k)
			cin >> cnt[i];
		rep(i, k)
			has[i] = 0;
		rep(i, lmt)
			pos[i].clear();
		int cntall = 0;
		rep(i, k){
			for(int j = lmt - 1; j > 0; j--)
				if(cnt[i] >= fib[j])
					cnt[i] -= fib[j], pos[j].push_back(i), has[i]++, cntall++;
		}
		bool ok = 1, nhas = 0, done = 0;
		for(int j = lmt - 1; j > 2; j--){
//			rep(i, k)
//				cout << i << "kk" << has[i] << " ";
//			cout << endl;
			if((int)pos[j].size() > 1){
				if(done){
					ok = 0;
					break;
				} else {
					if((int)pos[j].size() > 2){
						ok = 0;
						break;
					}
					int a = pos[j][0], b = pos[j][1];
					if(has[a] > 1)
						swap(a, b);
					if(has[a] != 1){
						ok = 0;
						break;
					}
//					cout << "do " << a << " " << has[a] << endl;
					int l = j - 1;
					for(l = j - 1; l > -1; l -= 2)
						pos[l].push_back(a);
					if(l != -1){
						ok = 0;
						break;
					}
					pos[j] = {b};
					done = 1;
				}
			}
			if(nhas && !(int)pos[j].size()){
				ok = 0;
				break;
			}
			if((int)pos[j].size()){
				if(!(int)pos[j - 1].size()){
					if(done || nhas){
						ok = 0;
						break;
					}
					int a = pos[j][0];
					if(has[a] != 1){
						ok = 0;
						break;
					}
					int l = j - 1;
					for(l = j - 1; l > -1; l -= 2)
						pos[l].push_back(a);
					if(l != -1){
						ok = 0;
						break;
					}
					pos[j].clear();
					done = 1;
				}
			}
			if((int)pos[j].size()){
				nhas = 1;
				has[pos[j][0]]--;
			}
//			cout << j << ": " << pos[j].size() << ": ";
//			rep(i, (int)pos[j].size())
//				cout << pos[j][i] << " ";
//			cout << endl;
		}
		int cnt1 = (int)pos[2].size() + (int)pos[1].size();
		if(cnt1 != 2 && !(!nhas && cnt1 == 1))
			ok = 0;
		cout << (ok ? "YES\n" : "NO\n");
	}
	return 0;
}