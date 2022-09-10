#include <bits/stdc++.h>

using namespace std;

typedef double D;
typedef long long int LL;

#define st first
#define nd second
#define pb push_back
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int Q = 1e4 + 7;
const int T[] = {(int)1e9 + 7, (int)1e9 + 9, 1234567891, 1070257823, 1070257849, 1070257189, 1003803979, 1003804027};

const int N = 1e6 + 7;
const LL INF = 1e18 + 9LL;

int MX;
string a, b;
int pt[N], H[N];

int m;
int val[N];

int hasz(int from, int to){
	return (((1LL * H[to] - 1LL * H[from] * pt[to - from])%MX) + MX)%MX;
}

int check(int l0, int l1){
	if((1LL * l0 * m + 1LL * l1 * (a.size() - m)) != b.size())
		return 0;

	int cur = 0, ha = -1, hb = -1;
	for(int i = 0; i < (int)a.size(); ++i){
		if(a[i] == '0'){
//			puts("tu");
			if(ha == -1)
				ha = hasz(cur, cur + l0);
			
			if(ha != hasz(cur, cur + l0))
				return 0;
			cur += l0;
		}
		else{
//			puts("tam");
			if(hb == -1)
				hb = hasz(cur, cur + l1);

			if(hb != hasz(cur, cur + l1))
				return 0;
			cur += l1;
		}
	}
	
	return ha != hb;
}

int main(){
	srand(*new int);
	ios_base::sync_with_stdio(false);
	cin >> a >> b;
	MX = T[rand()%8];

	pt[0] = 1;
	for(int i = 0; i < (int)b.size(); ++i){
		pt[i + 1] = (1LL * pt[i] * Q)%MX;
		H[i + 1] = (1LL * H[i] * Q + b[i])%MX;
	}
	
	for(auto v: a)
		m += v == '0';

	if(m == 0){
		if(b.size()%a.size() != 0){
			puts("0");
			return 0;
		}

		printf("%d\n", check(0, b.size() / a.size()));
		return 0;
	}
	
	if(m == (int)a.size()){
		if(b.size()%a.size() != 0){
			puts("0");
			return 0;
		}
		
		printf("%d\n", check(b.size() / a.size(), 0));
		return 0;
	}
	
	int res = 0;
	for(int i = 1; i <= (int)b.size(); ++i)
		if((int)b.size() > (1LL * i * m) && (b.size() - 1LL * i * m)%(a.size() - m) == 0)
			res += check(i, (b.size() - i * m) / (a.size() - m));
	printf("%d\n", res);
	return 0;
}