#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <math.h>
using namespace std;
#define fort(i,a,b) for(int i=a;i<b;i++)
#define fori(i,b) fort(i,0,b)
#define forn(i,b) fort(i,1,b)
typedef long long lol;
#define into(b) cin >> b;
#define def(b) lol b; into(b)
#define co cout <<
#define con continue;
#define el << endl;
#define ex return 0;
typedef vector<int> veci;


int main() {
	def(t)
	fori(kkk,t){
		def(n)
		veci arr(n);
		int cur=2;
		int sum=0;
		fori(i,n){
			def(a)
			if(a<n){
				arr[a]++;
			}
		}
		fori(i,n){
			cur=min(cur,arr[i]);
			sum+= cur;
		}
		co sum el

	}
	return 0;
}