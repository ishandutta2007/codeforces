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

#define inf 99999999999.
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
#define mod 1000000007
#define maxn 100100

using namespace std;

int gcd(int a,int b){
	return b ? gcd(b,a%b) : a;
}

main(){

		int n;
		scanf("%d",&n);
		multiset<int> S;
		vector<int> ans;
		for(int i=0;i<n*n;i++){
			int u;
			scanf("%d",&u);
			S.insert(-u);
		}

		while(S.size()){
			int a = -*(S.begin());
			S.erase(S.begin());
			for(vector<int> :: iterator it = ans.begin(); it < ans.end(); it++){
				S.erase(S.find(-gcd(*it,a)));
				S.erase(S.find(-gcd(*it,a)));
			}
			ans.pb(a);
		}

		for(int i=0;i<n;i++)
			printf("%d\n",ans[i]);

}