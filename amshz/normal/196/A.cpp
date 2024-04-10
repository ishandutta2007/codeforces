# include <bits/stdc++.h>

using namespace std;

int main(){
	string a;
	cin >> a;
	deque <char> dq;
	for (int i=0; i<a.size(); i++){
		while (dq.size() > 0 and dq.back() < a[i]) dq.pop_back();
		dq.push_back(a[i]);
	}
	for (int i=0; i<dq.size(); i++) cout << dq[i];
}