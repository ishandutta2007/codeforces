#include<bits/stdc++.h>

using namespace std;

#define F1(i,n) for(int i = 1; i <= n; i++)
#define F0(i,n) for(long long i = 0; i < n; i++)
#define F first
#define S second
#define INF 1000000000
#define mod 1000000007

typedef long long ll;
typedef vector<ll> vll;

void resolver(){
	int n;
	string s;
	cin>>n>>s;
	if(n < 11)  {
		cout<<"NO\n";
		return;
	}
	int i = n - 11;
	while(i >= 0){
		if(s[i] == '8') {
			cout<<"YES\n";
			return;
		}
		i--;
	}
	cout<<"NO\n";
}

int main(){
	int t;
	cin>>t;
	F1(x,t) resolver();
}