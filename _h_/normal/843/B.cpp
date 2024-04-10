#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = a; i < (b); ++i)
#define rrep(i,a,b) for(int i = b; i --> (a);)
#define all(v) v.begin(),v.end()
#define trav(x,v) for(auto &x : v)
#define sz(v) (int)(v).size()
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, s, x;
	cin >> n >> s >> x;
	srand(n+s+x);
	set<int> toask;
	toask.insert(s);
	rep(_,0,n/50){
		int i = -1;
		do {
			i = rand()%n*43499%n + 1;
		} while(toask.count(i));
		toask.insert(i);
	}
	vector<pii> ques;
	trav(i, toask){
		cout << "? " << i << endl;
		int val, next;
		cin >> val >> next;
		ques.emplace_back(val, next);
	}
	sort(all(ques));
	if(ques[0].first >= x){
		cout << "! " << ques[0].first << endl;
		return 0;
	}
	int i = 0;
	while(i+1 < sz(ques) && ques[i+1].first < x) ++i;
	int j = ques[i].second;
	while(true){
		if(j == -1){
			cout << "! -1" << endl;
			return 0;
		}
		cout << "? " << j << endl;
		int val, next;
		cin >> val >> next;
		if(val >= x){
			cout << "! " << val << endl;
			return 0;
		}
		j = next;
	}
}