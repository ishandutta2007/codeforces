#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#define fastio cin.tie(0);ios_base::sync_with_stdio(0);cout.tie(0);

using namespace std;

int main(){
	fastio;
	int t;
	cin >> t;
	while(t--){
		int a,b;
		cin >> a >> b;
		int c=(a+b)/2-min(a,b);
		set<int> s;
		for(int i=c;i<=a+b;i+=2){
			if(i>=c && a+b-i>=c){
				s.insert(i);
				s.insert(a+b-i);
			}
		}
		cout << s.size() << "\n";
		for(auto i=s.begin();i!=s.end();i++){
			cout << *i << " ";
		}
		cout << "\n";
	}
	return 0;
}