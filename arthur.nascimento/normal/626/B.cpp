#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <assert.h>
#include <stdio.h>
#include <ctime>
#include <cstdlib>
#include <string>
#include <utility>
#include <string.h>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <complex>

#define inf 1000000007
#define pii pair<int,int>
#define pip pair<int,pii>
#define pll pair<long long,long long>
#define pif pair<int,double>
#define eps 1e-7

#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

#define pb push_back
#define mod 1000000007
#define maxn 200200

typedef long long ll;
using namespace std;

int cnt[1010];
char str[12010];

main(){

	int n;
	scanf("%d",&n);
	char ch;
	scanf(" %s",str);
	for(int i=0;i<n;i++)
		cnt[str[i]]++;

	if(n == 1){
		printf("%c\n",str[0]);
		return 0;
	}

	int r = cnt['R'], g = cnt['G'], b = cnt['B'];

	if(r && g && b){
		printf("BGR\n");
		return 0;
	}

	if(b && r+g == 0){
		printf("B\n");
		return 0;
	}

	if(r && g+b == 0){
		printf("R\n");
		return 0;
	}

	if(g && b+r == 0){
		printf("G\n");
		return 0;
	}

	vector<char> ans;

	if(b == 0){
		ans.pb('B');
		if(g > 1) ans.pb('R');
		if(r > 1) ans.pb('G');
	}
	if(r == 0){
		ans.pb('R');
		if(g > 1) ans.pb('B');
		if(b > 1) ans.pb('G');
	}
	if(g == 0){
		ans.pb('G');
		if(b > 1) ans.pb('R');
		if(r > 1) ans.pb('B');
	}

	sort(ans.begin(), ans.end());

	for(int i=0;i<ans.size();i++)
		printf("%c",ans[i]);
	printf("\n");

}