#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
#pragma GCC target("avx2")  //Enable AVX

#include <bits/stdc++.h>

#define pb push_back

#define mp make_pair
#define f first
#define s second
#define pii pair < int, int >
#define ull unsigned long long
#define pll pair < ll, ll >
#define forit(it, s) for(__typeof(s.begin()) it = s.begin(); it != s.end(); it ++)
#define all(s) s.begin(), s.end()
#define sz(a) (int)a.size()
typedef long long ll;

const int inf = (1 << 29) - 1;
const int maxn = (int)8e5 + 10; //maximum + 10
const int mod = (int) 1e9 + 7;
using namespace std;
int p[26];
int rp[26];
char s[maxn];
char t[maxn];
bool ans[maxn];
int n;
int m;
int a[maxn];
int b[maxn];
int c[maxn];
int aa[maxn];
int ba[maxn];
int ca[maxn];

int N;
struct cd
{	
	double a, b;
	cd() {
		a = 0;
		b = 0;
	}
	cd(double x) {
		a = x;
		b = 0;
	}
	cd(double x, double y) {
		a = x;
		b = y;
	}
	const cd operator+(const cd &c) const
		{return cd(a + c.a, b + c.b);}
	const cd operator-(const cd &c) const
		{return cd(a - c.a, b - c.b);}
	const cd operator*(const cd &c) const
		{return cd(a*c.a - b*c.b, a*c.b + b*c.a);}
	const cd operator / (const double x) {
		return cd(a/x, b/x);
	}
	const double real(){
		return a;
	}
};
const double PI = acos(-1);

int reverse(int num, int lg_n) {
    int res = 0;
    for (int i = 0; i < lg_n; i++) {
        if (num & (1 << i))
            res |= 1 << (lg_n - 1 - i);
    }
    return res;
}
int rev_pos[maxn];
vector<cd>W[2];

void fft(vector<cd> & a, bool invert) {

    for (int i = 0; i < N; i++) {
        if (i < rev_pos[i])
            swap(a[i], a[rev_pos[i]]);
    }
    int cur = 0;
    for (int len = 2; len <= N; len <<= 1) {
        for (int i = 0; i < N; i += len) {
            for (int j = 0; j < len / 2; j++) {
                cd u = a[i+j], v = a[i+j+len/2] * W[invert][cur];
                a[i+j] = u + v;
                a[i+j+len/2] = u - v;
                cur++;
            }
        }
    }

    if (invert) {
    	for(int i = 0; i < a.size(); i++)
            a[i] = a[i]/N;
    }
}
void mult() {
    vector<cd> fa(N), fb(N);
    for(int i = 0; i < N; i++) {
    	fa[i] = cd(a[i], aa[i]);
    }
    for(int i = 0; i < N; i++) {
    	fb[i] = cd(b[i], -ba[i] * (N+1));
    }
    fft(fa, false);
    fft(fb, false);
    for (int i = 0; i < N; i++)
        fa[i] = fa[i] * fb[i];
    fft(fa, true);

    for (int i = 0; i < N; i++){
        c[i] = ll(fa[i].real() + 0.5) % (N+1);
        ca[i] = ll(fa[i].real() + 0.5)/(N+1);
    }
}
void calc(char z) {
	for(int i = 0; i < n; i++) {
		if(s[i] == z) a[i] = 1;
		else if(s[i] == rp[z-'a'] + 'a') a[i] = 1;
		else a[i] = 0;
	}
	for(int i = 0; i < m; i++) {
		if(t[i] == z) {
			b[i] = 1;
		} else b[i] = 0;
	}
	for(int i = 0; i < n; i++) {
		if(s[i] == z+1) aa[i] = 1;
		else if(s[i] == rp[z+1-'a'] + 'a') aa[i] = 1;
		else aa[i] = 0;
	}
	for(int i = 0; i < m; i++) {
		if(t[i] == z+1) {
			ba[i] = 1;
		} else ba[i] = 0;
	}
	mult();
	int cur = 0;
	for(int i = 0; i < m; i++) {
		cur += b[i];
		if(i >= n) cur -= b[i-n];
		if(cur != c[i]) ans[i] = 0;
	}
	cur = 0;
	for(int i = 0; i < m; i++) {
		cur += ba[i];
		if(i >= n) cur -= ba[i-n];
		if(cur != ca[i]) ans[i] = 0;
	}
	return;
	cout << z << "\n";
	for(int i = 0; i < n; i++) cout << a[i] << " ";
	cout << "\n";
	for(int i = 0; i < m; i++) cout << b[i] << " ";
	cout << "\n";

	for(int i = 0; i < m; i++) cout << c[i] << " ";
	cout << "\n";
	cout << "----\n";
}
void precalc(){
 
    int lg_n = 0;
    while ((1 << lg_n) < N)
        lg_n++;
 
    for (int i = 0; i < N; i++) {
        rev_pos[i] = reverse(i, lg_n);
    }
 	for(int invert = 0; invert < 2; invert++){
    	for (int len = 2; len <= N; len <<= 1) {
        	double ang = 2 * PI / len * (invert ? -1 : 1);
        	cd wlen(cos(ang), sin(ang));
        	for (int i = 0; i < N; i += len) {
            	cd w(1);
            	for (int j = 0; j < len / 2; j++) {
            		W[invert].pb(w);
                	w = w * wlen;
            	}
        	}
    	}
	}
}
void solve(){
	for(int i = 0; i < 26; i++) {
		scanf("%d", &p[i]);
		p[i]--;
		rp[p[i]] = i;
	}
	scanf("%s%s", s, t);
	n = strlen(s);
	m = strlen(t);
	for(int i = 0; i < m; i++) {
		ans[i] = 1;
	}
	reverse(s, s + n);
	N = 1;
	while(N <= m) N *= 2;
	//N *= 2;
	precalc();
	for(int i = 0; i < 26; i+=2) {
		calc(i+'a');
	}
	for(int i = n - 1; i < m; i++) {
		if(ans[i]) printf("1");
		else printf("0");
	}
	printf("\n");
}
int main () {

    int t=1;
    //scanf("%d", &t);
    for(int i=1; i <= t; i++){
      //printf("Case #%d: ", i);
      solve();
    }
    
    return 0;
}