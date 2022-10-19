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

main(){

		int a=0, b=0;

		char ch;

		while((ch=getchar()) != '\n')
			if(ch == '1')
				a++;
		while((ch=getchar()) != '\n')
			if(ch == '1')
				b++;

		if(a >= b || (a%2 == 1 && a + 1 == b))
			printf("YES\n");
		else
			printf("NO\n");

	}