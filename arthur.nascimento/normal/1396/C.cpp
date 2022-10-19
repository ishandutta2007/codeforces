#include <bits/stdc++.h>

#define maxn 1001000

#define maxK 4100

#define ll long long

#define pb push_back

#define pii pair<int,int>

#define mod 1000000007 

#define debug(args...) //fprintf(stderr,args)

using namespace std;


ll v[maxn];

ll dp[2][maxn];

int n;
ll r1,r2,r3,d;

ll all(int id){
	return v[id] * r1 + r3;
}

ll all_but_boss(int id){
	return min(r2, v[id] * r1 + r1);
}

ll boss(){
	return r1;
}

ll get(int f,int pos){

	ll &ans = dp[f][pos];
	if(ans+1) return ans;

	debug("get %d %d\n",f,pos);

	if(pos == n){
		if(f) return d + boss();
		else return -d;
	}

	ll a1 = all(pos) + d + get(0,pos+1);
	if(f) a1 = all(pos) + d + boss() + d + d + get(0,pos+1);
	if(f && pos == n-1) a1 = all(pos) + d + boss();

	ll a2 = all_but_boss(pos) + d + get(1,pos+1);
	if(f) a2 = all_but_boss(pos) + d + boss() + d + boss() + d + get(0,pos+1);

	return ans = min(a1,a2);

}


main(){

	scanf("%d%lld%lld%lld%lld",&n,&r1,&r2,&r3,&d);

	for(int i=0;i<n;i++)
		scanf("%lld",v+i);

	memset(dp,-1,sizeof(dp));

	printf("%lld\n",get(0,0));

}