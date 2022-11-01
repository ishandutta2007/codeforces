#include <bits/stdc++.h>

#define all(a) (a).begin(),(a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int main() {
	ios_base::sync_with_stdio(0);

	vector<int> x(3);
	for(int i = 0; i < 3; i++)
		cin >> x[i];
	sort(all(x));
	cout << (x[1] - x[0]) + (x[2] - x[1]);
}