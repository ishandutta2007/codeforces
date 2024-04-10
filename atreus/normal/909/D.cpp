#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_map>
#include <map>
#include <cmath>

#define MP make_pair
#define F first
#define S second
#define PB push_back

using namespace std;

vector <pair <int, char> > v;


int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	string s;
	cin >> s;
	int cnt = 1;
	for (int i = 1; i < s.size(); i++){
		if (s[i] != s[i - 1]){
			v.PB (MP(cnt, s[i - 1]));
			cnt = 1;
		}
		else 
			cnt ++;
	}
	v.PB(MP(cnt, s[s.size() - 1]));
	int ans = 0;
	for (int i = 1; i <= 1000 * 1000; i++){
		vector <pair<int, char> > a;
//		for (int j = 0; j < v.size(); j++)
//			cout << v[j].F << " -> " << v[j].S << " ";
//		cout << endl;
		if (v.size() <= 1)
			break;
		for (int j = 0; j < v.size(); j++){
			v[j].F --;
			if (j > 0 and j < v.size() - 1)
				v[j].F --;
		}
		int k = 0;
		char c = '0';
		for (int j = 0; j < v.size(); j++){
			if (v[j].F > 0){
				if (c == v[j].S || c == '0'){
					c = v[j].S;
					k += v[j].F;
				}
				else {
					a.PB(MP(k, c));
					c = v[j].S;
					k = v[j].F;
				}
			}
		}
		a.push_back(MP(k, c));	
		v = a;
		ans ++;
	}
	cout << ans << endl;
}