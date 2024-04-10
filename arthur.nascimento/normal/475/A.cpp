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
#define pff pair<long double,long double>
#define eps 1e-6
 
#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

#define pb push_back
#define mod 1000000007
#define maxn 100100

using namespace std;

char a[] = "+------------------------+\n";
char b[] = "|#.#.#.#.#.#.#.#.#.#.#.|D|)\n";
char c[] = "|#.#.#.#.#.#.#.#.#.#.#.|.|\n";
char d[] = "|#.......................|\n";
char e[] = "|#.#.#.#.#.#.#.#.#.#.#.|.|)\n";
char f[] = "+------------------------+\n";

main(){

		int n;
		scanf("%d",&n);

		int t = strlen(a);

		for(int i=0;i<t;i++){

			if(b[i] == '#' && n){
				n--; b[i] = 'O';}
			if(c[i] == '#' && n){
				n--; c[i] = 'O';}
			if(d[i] == '#' && n){
				n--; d[i] = 'O';}
			if(e[i] == '#' && n){
				n--; e[i] = 'O';}

		}

		cout << a << b << c << d << e << f << endl;

}