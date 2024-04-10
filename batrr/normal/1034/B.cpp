#include <bits/stdc++.h>

#define f first 
#define s second 
#define pb push_back               
#define mp make_pair 

using namespace std;                    

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = (int)1e5 + 123, mod = (int)1e9 + 7, inf = (int)1e9;
int main(){    
	ll n,m;
	cin >> n >> m;
	if(n > m)
		swap(n,m);
	if(n == 1){
		if(m % 6 == 0)
			cout << n*m;          
		else if(m % 6 == 4)
			cout << n*(m/6*6) + 2;
		else if(m % 6 == 5)
			cout << n*(m/6*6) + 4;
		else
			cout << n*(m/6*6) ;
		return 0;
	}
	if(n == 2){
		
		if(m < 3)	
			cout << 0;
		else
		if(m == 3)	
			cout << 4;
		else
		if(m == 7)	
			cout << 12;
		else
		if(m > 3)
			cout << n*m;
		return 0;
	}
    cout << n*m/2*2;
	return 0;
}