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

int n, p[N], was[N];
int main()
{
	ll q;
	cin >> q;
	while(q--){
		cin >> n;
		for(int i = 1; i <= n; i++)
			cin >> p[i];
		for(int i = 1; i <= n; i++)
			was[i] = 0;
		for(int x = 1; x <= n; x++){
			for(int i = 1; i <= n; i++)
				if(p[i] == x){
					for(int j = i - 1; j >= 1; j--){
						if(was[j] || p[j] < p[j + 1])
							break;
						was[j] = 1;
						swap(p[j], p[j + 1]);
					} 
					break;
				}
		}
		for(int i = 1; i <= n; i++)
			cout << p[i] << " ";
		cout << endl;
	}
	return 0;
}