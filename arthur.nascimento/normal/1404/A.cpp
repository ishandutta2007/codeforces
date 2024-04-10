#include <bits/stdc++.h>

#define ll long long

#define pb push_back

#define pii pair<int,int>

#define maxn 1001000

#define mod 1000000007

#define debug printf



using namespace std;

int v[maxn];


main(){

	int nt;
	scanf("%d",&nt);

	while(nt--){

		int n,k;
		scanf("%d%d",&n,&k);

		for(int i=0;i<k;i++)
			v[i] = -1;

		int ok = 1;

		for(int i=0;i<n;i++){
			char ch;
			scanf(" %c",&ch);
			if(ch == '?') continue;
			if(ch-'0' + v[i%k] == 1) ok = 0;
			v[i%k] = ch-'0';
		}

		int q0 = 0, q1 = 0;
		for(int i=0;i<k;i++){
			if(v[i] == 0) q0++;
			if(v[i] == 1) q1++;
		}

		if(ok && q0 <= k/2 && q1 <= k/2)
			printf("YES\n");
		else
			printf("NO\n");
	
	}

}