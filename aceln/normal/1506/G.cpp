#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
const int maxn=1e6+7;
const int inf=2e9;
const ll inff=1e18;
const ll mod=1e9+7;
#define pii pair<int,int>
#define mkp make_pair
#define F first
#define S second
#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()
//#define int ll

vector<int> v[30];
int have[30],mx[30];

int32_t main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int t; cin>>t;
	while (t--) {
		string s; cin>>s;
		memset(have,0,sizeof(have));
		memset(mx,0,sizeof(mx));
		for (int i=0;i<26;i++) v[i].clear();

		set<int> ss;
		for (int i=0;i<sz(s);i++) {
			v[s[i]-'a'].pb(i);
			have[s[i]-'a']=1;
			mx[s[i]-'a']=max(i,mx[s[i]-'a']);
		}

		int cnt=0;
		for (int i=0;i<26;i++) {
			if (have[i]) {
				cnt++;
				ss.insert(mx[i]);
			}
		}

		int place=-1;
		for (int i=0;i<cnt;i++) {
			for (int j=25;j>=0;j--) {
				if (!have[j]) continue;
				int tmpplace=(*upper_bound(all(v[j]),place));
				if (tmpplace<=(*ss.begin())) {
					have[j]=0;
					ss.erase(mx[j]);
					place=tmpplace;

					cout<<(char)(j+'a');
					break;
				}
			}
		}
		cout<<'\n';
	}
}