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
#define db(x) cerr << #x << "=" << x << endl
#define db2(x, y) cerr << #x << "=" << x << "," << #y << "=" << y << endl
#define db3(x, y, z) cerr << #x << "=" << x << "," << #y << "=" << y << "," << #z << "=" << z << endl
#define all(v) (v).begin(),(v).end()
#define rep(i,n) for(int i=0;i<(n);++i)

// Manacher's algorithm: finds maximal palindrome lengths centered around each
// position in a string (including positions between characters) and returns
// them in left-to-right order of centres. Linear time.
// Ex: "opposes" -> [0, 1, 0, 1, 4, 1, 0, 1, 0, 1, 0, 3, 0, 1, 0]
vector<int> fastLongestPalindromes(const string &str) {
    int i=0,j,d,s,e,lLen,palLen=0;
    vector<int> res;
    while (i < str.length()) {
        if (i > palLen && str[i-palLen-1] == str[i]) {
            palLen += 2; i++; continue;
        }
        res.push_back(palLen);
        s = res.size()-2;
        e = s-palLen;
        bool b = true;
        for (j=s; j>e; j--) {
            d = j-e-1;
            if (res[j] == d) { palLen = d; b = false; break; }
            res.push_back(min(d, res[j]));
        }
        if (b) { palLen = 1; i++; }
    }
    res.push_back(palLen);
    lLen = res.size();
    s = lLen-2;
    e = s-(2*str.length()+1-lLen);
    for (i=s; i>e; i--) { d = i-e-1; res.push_back(min(d, res[i])); }
    return res;
}

string manacher(string &s) {
	if(s.empty()) return s;
	vi v = fastLongestPalindromes(s);
	int n=s.size(),best=0,idx,mid_idx,llen;
	rep(i,2*n+1) {
		if(v[i]<=best) continue;
		mid_idx = i/2;
		llen = v[i]/2;
		if(mid_idx - llen == 0 || mid_idx - llen + v[i] == n) {
			best = v[i];
			idx = i;
		}
	}
	mid_idx = idx/2;
	llen = best/2;
	return s.substr(mid_idx - llen, best);
}


int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc;
    cin>>tc;
    string s;
    while(tc--) {
    	cin>>s;
    	int n=s.size();
    	int mid=n/2,len=0;
    	rep(i,mid) {
    		if(s[i]==s[n-1-i]) ++len;
    		else break;
    	}
    	string pref = s.substr(0,len);
    	string suff = s.substr(n-len,len);
    	s = s.substr(len,n-len-len);
    	pref.append(manacher(s));
    	pref.append(suff);
    	cout<<pref<<endl;
    }


}