#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define debug(x) cerr<<#x<<'='<<x<<endl;
#define debugd(x) cerr<<#x<<'='<<setprecision(5)<<fixed<<x<<endl;
#define debugp(x) cerr<<#x<<"= {"<<x.first<<", "<<x.second<<"}"<<endl;
#define all(x) x.begin(), x.end()
#define pb push_back

const ld eps=1e-7;
const ll infll=1e18+100;
const int inf=1e9+100;
const int mod = 1000000007;
const int MAXN = 100010;

ld a, b, c, S, ans;

ld f(ld a, ld b, ld x, ld y){
	return pow(x, a)*pow(y, b);
}
ld f3(ld x, ld y, ld z){
	return pow(x, a)*pow(y, b)*pow(z, c);
}

ld calc(ld s){
	ld l=0, r=s;
	for (int i=0; i<150; i++){
		ld m1=(5*l+4*r)/9;
		ld m2=(4*l+5*r)/9;
		if (f(a, b, m1, s-m1)>f(a, b, m2, s-m2)) r=m2;
		else l=m1;
	}
	return r;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>S>>a>>b>>c;
	a/=100;
	b/=100;
	c/=100;
	ld l=0, r=S;
	for (int i=0; i<150; i++){
		ld m1=(5*l+4*r)/9;
		ld m2=(4*l+5*r)/9;
		//cerr<<l<<' '<<m1<<' '<<m2<<' '<<r<<endl;
		ld v1=calc(S-m1);
		ld v2=calc(S-m2);
		/*
		cerr<<f3(v1, S-m1-v1, m1)<<endl;
		cerr<<f3(v2, S-m2-v2, m2)<<endl;
		cerr<<endl;
		*/
		
		if (f3(v1, S-m1-v1, m1)>f3(v2, S-m2-v2, m2)) r=m2;
		else l=m1;
	}
	ld z=r;
	ld x=calc(S-z);
	ld y=S-x-z;
	setprecision(10);
	cout<<setprecision(10)<<fixed<<x<<' '<<setprecision(10)<<fixed<<y<<' '<<setprecision(10)<<fixed<<z<<endl;
	
	debugd(calc(598.212));
	
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