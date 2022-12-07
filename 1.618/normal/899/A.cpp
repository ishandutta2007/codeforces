#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<fstream>
#include<cmath>
#include<stack>
#include<cstdlib>
#include<sstream>
#include<ctime>
using namespace std;
int n,a[200005],cnt[3];
int ans;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		cnt[a[i]]++;
	}
	ans+=min(cnt[1],cnt[2]);
	cnt[1]=max(0,cnt[1]-cnt[2]);
	printf("%d\n",ans+cnt[1]/3);
	return 0;
}