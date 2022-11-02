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
	int n, a[110], k = 0, l = 1, m = 0;
	cin >> n;
	for(int i = 0; i<n; i++)
		cin >> a[i];
	sort(a, a+n);
	for(int i = 0; i<n; i++)
		for(int j = 0; j<i; j++){
			if(a[i] - a[j] > m){
				m = a[i] - a[j];
				k = j;
				l = i;
			}
		}
	cout << a[l] << " ";
	for(int i = 0; i<n; i++)
		if(i!=k && i!=l) cout << a[i] << " ";
	cout << a[k];
    return 0;
}