#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#define pb push_back
#define ll long long
#define mp make_pair
#define ff first
#define sc second
#define pii pair<int,int>
#define pis pair<int, string>
#define psi pair<string, int>
using namespace std;
int main () {
	//freopen ("input.txt","r",stdin);
	//freopen ("output.txt","w",stdout);
	string s, t;
	bool d = 0;
	vector < string > v;
	while(getline(cin, s)){
		bool ok = 1;
		int n = s.size();
		for(int i = 0; i<n; i++){
			if(s[i] == ' '){
				continue;
			}
			if(s[i] == '#') {ok = 0; break;}
			else { break;}
		}
		if(!ok){
			if(d) v.pb(t);
			v.pb(s);
			t = "";
		}
		else {
			for(int i =0; i<n; i++)
				if(s[i] !=' ') t+=s[i];
		}
		d = ok;
	}
	if(d){
		v.pb(t);
	}
	for(int i = 0; i<v.size(); i++)
		cout << v[i] << endl;
    return 0;
}