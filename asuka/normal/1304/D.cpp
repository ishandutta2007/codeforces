#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<bitset>
#include<queue>
#include<cstdlib>
#include<cmath>
#include<set>
#include<list>
#include<deque>
#include<map>
#define ll long long
#define N 300005
using namespace std;
int t,n,ans[N];
char s[N];
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		scanf("%s",s);
		ans[0] = n;
		for(int i = 1;i < n;){
			while(i < n&&s[i-1]=='>'){
				ans[i] = n-i;++i;
			}
			int temp = i,sum = 0;
			while(temp < n&&s[temp-1]=='<'){
				temp++;sum++;
			}
			ans[i-1] = ans[i-1]-sum;
			while(i < n&&s[i-1]=='<'){
				ans[i] = ans[i-1]+1;++i;
			}
		}
		for(int i = 0;i < n;++i) printf("%d ",ans[i]);
		printf("\n"); 
		ans[n] = n;
		for(int i = n-1;i > 0;){
			while(i > 0&&s[i-1]=='<'){
				ans[i] = i;--i;
			}
			int temp = i,sum = 0;
			while(temp > 0&&s[temp-1]=='>'){
				temp--;sum++;
			}
			ans[i+1] = ans[i+1]-sum;
			while(i > 0&&s[i-1]=='>'){
				ans[i] = ans[i+1]+1;--i;
			}
		}
		for(int i = 1;i <= n;++i) printf("%d ",ans[i]);
		printf("\n"); 
	}
    return 0;
}