#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long       ll;
 
#define all(x)            (x).begin(),(x).end()
#define Sort(x)            sort(all(x))
#define A               first
#define B               second
#define sep             ' '
#define fast_io         ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define set_random     mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count())
 
const ll MAX1 = 2e5+10,
         MOD = 1e9+7;
 
ll q, n;
string s;
 
int main(){
    fast_io;
    cin >> q;
    while (q--){
    	cin >> s;
    	Sort(s);
    	if (s[0] == s[s.size()-1])	cout << s << '\n';
    	else{
    		for (int i = 0; i < s.size(); ++i)	cout << "01";
    		cout << '\n';
		}
	}
    return 0;
}
/*                 now or never                 */