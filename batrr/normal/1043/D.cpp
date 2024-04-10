#include <bits/stdc++.h>

#define f first 
#define s second 
#define pb push_back               
#define mp make_pair 

using namespace std;                    

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = (int)1e5 + 123, inf = 1e9;
const ll INF = 1e18;

int n, m, p[10][N], pos[10][N];
ll ans;
int main(){
	scanf("%d%d", &n, &m);
	for(int i = 0; i < m; i++)
		for(int j = 0; j < n; j++){
			scanf("%d", &p[i][j]);
			pos[i][p[i][j]] = j;
		}
	for(int i = 0, j = 0; i < n; i++){
		while(j < n){
			bool good = 1;
			for(int q = 0; q < m; q++){
				if(i == j || pos[q][p[0][j]] == pos[q][p[0][j - 1]] + 1)
					continue; 
				good = 0;
			}
			if(good)
            	j++;
			else
				break;
		}
		//cerr << i << " " << j << endl;
		ans += j - i;
	}
	printf("%lld", ans);
	return 0;
}