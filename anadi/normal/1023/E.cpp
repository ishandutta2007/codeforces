#include <bits/stdc++.h>

using namespace std;

typedef double D;
typedef long long int LL;

#define st first
#define nd second
#define pb push_back
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 1e6 + 7;
const int MX = 1e9 + 7;
const LL INF = 1e18 + 9LL;

int n;

bool write(int r1, int c1, int r2, int c2){
	printf("? %d %d %d %d\n", r1, c1, r2, c2);
	fflush(stdout);
	
	char s[5];
	scanf("%s", s);
	assert(s[0] != 'B');
	
	if(s[0] == 'Y')
		return true;
	return false;
}

bool ask(int x, int y){
	if(x + y - 2 >= n - 1)
		return write(1, 1, x, y);
	return write(x, y, n, n);
}

vector <char> get(){
	int x = 1, y = 1;
	vector <char> ret;

	while(x + y < n + 1){
		if(write(x + 1, y, n, n)){
			++x;
			ret.push_back('D');
			continue;
		}
		
		++y;
		ret.push_back('R');
	}
	
	return ret;
}

vector <char> get2(){
	int x = n, y = n;
	vector <char> ret;

	while(x + y > n + 1){
		if(write(1, 1, x, y - 1)){
			--y;
			ret.push_back('R');
			continue;
		}
		
		--x;
		ret.push_back('D');
	}
	
	reverse(ret.begin(), ret.end());
	return ret;
}

int main(){
	scanf("%d", &n);
	vector <char> res1 = get();
	vector <char> res2 = get2();
	
	printf("! ");
	for(auto v: res1)
		printf("%c", v);
	for(auto v: res2)
		printf("%c", v);
	fflush(stdout);
	return 0;
}