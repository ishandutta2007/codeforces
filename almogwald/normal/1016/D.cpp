#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <math.h>
using namespace std;
#define forr(i,a,b,c) for(int i=a;i<b;i+=c)
#define forrb(i,a,b,c) for(int i=a;i>b;i-=c)
#define fori(i,n) forr(i,0,n,1)
#define forib(i,n) forrb(i,n-1,-1,1)
#define forn(i,n) forr(i,1,n,1)
#define fornb(i,n) forrb(i,n-1,0,1)
#define fort(i,m,n) forr(i,m,n,1)
#define fortb(i,m,n) forrb(i,n-1,m-1,1)
#define forin(i,arr) fori(i,arr.size())
#define forinb(i,m,n) forib(i,arr.size())
#define into(i) cin >> i;
#define def(i) int i; into(i)
#define deft(t,i) t i; into(i)
#define defn def(n)
#define defp def(p)
#define defm def(m)
#define defk def(k)
#define defa def(a)
#define defb def(b)
#define defc def(c)
#define defd def(d)
#define vec(a) vector<a>
#define co cout <<
#define cas(p) co "Case #" << p+1 <<": ";
#define el << endl;
#define ex return 0;
#define qii queue<int>
#define sti stack<int>
#define dei deque<int>
#define con continue;
#define br break;
#define out(i) co i <<' ';
#define outv(a,n) fori(iere,n){out(a[iere])} co "" el;
#define maxi 1000000013
#define mod %1000000009;
typedef vector<int> veci;
typedef long long lol;
typedef vector<lol> vecl;
#define table(name,n,m) vector<veci> name(n,veci (m));
#define tablel(name,n,m) vector<vecl> name(n,vecl (m));
typedef pair<int, int> point;
typedef pair<point, point> poin;
lol gcd(lol a, lol b) {
	if (b == 0) {
		return a;
	}
	return gcd(b, a%b);
}
bool myfunc(poin ii,poin jj){
	point i=ii.first;
	point j=jj.first;
	return i.first<j.first || (i.first==j.first && i.second<j.second);
}
int main() {
	ios::sync_with_stdio(false);
	defn defm
	veci pow2(30);
	pow2[0]=1;
	forn(i,30){
	    pow2[i]=pow2[i-1]*2;
	}
    int xora=0;
	int xorb=0;
	veci a(n);
	veci b(m);
	fori(i,n){
	    into(a[i])
	    xora = xora^a[i];
	}
	fori(i,m){
	    into(b[i])
	    xorb = xorb^b[i];
	}
	if(xora!=xorb){
        co "NO" el
        ex
	}
	co "YES" el
	table(ans,n,m);
	fori(i,n){
	    fori(j,m){
            if(a[i]^b[j]!=0){
                int c=a[i]^b[j];
                a[i]=a[i]^c;
                b[j]=b[j]^c;
                ans[i][j]=c;
            }
        }
        int c=a[i];
        a[i]=a[i]^c;
        b[0]=b[0]^c;
        ans[i][0]=ans[i][0]^c;
	}
	fori(j,m){
        int c=b[j];
        a[0]=a[0]^c;
        b[j]=b[j]^c;
        ans[0][j]=ans[0][j]^c;
	}
	fori(i,n){
	    outv(ans[i],m)
	}
	ex
}