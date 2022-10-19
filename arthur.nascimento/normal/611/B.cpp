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
#define maxn 260

using namespace std;

main(){
	long long a,b;
	cin >> a >> b;
	int ans = 0;
	for(int i=0;i<64;i++)
		for(int j=0;j<i-1;j++){
			unsigned long long u = (1LLU<<i)-1 - (1LLU<<j);
			if(u >= a && u <= b)
				ans++;
		}
	cout << ans << endl;
}