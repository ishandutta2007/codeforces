#include <bits/stdc++.h>
#pragma GCC optimize ("O2")
#pragma GCC optimize ("unroll-loops")
//#pragma GCC optimize("no-stack-protector,fast-math")

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef pair<ll, ll> pll;
#define debug(x) cerr<<#x<<'='<<(x)<<endl;
#define debugp(x) cerr<<#x<<"= {"<<(x.first)<<", "<<(x.second)<<"}"<<endl;
#define debug2(x, y) cerr<<"{"<<#x<<", "<<#y<<"} = {"<<(x)<<", "<<(y)<<"}"<<endl;
#define debugv(v) cerr<<#v<<" : ";for (auto x:v) cerr<<x<<' ';cerr<<endl;
#define all(x) x.begin(), x.end()
#define pb push_back
#define kill(x) return cout<<x<<'\n', 0;

const ld eps=1e-7;
const int inf=1000000010;
const ll INF=10000000000000010LL;
const int mod = 1000000007;
const int MAXN = 100010, LOG=20;

struct T{
	int cnt[26], tot;
	T(){
		memset(cnt, 0, sizeof(cnt));
		tot=0;
	}
	
};
bool operator <(T x, T y){
	if (y.tot!=x.tot) return y.tot<x.tot;
	for (int i=0; i<26; i++) if (y.cnt[i]!=x.cnt[i]) return y.cnt[i]<x.cnt[i];
	return 0;
}

struct CMP{
	bool operator ()(T u, T v){
		return u<v;
	}
};

int n, m, k, u, v, x, y, t, a, b, ans;
multiset<T> mst;
vector<T> vec;

T bui(string s){
	T ret;
	ret.tot=s.size();
	for(int i=0;i<s.size();i++){
		ret.cnt[s[i]-'a']++;
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	string s;
	if (n==1){
		cout<<"? 1 1"<<endl;
		cin>>s;
		cout<<"! "<<s<<endl;
		return 0;
	}
	cout<<"? 1 "<<n<<endl;
	for(int i=1;i<=n*(n+1)/2;i++){
		cin>>s;
		mst.insert(bui(s));	
	}
	T shit;
	cout<<"? 2 "<<n<<endl;
	for(int i=1;i<=n*(n-1)/2;i++){
		cin>>s;
		T tmp=bui(s);
		mst.erase(mst.find(tmp));
	}
	for (auto tmp:mst) vec.pb(tmp);
	sort(all(vec));
	reverse(all(vec));
	T fuck;
	memset(fuck.cnt, 0, sizeof(fuck.cnt));
	fuck.tot=0;
	cout<<"! ";
	for (auto tmp:vec){
		char ch='a';
		for (int i=0; i<26; i++) if (fuck.cnt[i]!=tmp.cnt[i]) ch='a'+i;
		cout<<ch;
		fuck=tmp;
	}
	cout<<endl;
	
	return 0;
}