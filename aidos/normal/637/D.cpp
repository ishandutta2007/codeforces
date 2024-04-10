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

int a[200200];
int b[200200];
int len[200200];
int n, m, s, d;

void no(){
	cout << "IMPOSSIBLE\n";
	exit(0);
}
void run(int x){
	printf("RUN %d\n", x);
}
void jump(int x){
	printf("JUMP %d\n", x);
}

int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    scanf("%d %d %d %d", &n, &m, &s, &d);
    for(int i = 0; i < n; i++){
    	scanf("%d", &a[i]);
    }
    sort(a, a + n);
	if(a[0]<=s) no();
	vector < int > cur;
	int la = 1;
	b[0] = a[0];
	len[0] = a[0];
	for(int i = 1; i < n; i++){
		if(a[i] - a[i-1] <= s + 1){
			len[la-1] = a[i];
		}
		else {
			b[la] = a[i];
			len[la] = a[i];
			la++;
		}
	}
	int st = 0;
	for(int i = 0; i < la; i++){
		if(len[i] - b[i] + 2 > d) no();
		cur.pb(b[i]-st - 1);
		st = b[i] - 1;
		cur.pb(st - len[i] - 1);
		st = len[i] + 1;
	}
	if(st < m) cur.pb(m - st);
	for(int i = 0; i < cur.size(); i++){
		if(cur[i] < 0) jump(-cur[i]);
		else run(cur[i]);
	}
	
	




    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}