#include <bits/stdc++.h>

using namespace std;
typedef long long lli;

char str[110];
int n;

int main() {
	scanf("%d%s",&n,str);

	int ans=0;
	for(int i=0;i<n;) {
		if(str[i]!='x') {
			i++;
			continue;
		}
		
		int j=i;
		for(;j<n && str[j]=='x';j++);

		ans += max(0,j-i-2);
		i=j;
	}
	printf("%d\n",ans);
	return 0;
}