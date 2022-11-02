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
ll a[200200], l = 0, k = 0, n,t = 1;
int main () {
	map < int, int > m;
	cin >> n;
	n*=2;
	for(int i = 0; i<n; i++)
		cin >> a[i];
	n/=2;
	for(int i = 0; i<n; i++)
		if(a[i] == a[i+n]) m[a[i]]++;
	cin >> l;
	n*=2;
	sort(a, a+n);
	a[n] = -1;
	for(int i = 0; i<n; i++){
		if(!i || a[i] != a[i-1]){
			for(int j = i; a[j] == a[i]; j++){
				int u = j- i+1;
				if(u%2 == 0 && u/2 <= m[a[i]]){
					t *= u/2;
				}
				else t *= u;
				t %= l;
			}
		}
	}
	cout << t;
    return 0;
}