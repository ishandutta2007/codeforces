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

#define inf 99999999999999999LL
#define pii pair<int,int>
#define pip pair<int,pii>
#define pll pair<long long,long long>
#define pif pair<int,double>
#define eps 1e-5

#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

#define pb push_back
#define mod 1000000007
#define maxn 10010000

using namespace std;

main(){

	long long x,y;
	cin >> x >> y;

	string ans = "";

	while((x > 1 || y > 1) && (x != 0 && y != 0) && x != y){
		if(x > y){
			long long u = x/y;
			if(x%y == 0) u--;
			ans = ans + to_string(u) + "A";
			x -= u*y;
		}
		else {
			long long u = y/x;
			if(y%x == 0) u--;
			ans = ans + to_string(u) + "B";
			y -= u*x;
		}
	}

	if(x == 1 && y == 1)
		cout << ans << endl;
	else
		cout << "Impossible\n";

}