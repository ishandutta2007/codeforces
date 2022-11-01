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
  int n;
  string s;
  cin>>n>>s;
  int a=0,b=0;
  string ans;
  for(int i=0;i<n;++i) {
    if(s[i]=='(') {
      if(a<b) {
        ++a;
        ans.pb('0');
      } else {
        ++b;
        ans.pb('1');
      }
    } else {
      if(a>b) {
        --a;
        ans.pb('0');
      } else {
        --b;
        ans.pb('1');
      }
    }
  }
  cout<<ans<<endl;
}