#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

#define st first
#define nd second
#define pb push_back
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 1e5 + 7;
const int MX = 1e9 + 7;
const int INF = 1e9 + 9;

int h, s, m, t1, t2;

int main(){
	scanf("%d %d %d %d %d", &h, &m, &s, &t1, &t2);
	
	if(h == 12)
		h = 0;
	if(t1 == 12)
		t1 = 0;
	if(t2 == 12)
		t2 = 0;

	if(t1 > t2)
		swap(t1, t2);
	
	t1 *= 3600; t2 *= 3600;
	h *= 3600;
	h += 60 * m + s;

	m *= 12 * 60;
	m += s * 12;
	
	s *= 12 * 60;
	
	int ile = 0;
	if(t1 < h && h < t2)
		++ile;
	
	if(t1 < m && m < t2)
		++ile;

	if(t1 < s && s < t2)
		++ile;
	
	if(ile == 0 || ile == 3)
		puts("YES");
	else
		puts("NO");
	return 0;
}