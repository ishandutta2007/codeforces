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
const int MAXN = 1000010;

int n, m, a, b, x, y, t, ans;
ll cnt[35];
int B[MAXN];

bool check(int x){
	ll arr[35], tmp[35];
	memset(tmp, 0, sizeof(tmp));
	for (int i=0; i<x; i++) tmp[B[i]]++;
	for (int i=0; i<35; i++) arr[i]=cnt[i];
	
	//for (int i=0; i<10; i++) cerr<<tmp[i]<<' ';cerr<<endl;
	//for (int i=0; i<10; i++) cerr<<arr[i]<<' ';cerr<<endl;
	
	for (int i=34; i; i--){
		if (arr[i]<tmp[i]) return false;
		arr[i]-=tmp[i];
		arr[i-1]+=2*arr[i];
	}
	return arr[0]>=tmp[0];
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>m;
	for (int i=0; i<n; i++){
		cin>>x;
		for (int j=0; j<32; j++) if ((x>>j)&1) cnt[j]++;
	}
	for (int i=0; i<m; i++) cin>>B[i];
	sort(B, B+m);
	
	//debug(check(2));
	
	int dwn=-1, up=m;
	while (up-dwn>1){
		int mid=(up+dwn)/2;
		if (check(mid)) dwn=mid;
		else up=mid;
	}
	if (!check(up)) up--;
	cout<<up<<endl;
	
	return 0;
}
/*
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