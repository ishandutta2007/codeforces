#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
#include <functional>
#include <set>
#include <cstring>

#define fi first
#define se second
#define SZ(x) ((int)(x.size()))

using namespace std;
typedef pair<int,int> pii;

char str[101];
int n;

int main() {
	scanf("%s",str);
	n=strlen(str);
	int mx=0;
	for(int i=0;i<n;i++) for(int j=i+1;j<n;j++) {
		int f=1;
		for(int k=0;k<(j-i+1)/2;k++) if(str[i+k]!=str[j-k]) {
			f=0;
			break;
		}
		if(!f) mx=max(mx,j-i+1);
	}
	printf("%d\n",mx);
	return 0;
}