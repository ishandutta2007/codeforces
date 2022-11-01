#include <bits/stdc++.h>
using namespace std;
typedef long long       ll;
typedef long double     ld;
typedef string          str;
#define all(x)			(x).begin(),(x).end()
#define Sort(x)			sort(all(x))
#define A               first
#define B               second
#define sep             ' '
#define endl            '\n'
#define fast_io         ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const ll MAX1 = 2e5+7,
	     MOD = 1e9+7;

ll n, flag, cnt;
pair <pair<ll, ll>, ll> num[MAX1];
vector <ll> ans;

int main(){
	fast_io;
	cin >> n;
	for (int i = 0; i < n; ++i)	cin >> num[i].A.A;
	for (int i = 0; i < n; ++i)	cin >> num[i].A.B, num[i].B = i+1;
	sort(num, num+n);
	for (int i = 0; i < n/2; ++i)	swap(num[i], num[n-i-1]);
	ans.push_back(num[0].B);
	for (int i = 1; i < n; i += 2){
		if (num[i].A.B >= num[i+1].A.B)	ans.push_back(num[i].B);
		else	ans.push_back(num[i+1].B);
	}
	cout << ans.size() << endl;
	for (int i : ans)	cout << i << sep;
    return 0;
}
/*                     now or never                         */