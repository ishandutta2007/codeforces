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
	int n, a[1111], b[1111], cnt = 0, elem = 0;
	cin >> n;
	for(int i = 0; i<n; i++){
		cin >> b[i];
		a[i] = 1;
	}
	for(int i = 0; i<n; i++){
		if(a[i]){
			cnt++;
			int el = 0;
			for(int j = 0; j<n; j++){
				if(b[i] == b[j]){
					a[j] = 0;
					el++;
				}
			}
			elem = max(el, elem);
		}
	}
	cout << elem << " " << cnt;
    return 0;
}