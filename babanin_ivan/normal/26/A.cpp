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

int n;
bool prime[4000];

int main(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	scanf("%d",&n);
	for (int i=1;i<=n;++i)
		prime[i]=true;
	prime[0]=prime[1]=false;
	for (int i=2;i<=n;++i)
		if (prime[i])
			for (int j=i+i;j<=n;j+=i)
				prime[j]=false;
	int k,ans;
	k=ans=0;
	for (int i=1;i<=n;++i){
		k=0;
		for (int j=2;j<=i;++j)
			if (i%j==0 && prime[j])
				++k;
		if (k==2)
			++ans;
	}
	cout<<ans<<endl;
	return 0;
}