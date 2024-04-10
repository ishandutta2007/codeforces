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
typedef pair<point, int> poin;
lol gcd(lol a, lol b) {
	if (b == 0) {
		return a;
	}
	return gcd(b, a%b);
}
bool myfunc(point i,point j){
	return i.first>j.first || (i.first==j.first && i.second>j.second);
}
//#include <bits/stdc++.h>

int main() {
  ios::sync_with_stdio(false);
  defn
  vecl a(n);
  vecl b(n);
  fori(i,n){
  into(a[i])
  }
  fori(i,n){
  into(b[i])
  }
  vecl ra(n);
  vecl ura(n);
  vecl rb(n);
  vecl urb(n);
  lol sum=0;
  lol urealsum=0;
  forib(i,n){
    sum+=a[i];
    ra[i]=sum;
    urealsum+=a[i]*i;
    ura[i]=urealsum;
  }
  sum=0;
  urealsum=0;
  forib(i,n){
    sum+=b[i];
    rb[i]=sum;
    urealsum+=b[i]*i;
    urb[i]=urealsum;
  }
  lol maxm=0;
  sum=0;
  fori(i,n){
    lol cur=sum;
    if(i%2==0){
        cur+=ura[i]+i*ra[i];
        cur+=(2*n-1+i)*rb[i]-urb[i];
        sum+=(2*i)*a[i];
        sum+=(2*i+1)*b[i];
    }
    if(i%2==1){
        cur+=urb[i]+i*rb[i];
        cur+=(2*n-1+i)*ra[i]-ura[i];
        sum+=(2*i+1)*a[i];
        sum+=(2*i)*b[i];
    }
    maxm=max(maxm,cur);
  }
  co maxm el
  ex
}