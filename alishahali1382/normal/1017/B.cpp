#include <iostream>
#include <bits/stdc++.h>

using namespace std;

long long n, ans;
char A[100000 + 10];
char B[100000 + 10];
long long cnt[4];

int main(){
	//ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	cin>>n;
	for (int i=0; i<n; i++) cin>>A[i];
	for (int i=0; i<n; i++) cin>>B[i];
	for (int i=0; i<n; i++){
		cnt[(A[i]=='1')*2+(B[i]=='1')]++;
	}
	ans=cnt[3]*cnt[0]+cnt[2]*cnt[1]+cnt[2]*cnt[0];
	cout<<ans<<endl;
	
	return 0;
}