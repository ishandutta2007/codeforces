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

int n;
int m;
ll l1[200200];
ll l2[200200];
char c1[200200];
char c2[200200];
char x[2000];

void read(int &n, ll l[], char c[]){
	for(int i = 0; i < n; i++){
		scanf("%s", x);
		int len = strlen(x);
		c[i] = x[len-1];
		len-=2;
		for(int j = 0; j < len; j++)
			l[i] = l[i] * 10 + x[j] - '0';
	}
	int la = 1;
	for(int j = 1; j < n; j++){
		if(c[j] == c[la-1]){
			l[la-1] += l[j];
		}
		else {
			c[la] = c[j];
			l[la] = l[j];
			la++;
		}
	}
	n = la;
	
}
int z[500500];
int z2[500500];

int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    scanf("%d %d", &n, &m);
    read(n, l1, c1);
    read(m, l2, c2);
    if(m == 1){
    	ll ans = 0;

    	for(int i = 0; i < n; i++){
    		if(c1[i] == c2[0] && l1[i] >= l2[0]) ans += l1[i] - l2[0] + 1;
    	}
    	cout << ans << endl;
    	return 0;
    }
    if(m == 2){
    	
    	ll ans = 0;
    	for(int i = 1; i < n; i++){
    		if(c1[i-1] == c2[0] && c1[i] == c2[1]) ans += (l1[i-1]>= l2[0] && l1[i] >= l2[1]);
    	}
    	cout << ans << endl;
    	return 0;
    }
    pair < int, ll > cc1 = mp(c2[0], l2[0]);
    pair < int, ll > cc2 = mp(c2[m-1], l2[m-1]);
    for(int i = 1; i < m; i++){
    	l2[i-1] = l2[i];
    	c2[i-1] = c2[i];
    }
    m-=2;
    	
    int mm = n + m;
    for(int i = 0; i < n; i++){
    	l2[i+m] = l1[i];
    	c2[i+m] = c1[i];
    }
    
    for (int i=1, l=0, r=0; i<mm; ++i) {
		if (i <= r)
			z[i] = min (r-i+1, z[i-l]);
		while (i+z[i] < mm && l2[z[i]] == l2[i+z[i]])
			++z[i];
		if (i+z[i]-1 > r)
			l = i,  r = i+z[i]-1;
	}
	for (int i=1, l=0, r=0; i<mm; ++i) {
		if (i <= r)
			z2[i] = min (r-i+1, z2[i-l]);
		while (i+z2[i] < mm && c2[z2[i]] == c2[i+z2[i]])
			++z2[i];
		if (i+z2[i]-1 > r)
			l = i,  r = i+z2[i]-1;
	}
	ll ans = 0;
	for(int i = m+1; i < mm; i++){

		if(z[i] >= m && z2[i] >= m){
			int ind = i + m;
			if(cc1.f == c2[i-1] && l2[i-1] >= cc1.s){
				if(ind < mm && cc2.f == c2[ind] && cc2.s <= l2[ind]) ans++;
			}
		}
	}
	cout << ans << endl;


    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}