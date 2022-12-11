#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <cstring>
#include <map>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <bitset>
#define f first
#define s second
#define ll long long
#define ull unsigned long long
#define mp make_pair
#define pb push_back
#define vi vector <int>
#define ld long double
#define pii pair<int, int>
using namespace std;    
const int N = int(3e5), mod = int(1e9)  + 7;      

int s[N], d[N];

int main () {
	
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%d%d", &s[i], &d[i]);
	}

	int ans = 0;
	for(int i = 0; i < n; i++) {
		for(int j = i + 1; j < n; j++) {
			pair<int, int> p1, p2, p3;
			int mx = 0;
			{
				int cnt = 0;
				p1 = mp(s[i], 1);
				p2 = mp(s[j], 0);

				p3 = mp(s[i] + d[i], 1);
				if((p1 < p2 && p2 < p3) || (p1 > p2 && p2 > p3)) {
					cnt++;
				}
				p1 = p3;

				p3 = mp(s[j] + d[j], 0);
				if((p2 < p1 && p1 < p3) || (p2 > p1 && p1 > p3)) {
					cnt++;
				}
				p2 = p3;

				mx = max(mx, cnt);

			}

			{
				int cnt = 0;
				p1 = mp(s[i], 1);
				p2 = mp(s[j], 0);

				p3 = mp(s[j] + d[j], 0);
				if((p2 < p1 && p1 < p3) || (p2 > p1 && p1 > p3)) {
					cnt++;
				}
				p2 = p3;

				p3 = mp(s[i] + d[i], 1);
				if((p1 < p2 && p2 < p3) || (p1 > p2 && p2 > p3)) {
					cnt++;
				}
				p1 = p3;

				mx = max(mx, cnt);

			}
			ans += mx;
		}
	}

	cout << ans;


	return 0;
}