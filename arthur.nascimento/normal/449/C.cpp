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
#define eps 1e-8
 
#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

#define pb push_back

using namespace std;

int foi[100100];

int primo(int a){
	for(int i=2;i*i<=a;i++)
		if(a%i == 0) return 0;
	return 1;
}

main(){

		int n;
		scanf("%d",&n);

		vector<pii> ans;

		for(int i=n;i>=2;i--) if(primo(i)) {

			vector<int> v;

			for(int j=1;i*j<=n;j++) 
				if(!foi[i*j]) v.pb(i*j);

			if(v.size() == 1) continue;

			if(v.size()%2 == 1){

				swap(v[0],v[1]);
				reverse(v.begin(), v.end());
				v.pop_back();

			}

			for(int j=0;j<v.size();j+=2)
				ans.pb(pii(v[j],v[j+1])), foi[v[j]] = foi[v[j+1]] = 1;

		}

		printf("%d\n",ans.size());

		for(int i=0;i<ans.size();i++)
			printf("%d %d\n",ans[i].first,ans[i].second);

}