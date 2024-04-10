#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
#define SZ(x) (int)(x).size()
typedef long long ll;
typedef pair<int,int> pii;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;
	string s;
	cin >> s;
	vector<char> ans(n);
	ans[(n-1)/2]=s[0];
	int l=(n-1)/2-1,r=(n-1)/2+1;
	if(n%2==1) {
		for(int i=1; i<n; i++)
			if(i%2==1)ans[l]=s[i],l--;
			else ans[r]=s[i],r++;
	} else {
		for(int i=1; i<n; i++)
			if(i%2==0)ans[l]=s[i],l--;
			else ans[r]=s[i],r++;
	}
	for(int i=0; i<n; i++)cout<<ans[i];
}