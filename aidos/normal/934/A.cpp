// Dracarys!
#include <bits/stdc++.h>

using namespace std;
#define sz(a) (int)a.size()
#define all(x) (x).begin(),(x).end()
#define vi vector <int>
#define pb push_back
#define mp make_pair
#define ll long long        
#define sc scanf
#define pf printf    
#define f first
#define s second 
#define y1 dadssda
#define int ll
       
const int inf = (int)1e9;
const int mod = inf + 7;
const double pi = acos(-1.0);
const double eps = 1e-9;

int gcd(int a,int b) { return b?gcd(b,a%b):a;} 

// /////////////////////////////////////////////////////////////////////
 


int n, m;
vector<int> v, c;
main(){
	//freopen("in.in", "r", stdin);
    //freopen("out.out", "w", stdout);

    cin >> n >> m;
    for(int i = 0, x; i < n; ++i){
    	cin >> x;
    	v.pb(x);
    }
    for(int i = 0, x; i < m; ++i){
    	 cin >> x;
    	 c.pb(x);
    }
    sort(all(v));
    sort(all(c));
    int mini = (int)2e18;
    for(int i = 0; i < sz(v); ++i){
    	int res = i;
    	int mie = -2e18;
    	for(int j = 0; j < sz(c); ++j)
    		for(int a = 0; a < sz(v); ++a){
    			if(a == res) continue;
    			mie = max(mie, c[j] * v[a]);
    		}
    	mini = min(mie, mini);
    }
    cout << mini << endl;
    return 0;
}