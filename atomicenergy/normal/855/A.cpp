#include <iostream>
#include <vector>
#include <iomanip>
#include <map>
using namespace std;



int main() {
	int n;
	cin >> n;
	map<string, bool> m;
	for(int i=0; i<n; i++){
		string s;
		cin >> s;
		if(!m[s]){
			cout << "NO" << endl;
		}else{
			cout << "YES" << endl;
		}
		
		m[s] = true;
	}
}