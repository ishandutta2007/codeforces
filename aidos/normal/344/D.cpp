#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <stack>
using namespace std;
int main() {
	string s;
	cin >> s;
	int n = s.size(), k = 0, z=0;
	if(n & 1){
		cout << "No";
		return 0;
	}
	stack < char > q;
	for(int i = 0; i<n; i++){
		if(q.empty()) {
			q.push(s[i]);
		}
		else {
			if(q.top() == s[i]){
				q.pop();
			}
			else q.push(s[i]);
		}
	}
	if(q.size() == 0)cout << "Yes";
	else cout << "No";
	return 0;
}