#include <iostream>
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
 
#define INF (1<<30)
#define pii pair<int,int>
#define pll pair<long long,long long>
#define eps 1e-9
 
#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

using namespace std;

int v[220];

main(){

		int n,k;
		scanf("%d%d",&n,&k);

		for(int i=0;i<n;i++)
			scanf("%d",v+i);

		int ans = v[0];

		for(int i=0;i<n;i++)
			for(int j=i;j<n;j++){

				int sum = 0;
				vector<int> in;
				vector<int> out;

				for(int l=0;l<n;l++)
					if(l >=i && l <= j){
						sum += v[l],
						in.push_back(v[l]);
					}
					else
						out.push_back(v[l]);

				sort(in.begin(), in.end());
				sort(out.begin(), out.end());

				for(int l=0;l<k && l < in.size() && l < out.size() && in[l] < out[out.size()-l-1]; l++)
					sum = sum - in[l] + out[out.size()-l-1];

				ans = max(ans, sum);
					

			}

		printf("%d\n",ans);

	}