#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
//#define STB_IMAGE_IMPLEMENTATION
//#include "stb_image.h"
#define _CRT_SECURE_NO_DEPRECATE
#define _USE_MATH_DEFINES
#include <array>
#include <iostream>
#include <fstream>
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
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <forward_list>
#include <thread>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned int uint;
typedef unsigned char uchar;
typedef double ld;
typedef pair<int, int> pii;
typedef pair<short, short> pss;
typedef pair<LL, LL> pll;
typedef pair<ULL, ULL> puu;
typedef pair<ld, ld> pdd;
template<class T> inline T sqr(T x) { return x * x; }
template<class T> inline T parse(const string&s){T x;stringstream ss(s);ss>>x;return x;}
#define left asdleft
#define right asdright
#define link asdlink
#define unlink asdunlink
#define next asdnext
#define prev asdprev
#define y0 asdy0
#define y1 asdy1
#define mp make_pair
#define MT make_tuple
#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define clr(ar,val) memset(&ar, val, sizeof(ar))
#define istr stringstream
#define forn(i,n) for(int i=0;i<(n);++i)
#define forv(i,v) forn(i,sz(v))
#define X first
#define Y second
const ld EPS = 1e-12;
const int INF = 1000*1000*1000;
const LL LINF = INF * 1ll * INF;
const ld DINF = 1e200;
const ld PI = 3.1415926535897932384626433832795l;
int gcd(int a,int b){return a?gcd(b%a,a):b;}
LL gcd(LL a,LL b){return a?gcd(b%a,a):b;}
LL gcdex(LL a,LL b,LL &x,LL &y){if(!a){x=0,y=1;return b;}LL k=b/a;LL g=gcdex(b-k*a,a,y,x);x-=k*y;return g;}
LL inv(LL a,LL m){assert(m>1);LL x,y,g;g=gcdex(a,m,x,y);return (x%(m/g)+m/g)%m/g;}
LL crt(LL a1,LL m1,LL a2,LL m2){LL a=(a2-a1%m2+m2)%m2;LL x,y,g;g=gcdex(m1,m2,x,y);if(a%g)return -1;LL m=m1/g*m2;assert(x+m2>=0);x=a/g*(x+m2)%m2;LL r=(a1+x*m1)%m;assert(r%m1==a1 && r%m2==a2);return r;}
LL powmod(LL a,LL p,LL m){assert(p>=0);LL r=1;while(p){if(p&1)r=r*a%m;p>>=1;a=a*a%m;}return r;}
bool isprime(LL a){if(a<=1)return false;for (LL i=2;i*i<=a;++i){if(a%i==0)return false;}return true;}
LL sqrtup(LL a){if(!a)return 0;LL x=max(0ll,(LL)sqrt((ld)a));while(x*x>=a)--x;while((x+1)*(x+1)<a)++x;return x+1;}
LL isqrt(LL a){if(a<=0){assert(!a);return 0;}LL x=(LL)sqrt((ld)a);while(sqr(x+1)<=a)++x;while(x*x>a)--x;return x;}
LL sgn(LL x){return x<0?-1:x>0?1:0;}
ld randf(){ld m=RAND_MAX+1.;return (((rand()+.5)/m+rand())/m+rand())/m;}
template<class T> ostream& operator<<(ostream &s, const vector<T> &v);
template<class A,class B> ostream& operator<<(ostream &s, const pair<A,B> &p);
template<class K,class V> ostream& operator<<(ostream &s, const map<K,V> &m);
template<class T> ostream& operator<<(ostream &s, const set<T> &m);
template<class T,size_t N> ostream& operator<<(ostream &s, const array<T,N> &a);
template<class... T> ostream& operator<<(ostream &s, const tuple<T...> &t);
template<class T> ostream& operator<<(ostream &s, const vector<T> &v){s<<'[';forv(i,v){if(i)s<<',';s<<v[i];}s<<']';return s;}
template<class A,class B> ostream& operator<<(ostream &s, const pair<A,B> &p){s<<"("<<p.X<<","<<p.Y<<")";return s;}
template<class K,class V> ostream& operator<<(ostream &s, const map<K,V> &m){s<<"{";bool f=false;for(const auto &it:m){if(f)s<<",";f=true;s<<it.X<<": "<<it.Y;}s<<"}";return s;}
template<class T> ostream& operator<<(ostream &s, const set<T> &m){s<<"{";bool f=false;for(const auto &it:m){if(f)s<<",";f=true;s<<it;}s<<"}";return s;}
template<class T> ostream& operator<<(ostream &s, const multiset<T> &m){s<<"{";bool f=false;for(const auto &it:m){if(f)s<<",";f=true;s<<it;}s<<"}";return s;}
template<class T,class V,class C> ostream& operator<<(ostream &s, const priority_queue<T,V,C> &q) {auto a=q;s<<"{";bool f=false;while(!a.empty()){if(f)s<<",";f=true;s<<a.top();a.pop();}return s<<"}";}
template<class T,size_t N> ostream& operator<<(ostream &s, const array<T,N> &a){s<<'[';forv(i,a){if(i)s<<',';s<<a[i];}s<<']';return s;}
template<class T> ostream& operator<<(ostream &s, const deque<T> &a){s<<'[';forv(i,a){if(i)s<<',';s<<a[i];}s<<']';return s;}
template<size_t n,class... T> struct put1 { static ostream& put(ostream &s, const tuple<T...> &t){s<<get<sizeof...(T)-n>(t);if(n>1)s<<',';return put1<n-1,T...>::put(s,t);} };
template<class... T> struct put1<0,T...> { static ostream& put(ostream &s, const tuple<T...> &t){return s;} };
template<class... T> ostream& operator<<(ostream &s, const tuple<T...> &t){s<<"(";put1<sizeof...(T),T...>::put(s,t);s<<")";return s;}
ostream& put3(ostream &s, const char*, bool) {return s;}
template<class U,class... T> ostream& put3(ostream &s, const char *f, bool fs, U&& u, T&&... t) {
  while(*f==' ')++f;if (!fs)s<<", ";auto nf=f;int d=0;while(*nf&&(*nf!=','||d)){if(*nf=='(')++d;else if(*nf==')')--d;++nf;}
  auto nf2=nf;while(nf2>f&&*(nf2-1)==' ')--nf;fs=*f=='"';if(!fs){s.write(f,nf2-f);s<<"=";};s<<u;if(fs)s<<' ';if(*nf)++nf;return put3(s,nf,fs,forward<T>(t)...);}
#ifdef __ASD__
auto qweasdt0 = chrono::steady_clock::now();
#define dbg(...) do { cerr.setf(ios::fixed,ios::floatfield);cerr.precision(6);double qweasdt = chrono::duration_cast<chrono::duration<double>>(chrono::steady_clock::now() - qweasdt0).count();cerr << '[' << __LINE__ << ' ' << qweasdt << "] "; put3(cerr, #__VA_ARGS__, 1, ##__VA_ARGS__); cerr << endl; }while(false)
#include "draw.h"
#define draw(x,...) dr::get().add((new dr::x)__VA_ARGS__)
#define drawc(x) dr::get().x
#else
#define dbg(...) do{}while(false)
#define draw(...) do{}while(false)
#define drawc(...) do{}while(false)
#endif



int main(int argc, char **argv){
  ios_base::sync_with_stdio(false);cin.tie(0);cout.precision(20);srand(35964);

  /*
  int x,y,n;
  unsigned char *data = stbi_load("/Users/kolmike/Downloads/minijordan2.png", &x, &y, &n, 1);
  assert(x==64 && y==64);
  forn(i,x*y){
    cout<<(data[i]<127);
    //if(i%64==0) cout<<endl;
    }*/

  const char* a="0000000000000000000000000010101111110100000000000000000000000000000000000000000000000010111010101001011111000000000000000000000000000000000000000000111010001000110100001001000000000000000000000000000000000000011110101011111000011110101110100000000000000000000000000000000011000000101000001111000010101011000000000000000000000000000000100110111110111011101001011000100101000000000000000000000000000111001001000000101000111100110110110110000000000000000000000001111110110110111011101110000110010010001110000000000000000000001111111111110000100000100010110011011010011100000000000000000001111111111111111111101111111001111001111111111000000000000000001111111111111111111111111111111111111111111111110000000000000001111111111111111111111111111111111111111111111111100000000000000111111111111111111111111111111111111111111111111110000000000000111111111111111111111111111111111111111111111111111100000000000111111111111111111111111111111111111111111111111111111000000000011111111111111111111111111111111111111111111111111111100000000011111111111111111111111111111111111111111111111111111111000000011111111111111111111111111111111111111111111111111111111110000000011111111111111111111111111111111111111111111111111111111000000000011111111111100010011111111111111000101011111111111110000000110000011111111100100011111111111111101000000011111111000000000011110000011111000110100011111111111111101101100101100000001100011111110000010001110011100111111111110100100011000000000111111001111111110000010010011011000111111111011011111001000011111111100111111111111011011100000111001111111000100100001110111111111110011111111100000100011101110001111111101011111010001001011111111011111111111101110100100100010011111100100100001101110001111111111111111111100010010110111011101111010111011110011100010111111111111111111110111111011110000100101000010100101111000111011111111111111111111000001001001110111000101011011010010001001001111111111111111111110110111101101110001011100000111101011111101111111111111111111110001110010010001110100111011110010111000100011111111111111111111110000011011101101110110000010011011001000101111111111111111111111101101000010100001010010101101000110110111111111111111111111111000011110101010101111011010010111001110001111111111111111111111110100100011100011110001001100001001100011111111111111111111111111111000111000101101101101100101110100100111111111111111111111111111111000101111110000011111110001000111111111111111101111111111111111001000011111010111111111110001001111111111111100111111111111111111111111111111000011111111111111111111111111110011111111111111111111111111101001011111111111111111111111111111001111111111111111111111111010001111111111111111111111111111111100011111111111111111111111100010001111111111111111111111111111100001111111001111111111111111111011111111111111111111111111111110000011111110101111111111111111000111111111111111111111011111110000001111111000100011111111111001011111111111011111010000111111000000111111101010100101000110101100101001011000110000010111111100000001111111100011000001000000011000110000001010011101111111100000000011111110100111101111011100111000011101111101011111111100000000001111111111010010010001011110111011010000010001111111110000000000011111111000011011010000100010100001110100011111111110000000000000111111111011000111110110101000101100011111111111110000000000000011111111100111001010001110001011100100011111111111000000000000000111111111000111100011101101111011110111111111111000000000000000001111111110110000101000000100001011111111111111000000000000000000011111111111101011110110110101100111111111111000000000000000000000111111111111100001111000010000111111111111000000000000000000000000111111111111111111110111111111111111110000000000000000000000000001111111111111111111111111111111111110000000000000000000000000000001111111111111111111111111111111100000000000000000000000000000000011111111111111111111111111111100000000000000000000000000000000000001111111111111111111111110000000000000000000000000000000000000000001111111111111111111100000000000000000000000000000000000000000000000011111111111100000000000000000000000000";
  int r,c;
  cin>>r>>c;
  cout<<(a[r*64+c]=='1'?"IN":"OUT");

  return 0;
}