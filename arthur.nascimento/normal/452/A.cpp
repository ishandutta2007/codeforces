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

string str[] = {"vaporeon","jolteon","flareon", "espeon", "umbreon", "leafeon", "glaceon", "sylveon"};

main(){

		int n;
		scanf("%d",&n);

		char ch[15];
		scanf(" %s",ch);

		for(int i=0;i<8;i++){
			int ok = 1;
			if(str[i].length() != n)continue;
			for(int j=0;j<n;j++)
				if(ch[j] != '.' && ch[j] != str[i][j]) ok = 0;
			if(!ok)continue;
			cout << str[i] << endl;
		}
}