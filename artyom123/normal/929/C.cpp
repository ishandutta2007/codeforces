#include <bits/stdc++.h>
using namespace std;
struct man{
	int n;
	int type;
};
bool comp (man i, man j) {
	return (i.n < j.n);
}
int main() {
	int g, d, f;
	cin >> g >> d >> f;
	vector <man> a;
	for ( int i = 0; i < g; i++) {
		int now;
		cin >> now;
		man h;
		h.n = now;
		h.type = 1;
		a.push_back(h);
	}
	for ( int i = 0; i < d; i++) {
		int now;
		cin >> now;
		man h;
		h.n = now;
		h.type = 2;
		a.push_back(h);
	}
	for ( int i = 0; i < f; i++) {
		int now;
		cin >> now;
		man h;
		h.n = now;
		h.type = 3;
		a.push_back(h);
	}
	int r = 0;
	long long first = 0;
	long long second = 0;
	long long third = 0;
	sort(a.begin(), a.end(), comp);
	if ( a[0].type == 1) {
		first = 1;
	}
	else if ( a[0].type == 2) {
		second = 1;
	}
	else {
		third = 1;
	}
	long long answer = 0;
	for ( int l = 0; l < a.size(); l++){
		while ( r + 1 < a.size() && a[l].n * 2 >= a[r + 1].n){
			r += 1;
			if ( a[r].type == 1) {
				first += 1;
			}
			else if ( a[r].type == 2) {
				second += 1;
			}
			else {
				third += 1;
			}
		}
		
		if ( a[l].type == 1 && second >= 2 && third >= 3) {
			long long def = ((second - 1) * second) / 2;
			long long at = (third * (third - 1) * (third - 2)) / 6;
			answer += (def * at);
		}
		if ( a[l].type == 2 && first >= 1 && third >= 3 && second >= 2) {
			long long def = first;
			long long def1 = second - 1;
			long long at = (third * (third - 1) * (third - 2)) / 6;
			answer += (def1 * def * at);
		}
		if ( a[l].type == 3 && first >= 1 && second >= 2 && third >= 3) {
			long long def = first;
			long long def1 = ((third - 2) * (third - 1)) / 2;
			long long at = ((second - 1) * second) / 2;
			answer += (def1 * def * at);
		}
		if ( a[l].type == 1) {
				first -= 1;
		}
		else if ( a[l].type == 2) {
				second -= 1;
		}
		else {
				third -= 1;
		}
		
	}
	cout << answer;
	return 0;
}