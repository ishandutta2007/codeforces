#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ld eps=1e-10;
const ll inf=1000000010;
const int mod = 1000 * 1000 * 1000 + 7;
const int MAXN = 1010;

int n, m, tmp;
int A[8], B[8];

int main(){
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%d", &n);
	for (int i=0; i<n; i++){
		scanf("%d", &tmp);
		A[tmp]++;
	}
	for (int i=1; i<=7; i++) B[i]=A[i];
	
	if (B[3]>B[1] || B[3]>B[6] || A[5] || A[7]){
		cout<<-1<<endl;
		return 0;
	}
	B[1]-=B[3];
	B[6]-=B[3];
	B[3]=0;
	
	//  B[3]=B[5]=B[7]=0
	
	if (B[6]>B[1] || B[6]>B[2]){
		cout<<-1<<endl;
		return 0;
	}
	B[1]-=B[6];
	B[2]-=B[6];
	B[6]=0;
	if (B[1]==B[2] && B[2]==B[4]){
		for (int i=0; i<A[4]; i++) cout<<"1 2 4"<<endl;
		for (int i=0; i<A[6]-A[3]; i++) cout<<"1 2 6"<<endl;
		for (int i=0; i<A[3]; i++) cout<<"1 3 6"<<endl;
		return 0;
	}
	cout<<-1<<endl;
	
	return 0;
}