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

struct pnt{
	long long x, y;
	pnt(){}
	pnt(long long x, long long y): x(x), y(y){}	
	pnt operator - (pnt A){
		return pnt(x - A.x, y - A.y);		
	}
	long long operator * (pnt A){
		return x * A.y - y * A.x;		
	}	
};

pnt p[maxn];
int next[maxn];

int main(){
//     freopen("in", "r", stdin);
//     freopen("out", "w", stdout);
	int n, cur, x, y, t;
	long long ans, sum;
	pnt A;
	scanf("%d", &n);
	for (int i = n - 1; i >= 0; i--){
		scanf("%d%d", &x, &y);
		p[i] = pnt(x, y);		
	}
	
	
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++){
		cin >> A.x >> A.y;
		bool flag = 1;
		for (int i = 0; i < n; i++)
			if ((p[(i + 1) % n] - p[i]) * (A - p[i]) <= 0)
				flag = 0;
		if (!flag){
			cout << 0 << endl;
			continue;			
		}
		for (int i = 0; i < n; i++){
			cur = (i == 0)? 0: next[i - 1] - 1;
			for (; (p[(i + cur + 1) % n] - p[i]) * (A - p[i]) > 0; cur++);
			next[i] = cur;
		}
		ans = 0;
		sum = 0;
		cur = 0;
		for (int i = 1; i <= next[0]; i++)
			sum += next[i];
		for (int i = 0; i < n; i++){
			ans += sum - (next[i] * 1ll * (next[i] - 1) / 2);
			sum -= next[(i + 1) % n];
			for (int j = i + next[i] + 1; j <= i + 1 + next[i + 1]; j++)
				sum += next[j % n];
		}
	//	assert(ans % 3 == 0);
		cout << ans / 3 << "\n";
		
	}
 
    return 0;
}