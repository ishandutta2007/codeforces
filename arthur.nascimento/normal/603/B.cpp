#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <assert.h>
#include <stdio.h>
#include <ctime>
#include <cstdlib>
#include <string>
#include <utility>
#include <string.h>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <complex>

#define inf 1000000007
#define pii pair<int,int>
#define pip pair<int,pii>
#define pll pair<long long,long long>
#define pif pair<int,double>
#define eps 1e-7

#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

#define pb push_back
#define mod 1000000007
#define maxn 100100
using namespace std;
typedef long long ll;

main(){

	long long p,k;
	cin >> p >> k;

	int ord = 2;
	long long aux = (k*k)%p;
	while(aux != 1 && k != 0){
		aux = (aux*k)%p;
		ord++;
	}

	int e = (p-1)/ord;

	if(k == 0)
		e = p-1;
	if(k == 1)
		e = p;
	
	long long ans = 1;
	for(int i=0;i<e;i++)
		ans = (ans*p)%mod;
		
	cout << ans << endl;

}