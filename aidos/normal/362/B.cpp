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
	int n, d[11111], m;
	cin >> n >> m;
	for(int i = 0; i<m; i++)
		cin >> d[i];
	sort(d, d+m);
	if(d[m-1] == n || d[0] == 1){
		cout << "NO";
		return  0;
	}
	for(int i = 2; i<m; i++){
		if(d[i] == d[i-1] + 1 && d[i-1] == d[i-2]+1){
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
    return 0;
}