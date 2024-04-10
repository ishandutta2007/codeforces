#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = (int)2e5 + 123, inf = 1e9, mod = 1e9 + 7;
const ll INF = 1e18;
          
string s, t;
int n, cnt[4], a[N], b[N];
vector< int > ans;
void rev(int i){
	if(i <= 0)
		return;
	ans.pb(i << 1);
	reverse(a, a + i);
	for(int j = 0; j < i; j++)
		if(a[j] == 1 || a[j] == 2)
			a[j] ^= 3;
}
void solve(){
	cin >> s >> t;
	n = s.size() / 2;                     
	cnt[0] = cnt[1] = cnt[2] = cnt[3] = 0;
	for(int i = 0; i < n; i++){            
		a[i] = ((s[i << 1] - '0') << 1) + s[i << 1 | 1] - '0';
		b[i] = ((t[i << 1] - '0') << 1) + t[i << 1 | 1] - '0';
		cnt[a[i]]++;
		cnt[b[i]]--;
	}
	if(cnt[0] != 0 || cnt[3] != 0){
		cout << -1 << endl;
		return;
	}
	ans.clear();
	int A = -1, B = -1;
	{
		int X = 0, Y = 0;
		for(int j = 0; j < n; j++){
			if(b[j] == 1)
				X++;
			if(b[j] == 2)
				Y++;
		}
		for(int i = 0; i <= n; i++){
			int x = 0, y = 0;
			for(int j = 0; j < i; j++){
				if(a[j] == 2)
					x++;
				if(a[j] == 1)
					y++;
			}
			for(int j = i; j < n; j++){
				if(a[j] == 1)
					x++;
				if(a[j] == 2)
					y++;
			}
			if(x == Y && y == X)
				A = i;
		}    
	}
	{
		int X = 0, Y = 0;
		for(int j = 0; j < n; j++){
			if(a[j] == 1)
				X++;
			if(a[j] == 2)
				Y++;
		}
		for(int i = 0; i <= n; i++){
			int x = 0, y = 0;
			for(int j = 0; j < i; j++){
				if(b[j] == 2)
					x++;
				if(b[j] == 1)
					y++;
			}
			for(int j = i; j < n; j++){
				if(b[j] == 1)
					x++;
				if(b[j] == 2)
					y++;
			}
			if(x == Y && y == X)
				B = i;
		}    
	}
	if(A != -1)
		rev(A);
	else{
		reverse(b, b + B);
		for(int j = 0; j < B; j++)
			if(b[j] == 1 || b[j] == 2)
				b[j] ^= 3;
	}
	for(int i = 0; i < n; i++){
		int pos = -1;                        
		int need = b[n - 1 - i];
		if(need == 1 || need == 2)
			need ^= 3;
		for(int j = i; j < n; j++)
			if(need == a[j])
				pos = j;
		assert(pos != -1);
		rev(pos);
		rev(pos + 1); 
	}
	if(A == -1)
		ans.pb(B * 2);
	cout << ans.size() << endl;
	for(auto it : ans)
		cout << it << " ";
	cout << endl;
}
int main()
{                   
	int t;
	cin >> t;
	while(t--)
		solve();
	return 0;
}