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
#define maxn 500500
#define mod 1000000007

using namespace std;

string name[3] = {"","Stannis","Daenerys"};

int v[2];

main(){

		int n,k;
		cin >> n >> k;
		int i=0, p=0;
		for(int j=0;j<n;j++){
			int a;
			scanf("%d",&a);
			if(a%2 == 0) p++;
			else i++;
		}

		int rounds = n-k;
		int last = (rounds % 2) ? 1 : 2;

		if(n == k){
			if(i%2)
				cout << name[1] << endl;
			else
				cout << name[2] << endl;
			return 0;
		}

		if(i > rounds && p > rounds){
			cout << name[last] << endl;
			return 0;
		}

		int outro = 3 - last;
		
		int joga = 0;

		//tira par
		int tirai = ((rounds-p)%2+2)%2;
		int finalP = ((i-tirai)%2+2)%2;

		int finalI = 0;

		debug("last %d outro %d joga %d\n",last,outro,joga);
		debug("finalI %d finalP %d\n",finalI,finalP);

		if(finalP == outro%2 && finalI == outro%2){
			if(i < p) joga = 1;
			else joga = 0;
		}

		else if(finalP == outro%2) joga = 0;
		else if(finalI == outro%2) joga = 1;

		int turn = 1;

		if(finalP != outro%2 && finalI != outro%2){
			if(i < p) joga = 1;
			else joga = 0;
		}

		v[0] = p;
		v[1] = i;

		debug("last %d outro %d joga %d\n",last,outro,joga);

		while(n > k){

			if(n == k+1){
				if(v[1] && v[0]){
					cout << name[last] << endl;
					return 0;
				}
			}
		
			n--;
			if(turn == outro){
				if(v[joga]) v[joga]--;
				else v[1^joga]--;
			}
			else {
				if(v[1^joga]) v[1^joga]--;
				else v[joga]--;
			}
			turn = 3-turn;
			debug("-> %d %d\n",v[0],v[1]);
		}

		debug("!");
		if((v[1])%2 == 0)
			cout << name[2] << endl;
		else
			cout << name[1] << endl;

}