#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#define pb push_back
#define ll long long
#define mp make_pair
#define ff first
#define sc second
#define pii pair<int,int>
#define pis pair<int, string>
#define psi pair<string, int>
using namespace std;
int main () { 
	string s;
	int n;
	map < string, int > m;
	cin >> n;
	for(int i = 0; i<n; i++){
		cin >> s;
		int z = m[s];
		if(z == 0){
			cout << "OK\n";
		}
		else {
			cout << s << z<<endl;
		}
		m[s]++;
	}
    return 0;
}