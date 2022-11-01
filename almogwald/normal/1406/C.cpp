#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <math.h>
#include <algorithm>
using namespace std;
#define fort(i,a,b) for(int i=a;i<b;i++)
#define fori(i,b) fort(i,0,b)
#define forn(i,b) fort(i,1,b)
#define forin(i,b) fori(i,b.size())
#define fortb(i,a,b) for(int i=b-1;i>=a;i--)
#define forib(i,b) fortb(i,0,b)
#define fornb(i,b) fortb(i,1,b)
typedef long long lol;
#define into(b) cin >> b;
#define def(b) lol b; into(b)
#define co cout <<
#define con continue;
#define br break;
#define el << endl;
#define ex return 0;
#define all(arr) arr.begin(), arr.end()
typedef vector<int> veci;

int main() {
	def(t)
	fori(kkk,t){
		def(n)
		vector<veci> cons(n);
		fori(i,n-1){
			def(a) def(b)
			a--; b--;
			cons[a].push_back(b);
			cons[b].push_back(a);
		}
		veci stk(1);
		veci visit(n);
		veci ord;
		while(!stk.empty()){
			int cur=stk.back();
			stk.pop_back();
			if(visit[cur]){
				con
			}
			visit[cur]=1;
			ord.push_back(cur);
			forin(i,cons[cur]){
				stk.push_back(cons[cur][i]);
			}
		}
		veci sum(n);
		int mid=0;
		int midd=0;
		forib(i,n){
			int cur=ord[i];
			sum[cur]++;
			forin(i,cons[cur]){
				sum[cur]+=sum[cons[cur][i]];
			}
			if(sum[cur]>=(n+1)/2){
				mid=cur;
				midd=i;
				br
			}
		}
		int oth=-1;
		fori(i,n){
			int cur=ord[i];
			if(cons[cur].size()==1){
				oth=cur;
				if(i<midd|| i>=midd+sum[mid]){
					br
				}
			}

		}
		co oth+1 <<' ' << cons[oth][0]+1 el
		co oth+1 <<' ' << mid+1 el
	}
	return 0;
}