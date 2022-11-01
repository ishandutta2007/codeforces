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
#define ell << '\n';
#define ex return 0;
#define all(arr) arr.begin(), arr.end()
typedef vector<lol> veci;

int main() {
	ios::sync_with_stdio(0);
	int t=1;
	fori(kkk,t){
		def(n)
		veci arr(n+1);
		fori(i,n){
			def(a)
					arr[i]+=a;
			arr[i+1]-=a;
		}
		lol sum=0;
		forn(i,n){
			if(arr[i]>0){
				sum+=arr[i];
			}
		}
		co (arr[0]+sum)/2 + ((arr[0]+sum)>0 && ((arr[0]+sum)&1)) el
		def(m)
		fori(i,m){
			def(l) def(r) def(q)
			l--;
			if(l!=0){
				if(arr[l]>0){
					sum-=arr[l];
				}
			}
			arr[l]+=q;
			if(l!=0){
				if(arr[l]>0){
					sum+=arr[l];
				}
			}
			if(r!=n){
				if(arr[r]>0){
					sum-=arr[r];
				}
			}
			arr[r]-=q;
			if(r!=n){
				if(arr[r]>0){
					sum+=arr[r];
				}
			}
			co (arr[0]+sum)/2 + ((arr[0]+sum)>0 && ((arr[0]+sum)&1)) ell
		}
	}
	return 0;
}