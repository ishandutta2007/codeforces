#include <cstdio>
#include <algorithm>
#include <cstring>
#include <ctype.h>
#include <utility>

using namespace std;
typedef pair<int,int> pii;

int n;
pii arr[100];
int chk[101];
char ans[100];

int main() {
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&arr[i].first),arr[i].second = i;
	sort(arr,arr+n);

	int c=0,f=0;
	for(int i=0;i<n;) {
		int j=i;
		for(;j<n && arr[i].first==arr[j].first;j++);
		if(j-i==1) c++;
		else if(j-i>=3) f=1,chk[arr[i].first]=1;
		i=j;
	}

	if(c%2==0) {
		int t=0;
		for(int i=0;i<n;) {
			int j=i;
			for(;j<n && arr[i].first==arr[j].first;j++);
			for(int k=i;k<j;k++) {
				if(j-i==1) ans[arr[k].second] = t,t^=1;
				else ans[arr[k].second] = 0;
			}
			i=j;
		}
	} else {
		if(!f) {
			puts("NO");
			return 0;
		}
		int t=0;
		for(int i=0;i<n;) {
			int j=i;
			for(;j<n && arr[i].first==arr[j].first;j++);
			for(int k=i;k<j;k++) {
				if(j-i==1) ans[arr[k].second] = t,t^=1;
				else ans[arr[k].second] = 0;
			}
			i=j;
		}
		for(int i=0;i<n;i++) if(chk[arr[i].first]) {
			ans[arr[i].second]^=1;
			break;
		}
	}
	puts("YES");
	for(int i=0;i<n;i++) printf("%c",ans[i]+'A');
	
	return 0;
}