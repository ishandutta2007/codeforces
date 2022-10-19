#include <bits/stdc++.h>

#define ll long long

#define pb push_back

#define pii pair<int,int>

#define maxn 1001000

#define mod 1000000007

#define debug 



using namespace std;

int s[maxn];
int gr[maxn];
int foi[maxn];

int n;

int mir(int x){
	if(x <= n) return x+n;
	return x-n;
}

main(){

	scanf("%d",&n);

	if(n%2 == 0){
		printf("First\n");
		for(int i=1;i<=n;i++) printf("%d ",i);
		for(int i=1;i<=n;i++) printf("%d ",i);
		return 0;
	}

	printf("Second\n");
	fflush(stdout);

	for(int i=1;i<=2*n;i++){
		scanf("%d",gr+i);
		s[gr[i]] += i;
	}

	vector<pii> ans;

	for(int i=1;i<=n;i++)
		if(!foi[i]){
			int u = i;
			do {
				foi[u%n] = foi[n+u%n] = 1;
				ans.pb({gr[u],u});
				u = mir(u);
				u = s[gr[u]] - u;			
			} while(u != i);
		}

	sort(ans.begin(), ans.end());

	ll ss = 0;

	for(pii i : ans)
		ss += i.second;


	for(pii i : ans){
		if(ss%(2*n) == 0)
			printf("%d ",i.second);
		else
			printf("%d ",s[gr[i.second]] - i.second);
	}
	printf("\n");
	fflush(stdout);

}