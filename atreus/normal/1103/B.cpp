/**
 *    author:  Atreus
 *    created: 22.01.2019
 **/
#include <bits/stdc++.h>
#define F first
#define S second

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;

string ask(int fi, int se){
	cout << "? " << fi << " " << se << endl;
	string get;
	cin >> get;
	return get;
}

int main(){
	ios_base::sync_with_stdio(false);
	string s;
	cin >> s;
	while (true){
		ll answer = 0;
		string res = ask(0, 1);
		if (res == "x"){
			cout << "! " << 1 << endl;
		}
		else{
			int now = 0;
			while (true){
				res = ask(1ll << now, 1ll << (now + 1));
				if (res == "y")
					now ++;
				else{
					int lo = (1ll << now), hi = (1ll << (now + 1));
					while (hi - lo > 1){
						int mid = (hi + lo) >> 1;
						string res = ask((1ll << now), mid);
						if (res == "x")
							hi = mid;
						else
							lo = mid;
					}
					cout << "! " << hi << endl;
					break;
				}
			}
		}
		cin >> s;
		if (s != "start")
			break;
	}
}