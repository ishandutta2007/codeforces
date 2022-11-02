#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <queue>
#include <memory.h>
#include <stack>

using namespace std;

#define pb push_back
#define mp make_pair
#define fir first
#define fi first
#define sec second
#define int64 long long       
#define ld long double

const int inf=2000000000;

int n,m,k;
int a[2000];

int main(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	scanf("%d %d %d",&n,&m,&k);
	for (int i=0;i<m;++i)
		a[i]=inf;
	int r,c;
	for (int i=0;i<n;++i){
		scanf("%d %d",&r,&c);
		--r;
		a[r]=min(a[r],c);
	}
	int ans=0;
	for (int i=0;i<m;++i){
		if (a[i]<=k){
			ans+=a[i];
			k-=a[i];
		}
		else {
			ans+=k;
			break;
		}
	}
	cout<<ans<<endl;
	return 0;
}