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
int n, s, t, p[111000], k=0;
cin >> n >> s >> t;
bool u[111000];
for(int i=0; i<n; i++){
	cin >> p[i];
	u[i] = 0;
}
while(true){         
	if(s==t){
		cout << k;
		return 0;
	}
	else if(u[s-1]==1){
		cout << -1;
		return 0;
	}
	u[s-1] = 1;
	k++;
	s = p[s-1];		
}
return 0;
}