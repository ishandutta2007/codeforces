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
	int n;
	cin >> n;
	vector < bool > p(10000000, 0);
	for(int i = 2; i<2000000; i++)
		if(!p[i]){
			for(int j = i; j<2000000; j+=i)
				p[j] = 1;
			printf("%d ", i);
			n--;
			if(n == 0) break;
		}
	return 0;
}