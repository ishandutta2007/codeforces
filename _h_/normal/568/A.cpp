//#include "bits/stdc++.h"
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <map>
#include <bitset>
#include <cstdio>
#include <cassert>
#include <string>
#include <cmath>
#include <utility>
#include <cstring>
#include <stdlib.h>
using namespace std;
#define rep(i,a,b) for(int i = int(a); i < (b); ++i)
#define rrep(i,a,b) for(int i = int(b)-1; i >= int(a); --i)
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,int> pli;

const int mx = 2000000;

int main(){
	int p,q;
	scanf("%d%d",&p,&q);
	int pi[mx], rub[mx];
	bool eras[mx];
	rep(i,2,mx){
		if(!eras[i]){
			for(int j = 2*i; j < mx; j += i)
				eras[j] = 1;
		}
	}
	pi[0] = pi[1] = 0;
	rep(i,2,mx)
		pi[i] = pi[i-1] + !eras[i];
	rub[0] = 0;
	char str[15];
	rep(i,1,mx){
		rub[i] = rub[i-1] + 1;
		int l = sprintf(str,"%d",i);
		rep(j,0,l){
			if(str[j] != str[l-j-1]){
				--rub[i];
				break;
			}
		}
	}
	rrep(i,1,mx){
		if((long long)pi[i]*q <= (long long)p*rub[i]){
			printf("%d\n",i);
			return 0;
		}
	}
	printf("Palindromic tree is better than splay tree\n");
}