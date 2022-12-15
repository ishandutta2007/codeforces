
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <iostream>
#include <cstring>
#include <map>

#define fi first
#define se second
#define sz(x) ((int)x.size())

using namespace std;

int n=6,arr[6];
int main() {
	for(int i=0;i<n;i++) 
		scanf("%d",arr+i);

	int s=arr[0],i=1,j=5,f=1,ans=0;
	while(true) {
		ans += s*2+f;

		s+=f; arr[i]--;arr[j]--;
		if(!arr[i]) i++,f--;
		if(!arr[j]) j--,f--;
		if(i==j)break;
	}
	printf("%d\n",ans);

	return 0;
}