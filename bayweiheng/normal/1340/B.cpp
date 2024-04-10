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
typedef tuple<int,int,int> iii;

#define pb push_back
#define ctz __builtin_ctz
#define pct __builtin_popcount
#define db(x) cerr << #x << "=" << x << endl
#define db2(x, y) cerr << #x << "=" << x << "," << #y << "=" << y << endl
#define db3(x, y, z) cerr << #x << "=" << x << "," << #y << "=" << y << "," << #z << "=" << z << endl
#define all(v) (v).begin(),(v).end()
#define rep(i,n) for(int i=0;i<(n);++i)

string digits[10]={"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};
int d[10];
int n,k;
vi v;
const int maxn = 2005, maxk = 2005;
int dp[maxn][maxk];
int go[maxn][10]; // usage if v[i] goes to d[j]

int proc(int sub, int sup) {
	if((sub & sup) == sub) {
		return pct(sup-sub);
	}
	return -1;
}

int conv(string &s) {
	int ans=0;
	for(char c:s) {
		ans *= 2;
		ans += (c-'0');
	}
	return ans;
}

int can(int i,int j) {
	//db2(i,j);
	if(i==n) return j==0 ? 1 : 0;
	if(j<0) return 0;
	//db2(i,j);
	if(dp[i][j]!=-1) return dp[i][j];
	int ans=0;
	for(int k=9;k>=0;--k) {
		if(go[i][k]!=-1 && can(i+1, j - go[i][k])) {
			ans=1;
			break;
		}
	}
	return dp[i][j]=ans;
}

string sans;
void solve(int i,int j) {
	if(i==n) return;
	for(int k=9;k>=0;--k) {
		if(go[i][k]!=-1 && can(i+1, j - go[i][k])) {
			sans.pb('0'+k);
			solve(i+1, j - go[i][k]);
			break;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    rep(i,10) {
    	d[i] = conv(digits[i]);
    }
    cin>>n>>k;
    v.resize(n);
    string s;
    rep(i,n) {
    	cin>>s;
    	v[i] = conv(s);
    }
    memset(go,-1,sizeof(go));
    memset(dp,-1,sizeof(dp));
    rep(i,n) {
    	rep(j,10) {
    		go[i][j] = proc(v[i],d[j]);
    		//db3(i,j,go[i][j]);
    	}
    }
    int ans=can(0,k);
    if(ans==0) {
    	cout<<-1<<endl;
    	return 0;
    }
    solve(0,k);
    cout<<sans<<endl;




}