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
	int n, a[30], sum = 0;
	cin >> n;
	for(int i = 0; i<7; i++){
		cin >>a[i];
		sum+=a[i];
	}
	n%=sum;
	if(n == 0)n=sum;
	for(int i = 0; i<7; i++){
		if(a[i] >= n){
			cout << i+1;
			return 0;
		}
		n-=a[i];
	}
	return 0;
}