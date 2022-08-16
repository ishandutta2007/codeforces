#include<bits/stdc++.h>

using namespace std;

#define  GODSPEED       ios:: sync_with_stdio(0);cin.tie(0);cout.tie(0);cout<<fixed;cout<<setprecision(15);
#define  f              first               
#define  s              second
#define  newl           cout<<"\n";
#define  pb             push_back  
#define  mset(a,x)      memset(a,x,sizeof(a))
#define  debv(a)        for(auto it: a)cout<<it<<" ";newl;
#define  deb1(a)        cout<<a<<"\n";
#define  deb2(a,b)      cout<<a<<" "<<b<<"\n";
#define  deb3(a,b,c)    cout<<a<<" "<<b<<" "<<c<<"\n";
#define  deb4(a,b,c,d)  cout<<a<<" "<<b<<" "<<c<<" "<<d<<"\n";
#define  uniq(a)        a.resize(unique(a.begin(), a.end()) - a.begin());
#define  all(a)         a.begin(),a.end()           
 
typedef  long long             ll;
typedef  unsigned long long    ull;
typedef  long double           ld;
typedef  pair<ll,ll>           pll;
typedef  vector<ll>            vll;
typedef  vector<pll>           vpll;

const ll   N     =  1e6+5;
const ll   mod   =  998244353 ;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

ll n, m;
char s[1002][1002];

void solve(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
    	for(int j = 1; j <= n; j++){
    		cin >> s[i][j];
    	}
    }
    if(m&1){
    	deb1("YES")
    	for(int i = 0; i <= m; i++){
    		cout << (i % 2) + 1 << " ";
    	}
    	newl;
    	return;
    }
    for(int i = 1; i <= n; i++){
    	for(int j = i + 1; j <= n; j++){
    		if(s[i][j] == s[j][i]){
    			deb1("YES")
    			for(int k = 0; k <= m; k++){
		    		cout << ((k % 2)? i : j) << " ";
		    	}
		    	newl;
		    	return;
    		}
    	}
    }
    if(m % 4 == 0){
	    for(int i = 1; i <= n; i++){
	    	int a = 0, b = 0;
	    	for(int j = 1; j <= n; j++){
	    		if(s[i][j] == 'a') a = j;
	    		if(s[i][j] == 'b') b = j;
	    	}
			if(a != 0 && b != 0){
				deb1("YES")
				for(int k = 0; k < m / 2; k++){
		    		cout << ((k % 2 == 0)? i : a) << " ";
		    	}
		    	cout << i << " ";
		    	for(int k = 0; k < m / 2; k++){
		    		cout << ((k % 2 == 1)? i : b) << " ";
		    	}
		    	newl;
		    	return;
			}
	    }
	} else {
	    for(int i = 1; i <= n; i++){
	    	int a = 0, b = 0;
	    	for(int j = 1; j <= n; j++){
	    		if(s[j][i] == 'a') a = j;
	    		if(s[i][j] == 'a') b = j;
	    	}
	    	if(a != 0 && b != 0){
	    		deb1("YES")
				for(int k = 0; k <= m; k++){
		    		switch(k % 4){
		    			case 0: cout << a << " "; break;
		    			case 1: cout << i << " "; break;
		    			case 2: cout << b << " "; break;
		    			case 3: cout << i << " "; break;
		    		}
		    	}
		    	newl;
		    	return;
			}
	    }
	}
	deb1("NO")
}

int main(){
    GODSPEED;
    int test = 1;
    cin >> test;
    for(int i = 1; i <= test; i++){
        solve();
    }
}