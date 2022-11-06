#include <cstdio>
#include <vector>
#include <random>
#include <set>
#include <map> 
#include <algorithm>
using namespace std;
#define rep(i,a,b) for(int i = int(a); i < (b); ++i)

int main(){
	int n;
	scanf("%d",&n);
	vector<int> stad(n);
	rep(i,0,n)
		scanf("%d",&stad[i]);
	printf("%d %d\n",stad[1]-stad[0],stad[n-1]-stad[0]);
	rep(i,1,n-1)
		printf("%d %d\n",min(stad[i+1]-stad[i],stad[i]-stad[i-1]),max(stad[n-1]-stad[i],stad[i]-stad[0]));
	printf("%d %d\n",stad[n-1]-stad[n-2],stad[n-1]-stad[0]);
}