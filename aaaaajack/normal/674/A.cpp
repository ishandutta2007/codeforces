#include<bits/stdc++.h>
#define N 5010
using namespace std;
int a[N],ans[N],col[N];
set<int> s[N];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=0;i<n;i++){
		int mx=0,id=0;
		memset(col,0,sizeof(col));
		for(int j=i;j<n;j++){
			if(++col[a[j]]>mx){
				mx=col[a[j]];
				id=a[j];
			}
			else if(col[a[j]]==mx&&a[j]<id) id=a[j];
			ans[id]++;
		}
	}
	for(int i=1;i<=n;i++) printf("%d ",ans[i]);
	puts("");
	return 0;
}