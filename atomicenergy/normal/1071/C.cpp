#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

vector<vector<int> > u;
vector<int> v;

void addit(vector<int> w){
	u.push_back(w);
	for(int i : w){
		v[i] = 1-v[i];
	}
}

void addit(int a, int b, int c){
	addit({a, b, c});
}

int main() {
	int n;
	cin >> n;
	
	
	for(int i=0; i<n; i++){
		int x;
		cin >> x;
		v.push_back(x);
	}
	int i = n;
	while(i >= 11){
		if(v[i-1] && v[i-2] && v[i-3]){
			addit({i-3, i-2, i-1});
			i-=3;
		}
		else if(v[i-1] && !v[i-2] && v[i-3]){
			addit({i-5, i-3, i-1});
			i-=3;
		}
		else if(!v[i-1] && v[i-2] && v[i-3]){
			addit({i-4, i-3, i-2});
			i-=3;
		}
		else if(v[i-1] && !v[i-2] && !v[i-3]){
			addit({i-7, i-4, i-1});
			i-=3;
		}
		else if(!v[i-1] && v[i-2] && !v[i-3]){
			addit({i-6, i-4, i-2});
			i-=3;
		}
		else if(!v[i-1] && !v[i-2] && v[i-3]){
			addit({i-5, i-4, i-3});
			i-=3;
		}
		else if(!v[i-1] && !v[i-2] && !v[i-3]){
			i-=3;
		}
		else if(v[i-1] && v[i-2] && !v[i-3]){
			if(v[i-4] && v[i-5] && v[i-6]){
				addit({i-6, i-4, i-2});
				addit({i-9, i-5, i-1});
				i-=6;
			}
			else if(v[i-4] && v[i-5] && !v[i-6]){
				addit({i-8, i-5, i-2});
				addit({i-7, i-4, i-1});
				i-=6;
			}
			else if(v[i-4] && !v[i-5] && v[i-6]){
				addit({i-10, i-6, i-2});
				addit({i-7, i-4, i-1});
				i-=6;
			}
			else if(!v[i-4] && v[i-5] && v[i-6]){
				addit({i-10, i-6, i-2});
				addit({i-9, i-5, i-1});
				i-=6;
			}
			else if(v[i-4] && !v[i-5] && !v[i-6]){
				addit({i-6, i-4, i-2});
				addit({i-11, i-6, i-1});
				i-=6;
			}
			else if(!v[i-4] && v[i-5] && !v[i-6]){
				addit({i-3, i-2, i-1});
				addit({i-7, i-5, i-3});
				i-=6;
			}
			else if(!v[i-4] && !v[i-5] && v[i-6]){
				addit({i-3, i-2, i-1});
				addit({i-9, i-6, i-3});
				i-=6;
			}
			else if(!v[i-4] && !v[i-5] && !v[i-6]){
				addit({i-3, i-2, i-1});
				addit({i-11, i-7, i-3});
				i-=6;
			}
		}
	}
	
	while(i >= 3){
		if(v[i-1]){
			addit({i-3, i-2, i-1});
		}
		i--;
	}
	if((v[1] && n <= 7) || (v[0] && n<=6)){
		cout << "NO" << endl;
		return 0;
	}
	if(v[1] && !v[0]){
		addit(1, 4, 7);
		addit(4, 5, 6);
		addit(5, 6, 7);
	}
	if(v[0] && !v[1]){
		addit(0, 3, 6);
		addit(3, 4, 5);
		addit(4, 5, 6);
	}
	if(v[0] && v[1]){
		addit(0, 3, 6);
		addit(1, 4, 7);
		addit(3, 4, 5);
		addit(5, 6, 7);
	}
	cout << "YES" << endl;
	cout << u.size() << endl;
	for(auto w : u){
		cout << w[0]+1 << " " << w[1]+1 << " " << w[2]+1 << endl;
	}
	
}