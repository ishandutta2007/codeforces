/*
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 





 
 

*/

#include <bits/stdc++.h>

using namespace std;

#define int long long

main() {
	int a, b;
	cin >> a >> b;
	int lf = 1, rg = 100000;
	while(lf < rg) {
		int md = (lf + rg) / 2;
		if(lf == md) md++;
		if(md * md <= a) lf = md;
		else rg = md - 1;
	}
	int ca = lf;
	lf = 0, rg = 100000;
	while(lf < rg) {
		int md = (lf + rg) / 2;
		if(lf == md) md++;
		if(md * (md + 1) <= b) lf = md;
		else rg = md - 1;
	}
	int cb = lf;
	if(ca > cb) cout << "Valera";
	else cout << "Vladik";
}