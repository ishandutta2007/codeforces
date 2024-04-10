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
	int n, k, a[111111];
	for(int i = 1; i<111100; i++)
		a[i] = i;
	cin >> n >> k;
	if(k == n){
		cout << -1;
		return 0;
	}
	if(k%2 == 0){
		if(n%2 == 0){
			int z = (n-k)/2;
			for(int i = 1; i<=z; i++){
				swap(a[2*i], a[2*i-1]);
			}
		}
		else {
			int z = (n-k)/2;
			for(int i =1; i<=z; i++)
				swap(a[2*i], a[2*i+1]);
		}
	}
	else {
		if(n%2 == 0){
			int z = (n-k)/2;
			for(int i = 1; i<=z; i++){
				swap(a[2*i], a[2*i+1]);
			}
		}
		else {
			int z = (n-k)/2;
			for(int i =1; i<=z; i++)
				swap(a[2*i], a[2*i-1]);
		}
	}
	for(int i = 1; i<=n; i++)
		cout << a[i] << " ";
    return 0;
}