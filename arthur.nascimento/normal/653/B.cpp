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
#define maxn 500500
#define mod 1000000007

typedef long long ll;
using namespace std;

int foi[30000000];
int ans = 0;
int n,k;

int v[10];

char str[10];

char a[50];
char b[50];
char c[50];

void brute(int pos){
	if(pos == n-1){

		int ok = 1;
		str[0] = a[v[0]];
		str[1] = b[v[0]];
		for(int i=1;i<n-1;i++){
			if(a[v[i]] != c[v[i-1]]) ok = 0;
			str[i+1] = b[v[i]];
		}
		if(ok == 0 || c[v[n-2]] != 'a')
			return;
		int hash = 0;
		for(int i=0;i<n;i++){
			hash *= 6;
			hash += str[i]-'a';
		}
		for(int i=0;i<n;i++)
			debug("%c",str[i]);
		debug("\n");
		if(!(foi[hash/32]&(1<<(hash%32)))) ans++;
		foi[hash/32] |= (1<<(hash%32));
		return;
	}

	for(int i=0;i<k;i++){
		v[pos] = i;
		brute(pos+1);
	}

}

main(){

	scanf("%d%d",&n,&k);

	for(int i=0;i<k;i++)
		scanf(" %c %c %c",a+i,b+i,c+i);

	brute(0);

	cout << ans << endl;

}