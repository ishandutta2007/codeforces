#pragma comment(linker, "/STACK:512000000")
#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <climits>
#include <ctime>
#include <numeric>
#include <vector>
#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <complex>
#include <deque>
#include <functional>
#include <list>
#include <map>
#include <string>
#include <sstream>
#include <set>
#include <stack>
#include <queue>
using namespace std;
template<class T> inline T sqr(T x) { return x * x; }
template<class T> inline string tostr(const T & x) { stringstream ss; ss << x; return ss.str(); }
typedef long long lng;
typedef unsigned long long ulng;
typedef unsigned int uint;
typedef unsigned char uchar;
typedef long double ld;
typedef pair<int, int> PII;
typedef pair<PII, int> PIII;
typedef pair<lng, lng> PLL;
typedef pair<lng, int> PLI;
typedef pair<ld, ld> PDD;
#define left asdleft
#define right asdright
#define link asdlink
#define unlink asdunlink
#define next asdnext
#define prev asdprev
#define y0 asdy0
#define y1 asdy1
#define mp make_pair
#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define clr(ar,val) memset(ar, val, sizeof(ar))
#define istr stringstream
#define forn(i,n) for(int i=0;i<(n);++i)
#define forv(i,v) forn(i,sz(v))
#define X first
#define Y second
const double EPS = 1e-6;
const int INF = 1000*1000*1000;
const char CINF = 102;
const lng LINF = INF * 1ll * INF;
const ld PI = 3.1415926535897932384626433832795;



int main() {
#ifdef __ASD__
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif

	/*
	string s;
	while(getline(cin,s)){
		cout<<'"'<<s<<"\",";
	}
	return 0;//*/
	
	const char *ans[]={"111111101010101111100101001111111","100000100000000001010110001000001","101110100110110000011010001011101","101110101011001001111101001011101","101110101100011000111100101011101","100000101010101011010000101000001","111111101010101010101010101111111","000000001111101111100111100000000","100010111100100001011110111111001","110111001111111100100001000101100","011100111010000101000111010001010","011110000110001111110101100000011","111111111111111000111001001011000","111000010111010011010011010100100","101010100010110010110101010000010","101100000101010001111101000000000","000010100011001101000111101011010","101001001111101111000101010001110","101101111111000100100001110001000","000010011000100110000011010000010","001101101001101110010010011011000","011101011010001000111101010100110","111010100110011101001101000001110","110001010010101111000101111111000","001000111011100001010110111110000","000000001110010110100010100010110","111111101000101111000110101011010","100000100111010101111100100011011","101110101001010000101000111111000","101110100011010010010111111011010","101110100100011011110110101110000","100000100110011001111100111100000","111111101101000101001101110010001",};
	int a,b;
	cin>>a>>b;
	cout<<ans[a][b];

	return 0;
}