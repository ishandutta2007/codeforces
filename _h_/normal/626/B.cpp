#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <set>
#include <stack>
#include <queue>
#include <cmath>
#include <bitset>
#include <random>
#include <cassert>
#include <cstdio>
using namespace std;
#define rep(i,a,b) for(int i = (a); i < int(b); ++i)
#define rrep(i,a,b) for(int i = (b); i --> int(a);)
#define allof(v) v.begin(),v.end()
#define pb push_back
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pii;
typedef vector<bool> vb;
const ll inf = 1LL<<60;

int main(){
	int n;
	cin >> n;
	string s;
	cin >> s;
	map<char,int> k;
	for(char &c : s) ++k[c];
	if(k.size() == 1){
		cout << s[0] << endl;
	} else if(k.size() == 3){
		cout << "BGR\n";
	} else {
		if(k['B']==0 || k['G']>1 || k['R']>1) cout << "B";
		if(k['G']==0 || k['B']>1 || k['R']>1) cout << "G";
		if(k['R']==0 || k['G']>1 || k['B']>1) cout << "R";
		cout << endl;
	}
}