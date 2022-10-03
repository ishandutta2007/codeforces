#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ld eps=1e-10;
const ll inf=10000000010;
const int mod = 1000 * 1000 * 1000 + 7;
const int MAXN = 110;

int n, k, tmp, s;
int A[MAXN];
char ch;

int main(){
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	for (int i=0; i<n; i++){
		cin>>ch;
		A[i]=(ch-'0');
		s+=A[i];
	}
	if (!s){
		cout<<"YES"<<endl;
		return 0;
	}
	for (int x=1; x<s/2+1; x++){
		if (s%x || x==s) continue ;
		tmp=0;
		bool flag=false;
		for (int i=0; i<n; i++){
			tmp+=A[i];
			if (tmp>x){
				flag=true;
				break;
			}
			if (tmp==x) tmp=0;
		}
		if (flag) continue ;
		cout<<"YES"<<endl;
		return 0;
	}
	cout<<"NO"<<endl;
	
	return 0;
}