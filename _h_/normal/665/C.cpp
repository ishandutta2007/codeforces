#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <set>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <bitset>
#include <random>
#include <cassert>
#include <cstdio>
#include <cstring>
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
typedef long double ld;

int main(){
	cin.sync_with_stdio(0);
	string s;
	cin >> s;
	rep(i,1,s.size()){
		if(s[i]==s[i-1]) s[i]++;
		else continue;
		if(s[i]>'z')s[i]='a';
		if(i+1<s.size() && s[i]==s[i+1])s[i]++;
		if(s[i]>'z')s[i]='a';
	}
	cout << s << endl;
}