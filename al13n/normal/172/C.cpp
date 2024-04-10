#pragma comment(linker,"/STACK:256000000")
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <memory.h>
#include <string>
#include <set>
#include <queue>
#include <map>
#include <iomanip>
using namespace std;
#define forn(i,n) for(int i=0;i<(n);++i)
#define forv(i,v) forn(i,(int)(v).size())
#define iinf 1000000000
#define linf 1000000000000000000LL
#define all(v) (v).begin(),(v).end()
#define pb push_back
#define mp make_pair
#define lng long long
#define eps 1e-10
#define EQ(a,b) (fabs((a)-(b))<eps)
#define SQ(a) ((a)*(a))
#define PI 3.14159265359
#define index asdindex
#define FI first
#define SE second
#define prev asdprev
#define PII pair<int,int> 
#define X first
#define Y second
#define unlink asdunlink
typedef unsigned char uchar;
typedef unsigned int uint;

int res[110000];

int main(){
#ifdef __ASD__
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(false);

	int n,m;
	cin>>n>>m;
	lng T=0;
	for(int q=0;q<n;q+=m){
		int cnt=min(m,n-q);
		vector<PII> v(cnt);
		forn(i,cnt){
			lng t;
			cin>>t>>v[i].X;
			v[i].Y=q+i;
			T=max(T,t);
		}
		sort(all(v));
		int p=0;
		for(int i=0;i<cnt;){
			T+=v[i].X-p;
			p=v[i].X;
			int j=i;
			while(j<cnt&&v[j].X==v[i].X){
				res[v[j].Y]=T;
				++j;
			}
			T+=1+(j-i)/2;
			i=j;
		}
		T+=p;
	}

	forn(i,n){
		cout<<res[i]<<' ';
	}

    return 0;
}