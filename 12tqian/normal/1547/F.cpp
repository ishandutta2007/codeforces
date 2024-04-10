#include <bits/stdc++.h>
 
using namespace std;
 
#define f0r(a, b) for (long long a = 0; a < b; a++)
#define f1r(a, b, c) for (long long a = b; a < c; a++)
#define f0rd(a, b) for (long long a = b; a >= 0; a--)
#define f1rd(a, b, c) for (long long a = b; a >= c; a--)
#define ms(arr, v) memset(arr, v, sizeof(arr))
#define mp(a, b) make_pair(a, b)
#define pb push_back
#define f first
#define s second
 
#define ao(a, n) {for (int ele = 0; ele < n; ele++) { if (ele) cout << " "; cout << a[ele]; } cout << '\n';}
 
typedef long long ll;
typedef double ld;
typedef long double lld;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpi;
typedef vector<pll> vpl;
 
const ll inf = 1e9+7;
 
const int MOD = 1e9 + 7;
typedef decay<decltype(MOD)>::type T;
struct mi {
	T val;
	explicit operator T() const { return val; }
	mi() { val = 0; }
	mi(const long long& v) {
		val = (-MOD <= v && v <= MOD) ? v : v % MOD;
		if (val < 0) val += MOD; }
	friend ostream& operator<<(ostream& os, const mi& a) { return os << a.val; }
	friend bool operator==(const mi& a, const mi& b) { return a.val == b.val; }
	friend bool operator!=(const mi& a, const mi& b) { return !(a == b); }
	friend bool operator<(const mi& a, const mi& b) { return a.val < b.val; }
	mi operator-() const { return mi(-val); }
	mi& operator+=(const mi& m) {
		if ((val += m.val) >= MOD) val -= MOD;
		return *this; }
	mi& operator-=(const mi& m) {
		if ((val -= m.val) < 0) val += MOD;
		return *this; }
	mi& operator*=(const mi& m) { val = (long long) val * m.val % MOD;
		return *this; }
	friend mi pow(mi a, long long p) {
		mi ans = 1; assert(p >= 0);
		for (; p; p /= 2, a *= a) if (p & 1) ans *= a;
		return ans; }
	friend mi inv(const mi& a) { assert(a != 0); return pow(a, MOD - 2); }
	mi& operator/=(const mi& m) { return (*this) *= inv(m); }
	friend mi operator+(mi a, const mi& b) { return a += b; }
	friend mi operator-(mi a, const mi& b) { return a -= b; }
	friend mi operator*(mi a, const mi& b) { return a *= b; }
	friend mi operator/(mi a, const mi& b) { return a /= b; }
};

inline int binary_gcd(int a, int b) {
	if (a == 0 || b == 0) {
		return a + b;
	}
	char n = __builtin_ctz(a);
	char m = __builtin_ctz(b);
	a >>= n;
	b >>= m;
	n = min(n, m);
	while (a != b) {
		int d = a - b;
		char s = __builtin_ctz(d);
		bool f = a > b;
		b = f ? b : a;
		a = (f ? d : -d) >> s;
	}
	return a << n;
}

//Segment tree from geeks for geeks. Source: https://www.geeksforgeeks.org/gcds-of-a-given-index-ranges-in-an-array/


// To store segment tree
int *st;
  
  
/*  A recursive function to get gcd of given
    range of array indexes. The following are parameters for
    this function.
  
    st    --> Pointer to segment tree
    si --> Index of current node in the segment tree. Initially
               0 is passed as root is always at index 0
    ss & se  --> Starting and ending indexes of the segment
                 represented by current node, i.e., st[index]
    qs & qe  --> Starting and ending indexes of query range */
int findGcd(int ss, int se, int qs, int qe, int si)
{
    if (ss>qe || se < qs)
        return 0;
    if (qs<=ss && qe>=se)
        return st[si];
    int mid = ss+(se-ss)/2;
    return binary_gcd(findGcd(ss, mid, qs, qe, si*2+1),
               findGcd(mid+1, se, qs, qe, si*2+2));
}
  
//Finding The gcd of given Range
int findRangeGcd(int ss, int se, int arr[],int n)
{
    if (ss<0 || se > n-1 || ss>se)
    {
        cout << "Invalid Arguments" << "\n";
        return -1;
    }
    return findGcd(0, n-1, ss, se, 0);
}
  
// A recursive function that constructs Segment Tree for
// array[ss..se]. si is index of current node in segment
// tree st
int constructST(int arr[], int ss, int se, int si)
{
    if (ss==se)
    {
        st[si] = arr[ss];
        return st[si];
    }
    int mid = ss+(se-ss)/2;
    st[si] = binary_gcd(constructST(arr, ss, mid, si*2+1),
                 constructST(arr, mid+1, se, si*2+2));
    return st[si];
}
  
/* Function to construct segment tree from given array.
   This function allocates memory for segment tree and
   calls constructSTUtil() to fill the allocated memory */
int *constructSegmentTree(int arr[], int n)
{
   int height = (int)(ceil(log2(n)));
   int size = 2*(int)pow(2, height)-1;
   st = new int[size];
   constructST(arr, 0, n-1, 0);
   return st;
}


int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	ll t; cin >> t;

	while (t--) {
		ll n; cin >> n;
		int arr[n];

		int g;

		f0r(i, n) {
			cin >> arr[i];
			if (i == 0) {
				g = arr[i];
			} else {
				g = binary_gcd(g, arr[i]);
			}
		}



		f0r(i, n) {
			arr[i] /= g;
		}

		constructSegmentTree(arr, n);

		//binary search on the answer

		ll l = 0; ll r = n-1;

		while (l < r) {
			ll m = (l + r)/2;
			bool works = 1;
			f0r(i, n) {
				ll gcd;
				if (i + m >= n) {
					ll wrap = i + m - n;
					gcd = binary_gcd(findRangeGcd(i, n-1, arr, n), findRangeGcd(0, wrap, arr, n));
				} else {
					gcd = findRangeGcd(i, i+m, arr, n);
				}

				if (gcd != 1) {
					works = 0;
					break;
				}
			}

			if (works) {
				r = m;
			} else {
				l = m+1;
			}
		}

		cout << l << endl;



		
		


	}

	
}