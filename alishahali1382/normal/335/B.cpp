#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define debug(x) cerr<<#x<<'='<<x<<endl;
#define debugp(x) cerr<<#x<<"= {"<<x.first<<", "<<x.second<<"}"<<endl;
#define all(x) x.begin(), x.end()
#define pb push_back

const ld eps=1e-7;
const int inf=1000000010;
const int mod = 1000000007;
const int MAXN = 2600;

int n, a, b, x, y, t;
int dp[MAXN][MAXN];
pii upd[MAXN][MAXN];
string s;
vector<int> vec[26];

int f(int l, int r){
	if (dp[l][r]!=-1) return dp[l][r];
	if (r<l) return 0;
	upd[l][r]={l, l};
	if (l==r) return dp[l][l]=1;
	if (l+1==r){
		if (s[l]==s[r]){
			upd[l][r]={l, r};
			return dp[l][r]=2;
		}
		upd[l][r]={l, l};
		return dp[l][r]=1;
	}
	
	if (s[l]==s[r]){
		upd[l][r]={l, r};
		return dp[l][r]=f(l+1, r-1) + 2;
	}
	int res=max(f(l+1, r), f(l, r-1));
	if (f(l+1, r)>f(l, r-1)) upd[l][r]=upd[l+1][r];
	else upd[l][r]=upd[l][r-1];
	
	return dp[l][r]=res;
}

int main(){
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>s;
	n=s.size();
	for (int i=0; i<n; i++){
		vec[s[i]-'a'].pb(i);
		if (vec[s[i]-'a'].size()>=100){
			for (int j=0; j<100; j++) cout<<s[i];
			cout<<endl;
			return 0;
		}
	}
	memset(dp, -1, sizeof(dp));
	memset(upd, -1, sizeof(upd));
	//cerr<<f(0, n-1)<<endl;
	string outl="";
	string outr="";
	//debugp(upd[0][5]);
	//debugp(upd[1][4]);
	//debugp(upd[2][3]);
	f(0, n-1);
	
	
	for (int i=upd[0][n-1].first, j=upd[0][n-1].second; 0<=i && i<=j;){
		//debug(outl);
		//debug(outr);
		//debug(i);
		//debug(j);
		if (i==j){
			outl=outl+s[i];
			break ;
		}
		else{
			outl=outl+s[i];
			outr=s[j]+outr;
		}
		int tmp=i;
		i=upd[tmp+1][j-1].first;
		j=upd[tmp+1][j-1].second;
		if (i==tmp) break ;
	}
	if (outl.size()+outr.size()<=100)cout<<outl+outr<<endl;
	else{
		cout<<outl.substr(0, 50)+outr.substr(outr.size()-50, 50)<<endl;
	}
	
	return 0;
}
/*
                                                                                                            __                    .----.                    
          .---.                                                                     .---.              ...-'  |`. ..-'''-.       / .--. \        .-''-.     
          |   |.--.                       .                     .                   |   |.--.          |      |  |\.-'''\ \     ' '    ' '     .' .-.  )    
          |   ||__|                     .'|                   .'|                   |   ||__|          ....   |  |       | |    \ \    / /    / .'  / /     
          |   |.--.                    <  |                  <  |                   |   |.--.            -|   |  |    __/ /      `.`'--.'    (_/   / /      
    __    |   ||  |                     | |             __    | |             __    |   ||  |             |   |  |   |_  '.      / `'-. `.        / /       
 .:--.'.  |   ||  |                 _   | | .'''-.   .:--.'.  | | .'''-.   .:--.'.  |   ||  |          ...'   `--'      `.  \   ' /    `. \      / /        
/ |   \ | |   ||  |               .' |  | |/.'''. \ / |   \ | | |/.'''. \ / |   \ | |   ||  |          |         |`.      \ '. / /       \ '    . '         
`" __ | | |   ||  |              .   | /|  /    | | `" __ | | |  /    | | `" __ | | |   ||  |          ` --------\ |       , || |         | |  / /    _.-') 
 .'.''| | |   ||__|            .'.'| |//| |     | |  .'.''| | | |     | |  .'.''| | |   ||__|           `---------'        | || |         | |.' '  _.'.-''  
/ /   | |_'---'              .'.'.-'  / | |     | | / /   | |_| |     | | / /   | |_'---'                                 / ,' \ \       / //  /.-'_.'      
\ \._,\ '/                   .'   \_.'  | '.    | '.\ \._,\ '/| '.    | '.\ \._,\ '/                              -....--'  /   `.'-...-'.'/    _.'         
 `--'  `"                               '---'   '---'`--'  `" '---'   '---'`--'  `"                               `.. __..-'       `-...-'( _.-'            
 */