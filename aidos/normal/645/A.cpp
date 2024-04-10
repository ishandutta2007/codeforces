#include <bits/stdc++.h>

using namespace std;


#define pb push_back
#define ll long long
#define mp make_pair
#define f first
#define s second
#define pii pair < int, int >
#define pll pair < ll, ll >
#define all(s) s.begin(), s.end()
#define sz(s) (int) s.size()
#define vi vector < int >

const int inf = (int)1e9;
const int mod = (int) 1e9 + 7;


string get(){
	string a, b;
	cin >> a>>b;
	a += b[1];
	a += b[0];
	b = "";
	for(int i = 0; i < a.size(); i++)
		if(a[i] != 'X') b += a[i];
	return b;
}

int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    string s1, s2;
    s1 = get();
    s2 = get();
    s1 = s1 + s1 + s1+s1;
    for(int i = 0; i<6; i++){
    	int ok = 1;
    	for(int j = 0; j < s2.size(); j++){
    		if(s1[i+j] == s2[j]) continue;
    		ok = 0; 
    	}
    	if(ok){
    		cout <<"YES\n";
    		return 0;
    	}
    }
    cout << "NO\n";


    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}