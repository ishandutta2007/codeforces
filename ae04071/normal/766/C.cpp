#include <stdio.h>
#include <cstring>
#include <algorithm>

const int MOD=1e9+7;

int n, arr[26];
char str[1010];

int cache[1010][1010];

int pcnt=0,mlen=0,mpap=98765431;

int DP(int idx, int st, int lim)
{
	if(lim<idx-st+1) return 0;
	if(idx==n-1) {
		if(mlen<idx-st+1)
			mlen=idx-st+1;
		if(mpap>pcnt) mpap=pcnt;

		return 1;
	}

	int &ret=cache[idx][st];
	if(ret!=-1) return ret;

	ret=0;
	int val=DP(idx+1, st, std::min(lim, arr[str[idx+1]-'a']));
	ret+=val;
	ret%=MOD;

	pcnt++;
	val=DP(idx+1, idx+1, arr[str[idx+1]-'a']);	
	pcnt--;
	if(val!=0) {
		if(mlen<idx-st+1) 
			mlen=idx-st+1;
	}
	ret+=val;
	ret%=MOD;

	return ret;
}

int main()
{
	scanf("%d",&n);
	scanf("%s",str);
	for(int i=0;i<26;i++) {
		scanf("%d",arr+i);
	}

	pcnt++;
	memset(cache, -1, sizeof(cache));
	printf("%d\n",DP(0,0,arr[str[0]-'a']));
	printf("%d\n%d\n",mlen,mpap);

	return 0;
}