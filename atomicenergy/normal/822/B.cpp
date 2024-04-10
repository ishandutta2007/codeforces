#include <iostream>
using namespace std;



int main() {
	int n, m;
	cin >> n >> m;
	string s, t;
	cin >> s >> t;
	int min = -1;
	int minpos = -1;
	for(int i=0; i<=m-n; i++){
		int same = 0;
		for(int j=0; j<n; j++){
			if(s[j] == t[i+j]){
				same++;
			}
		}
		if(same>min){
			min = same;
			minpos = i;
		}
	}
	cout << n-min << endl;
	for(int j=0; j<n; j++){
		if(s[j] != t[minpos+j]){
			cout << (j+1) << " ";
		}
	}
	
}