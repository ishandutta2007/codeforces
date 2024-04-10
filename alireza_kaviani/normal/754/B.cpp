#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

#define all(x)      (x).begin(),(x).end()
#define X           first
#define Y           second
#define sep         ' '
#define endl        '\n'
#define SZ(x)       ll(x.size())

const ll MAXN = 1e6 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; //998244353; //1e9 + 9;

int ans , dx[4] = {1 , 0 , 1 , 1} , dy[4] = {0 , 1 , 1 , -1};
string s[4];

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin >> s[0] >> s[1] >> s[2] >> s[3];
	for(int i = 0 ; i < 4 ; i++){
		for(int j = 0 ; j < 4 ; j++){
			if(s[i][j] != '.')	continue;
			s[i][j] = 'x';
			for(int x = 0 ; x < 4 ; x++){
				for(int y = 0 ; y < 4 ; y++){
					for(int d = 0 ; d < 4 ; d++){
						int curx = x , cury = y , cnt = 0;
						for(int k = 0 ; k < 3 ; k++){
							if(curx < 0 || curx >= 4 || cury < 0 || cury >= 4)	break;
							if(s[curx][cury] != 'x')	break;
							cnt++;
							curx += dx[d];
							cury += dy[d];
						}
						ans |= (cnt == 3);
					}
				}
			}
			s[i][j] = '.';
		}
	}
	cout << (ans ? "YES" : "NO") << endl;

    return 0;
}
/*

*/