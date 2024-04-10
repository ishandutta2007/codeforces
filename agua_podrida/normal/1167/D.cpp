#include<bits/stdc++.h>

using namespace std;

#define F1(i,n) for(int i = 1; i <= n; i++)
#define F0(i,n) for(long long i = 0; i < n; i++)
#define F first
#define S second
#define INF 1000000000
#define mod 1000000007
#define mp make_pair
#define pb push_back

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pi;

int main(){
	int n;
	cin>>n;
	string s;
	cin>>s;
	vi res(n);
	int contador = 0;
	vi lifo;
	F0(i, n){
		if(s[i] == '('){
			contador++;
			lifo.pb(i);
		}
		else{
			contador--;
			int abre = lifo.back();
			lifo.pop_back();
			if(contador % 2  == 0){
				res[i] = 1;
				res[abre] = 1;
			}
		}
	}
	F0(i,n) cout<<res[i];
	cout<<'\n';
}