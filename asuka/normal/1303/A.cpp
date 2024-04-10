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
#define N 105
using namespace std;
int t;
char s[N]; 
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%s",s);
		int l = strlen(s),lst = -1,ans = 0;
		for(int i = 0;i < l;++i){
			if(s[i]=='0') continue;
			if(lst == -1||lst == i-1){
				lst = i;
				continue;
			}
			ans += i-lst-1;
			lst = i;
		}
		printf("%d\n",ans);
	}
    return 0;
}