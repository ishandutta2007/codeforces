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
#define mod 1000000007
#define maxn 100100

using namespace std;

main(){

		int n;
		scanf("%d\n",&n);

		vector<int> u;
		for(int i=0;i<n;i++){
			char ch;
			scanf(" %c",&ch);
			ch -= '0';
			if(ch <= 1) continue;
			if(ch == 4){u.pb(3);u.pb(2);u.pb(2);}
			else if(ch == 8){u.pb(7);u.pb(2);u.pb(2);u.pb(2);}
			else if(ch == 6){u.pb(5); u.pb(3);}
			else if(ch == 9){u.pb(7); u.pb(3); u.pb(3); u.pb(2);}
			else u.pb(ch);
		}

		sort(u.begin(),u.end());
		reverse(u.begin(),u.end());

		for(int i=0;i<u.size();i++)
			printf("%d",u[i]);
		printf("\n");

}