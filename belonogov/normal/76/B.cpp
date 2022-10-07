#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cassert>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <set>
#include <map>
#include <vector>
#include <queue>

using namespace std;

#define fr first
#define sc second
#define mp make_pair
#define pb push_back

#define epr(...) fprintf(stderr, __VA_ARGS__)

const int maxn = 1e5 + 2;
const int inf = 1e9;

int a[maxn];
int b[maxn];
int p[maxn];

int main(){
//     freopen("in", "r", stdin);
//     freopen("out", "w", stdout);
    int n, m, y, y0, ans = 0, cur, x;
	cin >> n >> m >> y >> y0;
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for (int i = 0; i < m; i++)
		scanf("%d", &b[i]);
	memset(p, -1, sizeof(p));
	cur = 0;
	for (int i = 0; i < n; i++){
		for (; cur < m && b[cur + 1] <= a[i]; cur++);
			
		if (b[cur] < a[i] && cur + 1 < m && a[i] - b[cur] == b[cur + 1] - a[i]){
			if (p[cur] == -1){
				p[cur] = a[i] - b[cur];
				ans++;			
			}
			else{
				if (p[cur] == a[i] - b[cur])
					ans++;
				else{
					ans++;
					p[cur + 1] = b[cur + 1] - a[i];
				}
			}
		}
		else{
			if (cur + 1 < m && abs(a[i] - b[cur]) > b[cur + 1] - a[i]){
				if (p[cur + 1] == -1){
					p[cur + 1] = b[cur + 1] - a[i];
					ans++;				
				}
				p[cur + 1] = min(p[cur + 1], b[cur + 1] - a[i]);
			}
			else{
// 				cerr << "i: " << i << endl;
				x = abs(b[cur] - a[i]);
// 				cerr << x << endl;
				if (p[cur] == -1 || p[cur] == x){
					p[cur] = x;
					ans++;	
				}
				else{
					p[cur] = min(p[cur], x);					
				}
				
			}
		}		
	}
// 	cerr << endl;
// 	for (int i = 0; i < m; i++)
// 		cerr << p[i] << " ";
// 	cerr << endl;
	cout << n - ans << endl;
	
    return 0;
}