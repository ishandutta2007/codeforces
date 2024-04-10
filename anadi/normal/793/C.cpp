#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef double D;

#define st first
#define nd second
#define pb push_back
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 1e5 + 7;
const int inf = 1e9 + 7;

int n;
pair <PII, PII> start;

int main(){
	scanf("%d", &n);
	scanf("%d %d %d %d", &start.st.st, &start.st.nd, &start.nd.st, &start.nd.nd);
	
	if(start.st.st > start.nd.st)
		swap(start.st.st, start.nd.st);
	if(start.st.nd > start.nd.nd)
		swap(start.st.nd, start.nd.nd);
	
	double mn = 0.0, mx = inf;
	for(int i = 1; i <= n; ++i){
		PII wsp, v;
		scanf("%d %d %d %d", &wsp.st, &wsp.nd, &v.st, &v.nd);
		double minx, maxx, miny, maxy;
		if(v.st == 0){
			if(start.st.st < wsp.st && wsp.st < start.nd.st){
				minx = 0;
				maxx = inf;
			}
			else{
				minx = inf;
				maxx = 0;
			}
		}
		else{
			minx = 1.0 * D(start.st.st - wsp.st) / D(v.st);
			maxx = 1.0 * D(start.nd.st - wsp.st) / D(v.st);
			if(minx > maxx)
				swap(minx, maxx);
		}

		if(v.nd == 0){
			if(start.st.nd < wsp.nd && wsp.nd < start.nd.nd){
				miny = 0.0;
				maxy = inf;
			}
			else{
				miny = inf;
				maxy = 0.0;
			}
		}
		else{
			miny = 1.0 * D(start.st.nd - wsp.nd) / D(v.nd);
			maxy = 1.0 * D(start.nd.nd - wsp.nd) / D(v.nd);
		if(miny > maxy)
			swap(miny, maxy);
		}

		mn = max(mn, max(miny, minx));
		mx = min(mx, min(maxx, maxy));
	}
	
	if(mn >= mx)
		puts("-1");
	else
		printf("%.8lf\n", mn);
	return 0;
}