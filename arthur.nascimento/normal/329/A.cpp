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
#define eps 1e-9

#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

using namespace std;

stack<pii> ans;
char M[110][110];

main(){

	int n;
	scanf("%d\n",&n);

	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)
		M[i][j] = getchar();
		getchar();
}	


	for(int i=0;i<n;i++){

		bool ok = 0;

		for(int j=0;j<n && !ok;j++)
			if(M[i][j] == '.'){
				ok = 1;
				ans.push(pii(i+1,j+1));
				}

		}

	if(ans.size() != n){

		while(ans.size())
			ans.pop();

		for(int j=0;j<n;j++){

		bool ok = 0;

		for(int i=0;i<n && !ok;i++)
			if(M[i][j] == '.'){
				ok = 1;
				ans.push(pii(i+1,j+1));
				}

		}

		}

	if(ans.size() != n)
		printf("-1");
	else 
		while(ans.size()){
			printf("%d %d\n",ans.top().first,ans.top().second);
			ans.pop();

		}

		}