///
///    Hashire sori yo 
///    Kaze no you ni  
///    Tsukimihara wo  
///    Padoru Padoru   
///

#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2")

#include <bits/stdc++.h>
#define Loop(x,l,r) for(ll x = ll(l); x < ll(r); ++x)
#define LoopR(x,l,r) for(ll x = ll(r)-1; x >= ll(l); --x)
typedef long long ll;
typedef std::pair<int,int> pii;
using namespace std;

const int N = 200'256;
bitset<N> A, B, C;
int n, k;

bool padoru(){
	if(A[0] == A[n-1]) return 0;
	Loop(i,0,n-1) if(A[i] == A[i+1]) return 0;
	return 1;
}

int main()
{
	cin >> n >> k;
	Loop(i,0,n) {
		char c;
		cin >> c;
		A[i] = c-'W';
	}
	if(padoru()){
		Loop(i,0,n)
			cout << (A[i]^(k&1)?'B':'W');
		cout << '\n';
		return 0;
	}
	if(k > n/2) k = n/2;
	while(k--)
	{
		B = A<<1; B[0] = A[n-1]; B[n] = 0;
		C = A>>1; C[n-1] = A[0];
		char *a=(char*)&A, *b=(char*)&B, *c=(char*)&C;
		Loop(i,0,N/8)
			a[i] = (a[i]&b[i]) | (a[i]&c[i]) | (b[i]&c[i]);
	}
	Loop(i,0,n)
		cout << (A[i]?'B':'W');
	cout << '\n';
}