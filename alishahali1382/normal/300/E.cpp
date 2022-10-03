#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
#define all(x) x.begin(), x.end()
#define pb push_back

const ld eps=1e-7;
const int inf=1000000010;
const int mod = 1000000007;
const int MAXN = 1000010;

ll get(ll a, ll b){
	if (a<b) return 0;
	return a/b+get(a/b, b);
}
int calc(ll a, ll b){
	if (a%b || a==0) return 0;
	return 1+calc(a/b, b);
}

ll k, ans=1, l, r, x, mx;
int A[10000001];
bool sieve[10000001];
int prime[MAXN], m;
ll cnt[MAXN];

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	for (int i=2; i*i<10000000; i++){
		if (sieve[i]) continue ;
		for (int j=i*i; j<10000000; j+=i) sieve[j]=true;
	}
	for (int i=2; i<10000000; i++) if (!sieve[i]) prime[m++]=i;
	//cerr<<m<<endl;
	cin>>k;
	for (int i=0; i<k; i++){
		cin>>x;
		A[x]++;
		mx=max(mx, x);
	}
	for (int i=9999999; i; i--) A[i]+=A[i+1];
	
	for (int i=0; i<m; i++){
		ll p=prime[i];
		for (int pp=p; pp<=10000000; pp+=p) cnt[i]+=A[pp]*calc(pp, p);
		
		//if (prime[i]<10)cerr<<prime[i]<<' '<<cnt[i]<<endl;
		
		l=mx-1;
		r=1e13;
		while (r-l>1){
			ll mid=(l+r)/2;
			if (get(mid, prime[i])<cnt[i]) l=mid;
			else r=mid;
		}
		ans=max(ans, r);
	}
	
	cout<<ans<<endl;
	
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