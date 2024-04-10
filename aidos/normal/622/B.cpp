#include <bits/stdc++.h>

using namespace std;
int h, m, a;

int main(){
	scanf("%d:%d %d", &h, &m, &a);
	m +=a;
	h += m/60;
	printf("%02d:%02d", h % 24, m%60);
}