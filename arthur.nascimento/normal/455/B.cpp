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
#define mod 1000000007

#define X second.first
#define Y second.second

using namespace std;

struct node {
	int next[30];
	int win,lose;
	void clear(){
		memset(next,-1,sizeof(next));
	}
}

T[100100];
char str[100100];

void dfs(int p){

	int ok = 0;
	int nwin = 0, nlose = 0;

	for(int i=0;i<26;i++) if(T[p].next[i]+1){

		dfs(T[p].next[i]);

		if(T[T[p].next[i]].win == 0) nwin = 1;
		if(T[T[p].next[i]].lose == 0) nlose = 1;

		ok = 1;
	}

	if(ok == 0){
		T[p].win = 0;
		T[p].lose = 1;
		return;
	}

	T[p].win = nwin;
	T[p].lose = nlose;
	
}

main(){

		int n,k;
		scanf("%d%d",&n,&k);

		T[0].clear();
		int qnt = 1;

		for(int i=0;i<n;i++){

			scanf(" %s",str);

			int p = 0, len = strlen(str);

			for(int i=0;i<len;i++){

				if(T[p].next[str[i]-'a'] == -1){
					T[p].next[str[i]-'a'] = qnt;
					T[qnt].clear();
					qnt++;
				}

				p = T[p].next[str[i]-'a'];

			}

		}

		dfs(0);

		if(T[0].win == 0)
			printf("Second\n");
		else{
			if(T[0].lose == 1)
				printf("First\n");
			else{
				if(k%2)
					printf("First\n");
				else
					printf("Second\n");
				}
		}

}