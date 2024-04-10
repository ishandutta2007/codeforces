#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN=1000 * 1000 + 10;

int n, mx;
int A[MAXN];
int B[MAXN];
int prv[MAXN];
int nxt[MAXN];
int cnt[MAXN];

ll ans;

int main(){
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	scanf("%d", &n);
	for (int i=0; i<n; i++){
		scanf("%d", &A[i]);
		if (A[mx]<A[i]) mx=i;
	}
	for (int i=0; i<n; i++) B[i]=A[(i+mx)%n];
	for (int i=0; i<n; i++){
		prv[i]=i-1;
		nxt[i]=i+1;
	}
	for (int i=1; i<n; i++){
		while (prv[i] && B[i]>=B[prv[i]]) prv[i]=prv[prv[i]];
	}
	
	for (int i=n-1; i>=0; i--){
		while (nxt[i]<n && B[i]>B[nxt[i]]) nxt[i]=nxt[nxt[i]];
		if (nxt[i]<n && B[i]==B[nxt[i]]){
			cnt[i]=cnt[nxt[i]]+1;
			nxt[i]=nxt[nxt[i]];
		}
	}
	for (int i=0; i<n; i++){
		ans+=cnt[i];
		if (B[i]!=B[0]){
			ans+=2;
			if (!prv[i] && nxt[i]==n) ans--;
		}
	}
	printf("%lld\n", ans);
	return 0;
}