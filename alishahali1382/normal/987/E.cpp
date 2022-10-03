#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define all(x) x.begin(), x.end()
#define pb push_back

const ld eps=1e-7;
const int inf=1000000010;
const int mod = 1000000007;
const int MAXN = 1000010;

ll n, m, k, ans, x, q;
int A[MAXN];
int B[MAXN];

void merg(int l, int mid, int r){
	//cerr<<"Merge "<<l<<' '<<mid<<' '<<r<<endl;
	//for (int i=1; i<=n; i++) cerr<<A[i]<<' ';cerr<<endl;
	for (int i=l; i<mid; i++) B[i]=A[i];
	B[mid]=inf;
	for (int i=mid; i<r; i++) B[i+1]=A[i];
	B[r+1]=inf;
	for (int i=l, j=mid+1, k=l, cnt=0; k<r; k++){
		if (B[i]<B[j]){
			A[k]=B[i++];
			ans+=cnt;
		}
		else{
			A[k]=B[j++];
			cnt++;
		}
	}
}
void Sort(int l, int r){
	if (r-l<2) return ;
	int mid=(l+r)/2;
	Sort(l, mid);
	Sort(mid, r);
	merg(l, mid, r);
}

int main(){
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	for (int i=1; i<=n; i++) cin>>A[i];
	Sort(1, n+1);
	if (n%2==ans%2) cout<<"Petr"<<endl;
	else cout<<"Um_nik"<<endl;
	//cerr<<ans<<endl;
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