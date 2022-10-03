#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int MAXN=1000 * 1000;
const int inf=1000 * 1000 * 1000 + 10;

ll n, x, y, xx, yy;
int A[MAXN][4];
pair<int, int> firstl[MAXN];
pair<int, int> lastl[MAXN];
pair<int, int> firstr[MAXN];
pair<int, int> lastr[MAXN];

int main(){
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	cin>>n;
	firstr[0].first=inf;
	firstr[0].second=inf;
	lastr[n+1].first=inf;
	lastr[n+1].second=inf;
	
	firstl[0].first=-inf;
	firstl[0].second=-inf;
	lastl[n+1].first=-inf;
	lastl[n+1].second=-inf;
	
	for (int i=1; i<=n; i++){
		cin>>A[i][0]>>A[i][1]>>A[i][2]>>A[i][3];
		firstl[i].first=max(firstl[i-1].first, A[i][0]);
		firstl[i].second=max(firstl[i-1].second, A[i][1]);
		firstr[i].first=min(firstr[i-1].first, A[i][2]);
		firstr[i].second=min(firstr[i-1].second, A[i][3]);
	}
	
	for (int i=n; i>=1; i--){
		lastl[i].first=max(lastl[i+1].first, A[i][0]);
		lastl[i].second=max(lastl[i+1].second, A[i][1]);
		lastr[i].first=min(lastr[i+1].first, A[i][2]);
		lastr[i].second=min(lastr[i+1].second, A[i][3]);
	}
	
	for (int i=1; i<=n; i++){
		x=max(firstl[i-1].first, lastl[i+1].first);
		y=max(firstl[i-1].second, lastl[i+1].second);
		xx=min(firstr[i-1].first, lastr[i+1].first);
		yy=min(firstr[i-1].second, lastr[i+1].second);
		//cout<<x<<' '<<y<<' '<<xx<<' '<<yy<<endl;
		if (x<=xx && y<=yy){
			cout<<x<<' '<<y<<endl;
			return 0;
		}
		
	}
	

		
	
	return 0;
}