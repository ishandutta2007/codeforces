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

int n, a[N], l[N], r[N], was[N];
int main(){
    cin >> n;
    for(int i = 0; i < n; i++)
    	cin >> l[i];
	for(int i = 0; i < n; i++)
    	cin >> r[i];
	for(int i = 0; i < n; i++){
		vector< int > v;
		for(int j = 0; j < n; j++)
			if(!was[j] && l[j] == 0 && r[j] == 0){
				a[j] = n - i; 
				was[j] = 1;
				v.pb(j);
			}
		for(auto it : v)
			for(int j = 0; j < n; j++)
				if(!was[j]){
					if(j > it)
						l[j]--;
					else
						r[j]--;
				}
		for(int j = 0; j < n; j++)
			if(l[j] < 0 || r[j] < 0)
				cout << "NO", exit(0);
	}
	for(int i = 0 ; i < n; i++)
		if(!was[i])
			cout << "NO", exit(0);
	
	cout << "YES" << endl;
	for(int i = 0 ; i < n; i++)
		cout << a[i] << " ";


	return 0;
}