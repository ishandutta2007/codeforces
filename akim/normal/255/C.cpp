#pragma comment(linker, "/stack:20000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 4040;
 
unordered_map <int, int> M;
int n, a[N], mx = 0;
 
int main (){
    M.reserve(4000*4000 + 2);
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> a[i];
        // a[i] = i;
	}
	for (int i = 1; i < n; i++){
		for (int j = 0; j < i; j++){
			int x = a[i] - a[j];
			M[i * 2000000 + x + 1000000] = (M.count(j * 2000000 - x + 1000000) ? M[j * 2000000 - x + 1000000] : 0) + 1;
			if(mx < M[i * 2000000 + x + 1000000])
    			mx = M[i * 2000000 + x + 1000000];
		}
	}
	cout << mx + 1;
	return 0;
}