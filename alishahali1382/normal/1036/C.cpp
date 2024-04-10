#include <bits/stdc++.h>

using namespace std;

typedef signed long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ld eps=1e-10;
const int inf=1000000010;
const int mod = 1000 * 1000 * 1000 + 7;
const int MAXN = 1952600;

ll T, L, R, ans, num, numm;
ll a, b, c, ttt, x;
ll A[MAXN];
ll B[MAXN];
int X[18];

ll f(){
	ll out=0, x=1;
	for (int i=0; i<18; i++){
		out+=X[17-i]*x;
		x*=10;
	}
	return out;
}

int main(){
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	// ----------------------------------------------------------------------
	R=1000000000000000000;
	A[ttt++]=R;
	for (a=1; a<10; a++){
		for (int i=0; i<18; i++){
			//memset(X, 0, sizeof(X));
			X[i]=a;
			A[ttt++]=f();
			for (b=1; b<10; b++){
				for (int j=i+1; j<18; j++){
					X[j]=b;
					A[ttt++]=f();
					for (c=1; c<10; c++){
						for (int k=j+1; k<18; k++){
							X[k]=c;
							A[ttt++]=f();
							X[k]=0;
						}
					}
					X[j]=0;
				}
			}
			X[i]=0;
		}
	}
	/*
	memset(X, 0, sizeof(X));
	X[17]=5;
	X[0]=6;
	cout<<f()<<endl;
	*/
	// ---------------------------------------------------------------------
	sort(A, A+ttt);
	for (int i=0; i<ttt; i++) B[i]=-A[ttt-i-1];
	
	cin>>T;
	for (; T; T--){
		cin>>L>>R;
		ll x=lower_bound(A, A+ttt, L)-A;
		ll y=lower_bound(B, B+ttt, -R)-B;
		if (R<L){
			cout<<0<<endl;
			continue ;
		}
		cout<<ttt-x-y<<endl;
	}

	return 0;
}