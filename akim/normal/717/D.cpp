#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <cstring>
#include <map>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <bitset>
#define f first
#define s second
#define ll long long
#define ull unsigned long long
#define mp make_pair
#define pb push_back
#define vi vector <int>
#define ld long double
#define pii pair<int, int>
using namespace std;    
const int N = int(3e5), mod = int(1e9)  + 7; 

double c[128][129];
struct matrix{
 	double a[128][128];
 	matrix (){
 		for (int i = 0; i < 128; i++)
 			for (int j = 0; j < 128; j++)
 				a[i][j] = 0;
 		for (int i = 0; i < 128; i++)
 			a[i][i] = 1;
 	 			
 	}
 	void operator *= (const matrix &X){
 		for (int i = 0; i < 128; i++)
 			for (int j = 0; j < 128; j++) {
 			 	c[i][j] = 0;
 			 	for (int t = 0; t < 128; t++) {
 			 	 	c[i][j] += a[i][t] * X.a[t][j];
 			 	}
			}	
 		for (int i = 0; i < 128; i++)
 			for (int j = 0; j < 128; j++)
 				a[i][j] = c[i][j];
 	}

} z, x, res;


double f[N];
int n, m;

matrix binpow(matrix A, int n) {
		while (n) {
	 	if (n&1)
	 		res *= A;
	 	A *= A;
	 	n /= 2;
	}
	return res;
}

int main () {
 	scanf("%d%d", &n, &m);

 	for (int i = 0; i <= m; i++) {
 	 	scanf("%lf", &f[i]);

 	}
 	for (int i = 0; i < 128; i++)
 		for (int j = 0; j < 128; j++)
 			x.a[i][j] = f[i^j];
    
 	z = binpow(x, n);

    cout << 1-z.a[0][0] << endl;



return 0;
}