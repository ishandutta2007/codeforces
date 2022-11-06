#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = (a); i < (b); ++i)
#define rrep(i,a,b) for(int i = (b); i --> (a);)
#define all(v) (v).begin(),(v).end()
#define trav(x,v) for(auto &x : v)
#define sz(v) int(v.size())
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> pii;

int main(){
	rrep(i,0,10){
		cout << i << endl;
		string s;
		getline(cin, s);		
		if(s == "cool" ||
	       	s == "not bad" || 
		s == "don't think so" ||
	        s == "don't touch me!" ||
		s == "great!"){
			cout << "normal" << endl;
			return 0;
		}		
		if(s == "terrible" ||
	       	s == "worse" || 
		s == "are you serious?" ||
	        s == "go die in a hole" ||
		s == "no way"){
			cout << "grumpy" << endl;
			return 0;
		}

	}
}