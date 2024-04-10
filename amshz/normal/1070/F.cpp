//in the name of god
//if you read this code please search about imam hussain
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pb push_back
#define endl "\n"
#define X first
#define Y second
#define pii pair<int,int>
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define read freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout)

const int maxn=1e6+5;
const int mod=1e9+7;
const int inf=1e9;
const int del=728729;

ll poww(ll a, ll b, ll md) {return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));}

ll n;
ll ans;
ll cnt;
vector<int> dob ;
vector<int> chap ;
vector<int> ras ;
string s ;
ll x ;
int main() {
    migmig;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> s >> x ;
        if (s == "11"){
        	ans += x ;
			cnt++;
		} 
        else if (s == "00"){
        	dob.push_back(x);
		} 
        else if (s == "01"){
        	ras.push_back(x);
		} 
        else if (s == "10"){
        	chap.push_back(x);
		} 
    }
    sort(chap.begin(), chap.end());
    sort(ras.begin(), ras.end());
    while (ras.size() and chap.size()) {
        ans += chap.back() + ras.back();
        chap.pop_back();
        ras.pop_back();
    }
    for (auto x: chap){
    	dob.push_back(x);
	} 
    for (auto x: ras){
    	dob.push_back(x);
	} 
    sort(dob.begin(), dob.end());
    while (cnt!=0 and dob.size()){
    	cnt-- ;
		ans += dob.back() ;
		dob.pop_back();
	} 
    cout << ans ;
    return 0;
}