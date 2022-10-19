#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <set>
#include <map>
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;


ll mod = 1e9+7;

ll two(int a){
	if(a==0) return 1%mod;
	ll b = two(a/2);
	if(a%2==0) return (b*b)%mod;
	return (b*b*2)%mod;
}


int main() {
	string s;
	cin >> s;
	int as = 0;
	ll tot = 0;
	for(int i=0; i<s.size(); i++){
		if(s[i]=='a') as++;
		else{
			tot+=(two(as)-1);
			tot%=mod;
		}
	}
	cout << tot << endl;
}