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

int a,b;
char str[100100];

main(){
    
	int n;
	int ans = 0;
	scanf("%d\n",&n);

	scanf(" %s",str);

	for(int i=3;i<strlen(str);i++){

		if(i%n == 0)
			if(str[i-3] == str[i-2] && str[i-2] == str[i-1])
				ans++;

		}
    	printf("%d\n",ans);
}