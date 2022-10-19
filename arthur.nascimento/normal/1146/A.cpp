#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn 300300
#define bs bitset<maxn>
#define debug
#define pb push_back
#define pii pair<int,int>
char str[maxn];
int main(){
	
	scanf(" %s",str);
	int n = strlen(str);
	int qa = 0, qb = 0;
	for(int i=0;i<n;i++)
	{	if(str[i] == 'a') qa++; else qb++;
	}
	int ans = n;
	while(qb >= qa){
		qb--;
		ans--;
	}
	printf("%d\n",ans);

}