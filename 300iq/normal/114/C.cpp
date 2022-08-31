#include <bits/stdc++.h>
#define int long long
using namespace std;

int t[100010];
int p[100010];

main() {
    vector <string> gg;
    string s;
    while (cin >> s)
	gg.push_back(s);
    for (int i = 0; i < (int) gg.size(); i++) {
	int v = gg[i].size();
	if (v < 3) {
	    cout << "NO" << endl;
	    return 0;
	} else {
	    while (gg[i].size() < 10)
		gg[i] = '0' + gg[i];
	    v = gg[i].size();
	    int z = v - 3;
	    string f = "";
	    for (int j = z; j < v; j++) 
		f += gg[i][j];
	    if (f == "etr") {
		p[i] = 2;
		t[i] = 2;
	    }
	    z = v - 4;
	    f = "";
	    for (int j = z; j < v; j++)
		f += gg[i][j];
	    if (f == "etra") {
		p[i] = 1;
		t[i] = 2;
	    }
	    if (f == "lios") {
		t[i] = 1;
		p[i] = 2;
	    }
	    z = v - 5;
	    f = "";
	    for (int j = z; j < v; j++)
		f += gg[i][j];
	    if (f == "liala") {
		p[i] = 1;
		t[i] = 1;
	    }
	    z = v - 6;
	    f = "";
	    for (int j = z; j < v; j++) 
		f += gg[i][j];
	    if (f == "initis" || f == "inites") {
		p[i] = (f == "initis" ? 2 : 1);
		t[i] = 3;
	    }
	    if (t[i] == 0) {
		cout << "NO" << endl;
		return 0;
	    }
	}
    }
    int n = gg.size();
    set <int> g;
    if (n == 1) {
	cout << "YES" << endl;
	return 0;
    }
    int i = 0;
    while (t[i] == 1) {
	g.insert(p[i]);
	i++;
    }
    if (t[i] != 2) {
	cout << "NO" << endl;
	return 0;
    }
    g.insert(p[i]);
    i++;
    while (i < n && t[i] == 3) {
	g.insert(p[i]);
	i++;
    }
    if (i != n || g.size() != 1) {
	cout << "NO" << endl;
	return 0;
    }
    cout << "YES" << endl;
    return 0;
}