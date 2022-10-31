#include <vector>
#include <cstdio>
#include <cstring>
#include <map>
#include <algorithm>
#include <cmath>
using namespace std;

#define distance(x, y)\
	sqrt((double)(x)*(x)+(double)(y)*(y))

int main(){
	int n, vb, vs;
	scanf("%d %d %d", &n, &vb, &vs);
	vector<int>x;
	for(int i = 0; i < n; i ++){
		int y;
		scanf("%d", &y);
		x.push_back(y);
	}
	int xu, yu;
	scanf("%d %d", &xu, &yu);
	pair<double,double> m = make_pair(999999999999999.0,0.0); int mi = -1;
//	sort(x.begin(),x.end());
	for(int i = 1; i < n; i ++) {
		double d;
		d = distance(xu - x[i], yu);
		double t = (x[i] / (double)vb + d / (double)vs);
		pair<double, double>p = make_pair(t,d);
		if(t < m.first || (abs(t - m.first) < 0.00001 && d < m.second)) {
			mi = i;
			m = p;
		}
	}
	printf("%d\n", mi+1);
	return 0;
}