#include <bits/stdc++.h>

using namespace std;

mt19937 rando(chrono::steady_clock::now().time_since_epoch().count());
int T, N, K;
bool done = 0;

int query(vector<int> a, vector<int> b){
	if(a.size() == 1 && b.size() == 1 && a[0] == b[0]){
		return 0;
	}
	cout << "? " << a.size() << " " << b.size() << endl;
	for(int n : a){
		cout << n << " ";
	}
	cout << endl;
	for(int n : b){
		cout << n << " ";
	}
	cout << endl;
	string s;
	cin >> s;
	if(s == "FIRST"){
		return 1;
	}
	else if(s == "SECOND"){
		return -1;
	}
	else if(s == "EQUAL"){
		return 0;
	}
	else{
		assert(0);
	}
}

void answer(int n){
	done = 1;
	cout << "! " << n << endl;
}

vector<int> build(int l, int r){
	vector<int> ret;
	for(int i = l; i<=min(N, r); i++){
		ret.push_back(i);
	}
	return ret;
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> T;
	while(T--){
		cin >> N >> K;
		done = 0;
		for(int t = 0; t<28; t++){
			int k = query({1}, {uniform_int_distribution<int>(1, N)(rando)});
			if(k == -1){
				answer(1);
				break;
			}
		}
		if(done){
			continue;
		}		
		for(int d = 0; d<31-__builtin_clz(N); d++){
			int k = query(build(1, 1<<d), build((1<<d)+1, 1<<(d+1)));
			//cout << 31-__builtin_clz(N)-1 << " " << d << endl;
			if(k || d == 31-__builtin_clz(N)-1){
				int crnt = (1<<d);
				if(!k && d == 31-__builtin_clz(N)-1){
					crnt = (1<<(d+1));
				}
				//cout << crnt << endl;
				do{
					if(crnt+(1<<d) <= N && query(build(1, 1<<d), build(crnt+1, crnt+(1<<d))) == 0){
						crnt += (1<<d);
					}
				}
				while(--d>=0);
				answer(crnt+1);
				break;
			}
		}
	}
}