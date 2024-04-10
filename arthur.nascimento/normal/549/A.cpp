#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <assert.h>
#include <stdio.h>
#include <ctime>
#include <cstdlib>
#include <utility>
#include <string.h>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>

#define inf (999999999999LL)
#define pii pair<int,int>
#define pip pair<int,pii>
#define pll pair<long long,long long>
#define eps 1e-8
 
#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

#define pb push_back	
#define maxn 500500
#define mod 1000000007

using namespace std;

char str[55][55];

main(){

		int n,m;
		scanf("%d%d",&n,&m);

		for(int i=0;i<n;i++) scanf(" %s",str[i]);

		int ans = 0;
		for(int i=0;i<n-1;i++) for(int j=0;j<m-1;j++){

			vector<char> v;
			v.pb(str[i][j]);
			v.pb(str[i+1][j]);
			v.pb(str[i][j+1]);
			v.pb(str[i+1][j+1]);
			sort(v.begin(),v.end());
			if(v[0] == 'a' && v[1] == 'c' && v[2] == 'e' && v[3] == 'f') ans++;

		}

		cout << ans << endl;

}