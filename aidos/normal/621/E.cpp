#include <bits/stdc++.h>

using namespace std;


#define pb push_back
#define ll long long
#define mp make_pair
#define f first
#define s second
#define pii pair < int, int >
#define pll pair < ll, ll >
#define all(s) s.begin(), s.end()
#define sz(s) (int) s.size()
#define vi vector < int >

const int inf = (int)1e9;
const int mod = (int) 1e9 + 7;

int a[202][111];

int cnt[202];

int n, b, k, x;
int d[202][202];
void mul(int a[][111], int c[][111]){
	for(int i = 0; i < x; i++)
		for(int j = 0; j < x; j++)
			d[i][j] = 0;
	for(int i = 0; i < x; i++){
		for(int j = 0; j < x; j++){
			for(int k = 0; k < x; k++)
				d[i][j] = (d[i][j] + a[i][k] * 1ll * c[k][j]) % mod;
		}
	}
	for(int i = 0; i < x; i++)
		for(int j = 0; j < x; j++)
			a[i][j] = d[i][j];
}

void binpow(int a[][111], int b){
	if(b == 0){
		for(int i = 0; i < x; i++)
			for(int j = 0; j < x; j++)
				a[i][j] = (i == j);
		return;
	}
	int c[111][111];
	for(int i = 0; i < x; i++)
		for(int j = 0; j < x;j++)
			c[i][j] = a[i][j];
	if(b % 2 == 1){
		binpow(a, b - 1);
		mul(a, c);
	}else {
		binpow(a, b/2);
		mul(a, a);
	}
}


int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    cin >> n >> b >> k >> x;
    for(int i = 0, c; i < n; i++){
    	cin >> c;
    	cnt[c]++;
    }
    for(int i = 0; i < x; i++){
    	int z = i % x;
    	for(int j = 0; j < 10; j++){
    		int h = (z * 10 + j) % x;
    		a[z][h] += cnt[j];
    	}
    }
/*    for(int i = 0; i < x; i++){
    	for(int j = 0; j < x; j++)
    		cout << a[i][j] << " ";
    	cout <<endl;
    }
    cout << endl;  */
    binpow(a, b);
  /*  for(int i = 0; i < x; i++){
    	for(int j = 0; j < x; j++)
    		cout << a[i][j] << " ";
    	cout <<endl;
    }*/
    cout << a[0][k] << endl;

    


    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}