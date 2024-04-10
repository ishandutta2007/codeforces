#include<bits/stdc++.h>

using namespace std;

typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<vvd> vvvd;
typedef vector<string> vs;
typedef vector<char> vc;
typedef vector<vc> vvc;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;
typedef vector<long long> vll;
typedef vector<vll> vvll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<bool> vb;
typedef vector<vb> vvb;

#define pb push_back
#define ctz __builtin_ctz
#define db(x) cerr << #x << "=" << x << endl
#define db2(x, y) cerr << #x << "=" << x << "," << #y << "=" << y << endl
#define db3(x, y, z) cerr << #x << "=" << x << "," << #y << "=" << y << "," << #z << "=" << z << endl

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc,n;
    string s;
    cin>>tc;
   	while(tc--) {
   		cin>>n>>s;
   		bool can=0;
   		for(int i=n-11;i>=0;--i) {
   			if(s[i]=='8') {
   				can=1;break;
   			}
   		}
   		if(can) cout<<"YES"<<endl;
   		else cout<<"NO"<<endl;

   	}

}