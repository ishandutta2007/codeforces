#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int MAXN=200 * 1000 + 10;

int n, q, l, r;
ll ans;

ll Q[2*MAXN];
ll A[MAXN];
ll B[MAXN];

int main(){
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>q;
	for (int i=0; i<n; i++) cin>>A[i];
	for (int i=0; i<q; i++){
		cin>>l>>r;
		l--;
		r--;
		Q[2*i]=2*l;
		Q[2*i+1]=2*r+1;
	}
	sort(A, A+n);
	sort(Q, Q+2*q);
	
	int j=0, t=0;
	for (int i=0; i<n; i++){
		while (Q[j]<=2*i && j<2*q){
			if (Q[j]%2) t--;
			else t++;
			j++;
		}
		B[i]=t;
		while (Q[j]<=2*i+1 && j<2*q){
			if (Q[j]%2) t--;
			else t++;
			j++;
		}
	}
	sort(B, B+n);
	for (int i=0; i<n; i++){
		ans+=A[i]*B[i];
		//cout<<B[i]<<' ';
	}
	
	cout<<ans<<endl;
	return 0;
}