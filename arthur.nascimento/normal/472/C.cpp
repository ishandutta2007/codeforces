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

#define inf (999999999)
#define pii pair<int,int>
#define pip pair<int,pii>
#define pll pair<long long,long long>
#define pff pair<long double,long double>
#define eps 1e-6
 
#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

#define pb push_back
#define mod 1000000007
#define maxn 100100

using namespace std;

struct person {
	string a,b;
	int idx;
	bool operator<(person comp)const{
		return idx < comp.idx;
	}
}

v[100100];

main(){

		int n;
		scanf("%d",&n);

		for(int i=0;i<n;i++)
			cin >> v[i].a >> v[i].b;
		for(int i=0;i<n;i++){
			int u;
			scanf("%d",&u);
			v[u-1].idx = i;
		}

		sort(v,v+n);

		int f = 1, s = 1;

		for(int i=1;i<n;i++){

			int f2 = 0, s2 = 0;
			if(f && v[i].a > v[i-1].a) f2 = 1;
			if(s && v[i].a > v[i-1].b) f2 = 1;
			if(f && v[i].b > v[i-1].a) s2 = 1;
			if(s && v[i].b > v[i-1].b) s2 = 1; 
			f = f2;
			s = s2;
			debug("i = %d %d %d\n",i,f,s);
			//cout << v[i].a << " " << v[i].b << endl;
			
		}

		if(f || s)
			printf("YES\n");
		else
			printf("NO\n");

}