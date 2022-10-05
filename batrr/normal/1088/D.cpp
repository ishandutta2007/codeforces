#include <bits/stdc++.h>

#define f first 
#define s second 
#define pb push_back               
#define mp make_pair 

using namespace std;                    

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = (int)1e5 + 123, inf = 1e9;
const ll INF = 1e18;

int c, ans[2][50];
int ask(int c, int d){
	//int a, b;
	//a = 4545;
	//b = 4785;
	cout << "?" << " " << c << " " << d << endl;
	int res;    
	/*
	if((a ^ c) > (b ^ d))
		res = 1;
	if((a ^ c) == (b ^ d))
		res = 0;
	if((a ^ c) < (b ^ d))
		res = -1;
	*/
	cin >> res;
	return res;
}
void solve(int x){// a ^ x = b
	int a, b;
	a = b = 0;
	for(int i = 0; i < 30; i++){
		if(ans[0][i] == ans[1][i]){
			int res = ask(0, c ^ (1 << i));
			if(res == 1){      
				a |= (1 << i);
				b |= (1 << i);	
			}
		}else{                    
			a |= (ans[0][i] << i);
			b |= (ans[1][i] << i);
		}
	}
	cout << "! " << a << " " << b << endl;
	exit(0);
}
int main(){
	int cur = ask(0, 0);
	if(cur == 0){
	    solve(0);
		return 0;
	}
	for(int i = 29; i >= 0; i--){
		int val = (1 << i);
		int res = ask(val, val ^ c);
		if(res == cur)
			continue;
		c ^= (1 << i);
		if(res == -1){
			ans[0][i] = 1;
			ans[1][i] = 0;
		}else{
			ans[0][i] = 0;
			ans[1][i] = 1;
		}
		cur = ask(0, c);	
		if(cur == 0)
			solve(c);
	}
	solve(c);
	return 0;
}