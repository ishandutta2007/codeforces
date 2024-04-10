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

char str[100100];
int f[220];

main(){

		int n;
		scanf("%d",&n);
		scanf(" %s",str);

		int fm = -1;

		for(int i=0;i<n;i++){
			f[str[i]]++;
			if(f[str[i]] > fm)
				fm = f[str[i]];
		}

		int a = 0;
		if(f['A'] == fm)a++;
		if(f['T'] == fm)a++;
		if(f['C'] == fm)a++;
		if(f['G'] == fm)a++;

		long long ans = 1;
		for(int i=0;i<n;i++)
			ans = (ans*a)%mod;

		cout << ans << endl;

}