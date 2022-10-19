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
#define maxn 30

using namespace std;


vector<int> L[maxn];
int indg[maxn];

char str[110][110];
int t[110];

main(){

		int n;
		scanf("%d",&n);

		for(int i=0;i<n;i++){
			scanf(" %s",str[i]);
			t[i] = strlen(str[i]);
		}

		int imp = 0;

		for(int i=0;i<n-1;i++){

			int u = 0;
			while(u < t[i] && u < t[i+1] && str[i][u] == str[i+1][u]) u++;
			if(u != t[i] && u == t[i+1]) imp = 1;
			if(u != t[i] && u != t[i+1]) L[str[i][u]-'a'].pb(str[i+1][u]-'a'), indg[str[i+1][u]-'a']++;

		}

		queue<int> Q;
		vector<char> ans;
		for(int i=0;i<26;i++)
			if(indg[i] == 0) Q.push(i);

		while(Q.size()){
			int u = Q.front();
			Q.pop();
			ans.pb(u);
			for(vector<int> :: iterator it = L[u].begin(); it < L[u].end(); it++){
				indg[*it]--;
				if(indg[*it] == 0)
					Q.push(*it);
			}
		}

		if(imp || ans.size() != 26) printf("Impossible\n");
		else {
			for(int i=0;i<26;i++)printf("%c",ans[i]+'a');
			printf("\n");
		}

}