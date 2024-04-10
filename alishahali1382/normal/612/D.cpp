#include <iostream>
#include <bits/stdc++.h>

using namespace std;

long long n, k, l, r, tmp;
long long A[2000 * 1000 + 10];
int out[1000 * 1000 + 10][2];

int main(){
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	scanf("%lld %lld", &n, &k);
	A[2*n]=10000000001;
	
	for (int i=0; i<n; i++){
		scanf("%lld %lld", &l, &r);
		A[2*i]=2*l;
		A[2*i+1]=2*r+1;
	}
	sort(A, A+2*n+1);
	tmp=0;
	int ans=0;
	for (int i=0; i<=2*n; i++){
		//cout<<A[i]<<' ';
		if (A[i]%2){
			if (tmp==k){
				out[ans++][1]=((A[i]-1)/2);
			}
			tmp--;
		}
		else{
			if (tmp==k-1){
				out[ans][0]=(A[i]/2);
			}
			tmp++;
		}
	}
	//cout<<endl;
	cout<<ans<<endl;
	for (int i=0; i<ans; i++){
		printf("%d %d \n", out[i][0], out[i][1]);
	}
	return 0;
}