#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <memory.h>
using namespace std;
#define forn(i,n) for(int i=0;i<(n);++i)
#define forv(i,v) forn(i,(int)(v).size())
#define iinf 1000000000
#define all(v) (v).begin(),(v).end()



int main(){
#ifdef __ASD__
	freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#endif

	ios_base::sync_with_stdio(false);

	int n;
	cin>>n;
	vector<int> ar(n);
	forn(i,n)
		cin>>ar[i];
	sort(all(ar));

	rotate(ar.begin(),ar.end()-1,ar.end());
	if(ar[0]==1)
		ar.back()=2;
	else
		ar[0]=1;
	forn(i,n)
		cout<<ar[i]<<' ';

	return 0;
}