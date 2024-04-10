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


int a[222];

int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif

    string s, t;
    cin >> s;
    for(int i = 0; i < s.size(); i++){
    	a[s[i] - 'a'] ++;
    	t += 'a';
    }
    int cnt = 0, l = 0, r = sz(s) - 1;
    for(int i = 0; i < 26; i++)
    	cnt += a[i] % 2;
    for(int i = 0; i < 26; i++){
    	if(a[i] % 2 == 0){
    	
    	}
    	else {
    		if(cnt > 1){
    			int p = -1;
    			for(int j = 25; j >i; j--){
    				if(a[j] % 2 == 1){
    					p = j;
    					break;
    				}
    			}
    			cnt -= 2;
    			a[p]--;
    			a[i]++;
    		}
    	}
    	while(a[i] > 1){
    		a[i] -= 2;
    		t[l++] = 'a' + i;
    		t[r--] = 'a' + i;
    	}
    }
    for(int i = 0; i < 26; i++)
    	if(a[i] ) t[l++] = 'a' + i;
	cout << t << endl;
    


    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}