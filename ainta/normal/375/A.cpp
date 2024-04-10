#pragma warning(disable:4996)
#include<stdio.h>
#include<algorithm>
using namespace std;
char p[1010000];
bool v[4], ck;
int n,  b[4] = { 1, 6, 8, 9 };
bool Mul()
{
	int i, s = 0;
	for (i = 0; i < n; i++){
		s *= 10;
		s += p[i] - '0';
		s %= 7;
	}
	if (!s){
		printf("%s\n", p);
		return true;
	}
	return false;
}
void DFS(int k){
	if (k == 4){
		if (Mul()){
			ck = true;
			return;
		}
	}
	int i;
	for (i = 0; i < 4; i++){
		if (v[i])continue;
		p[k] = '0' + b[i];
		v[i] = true;
		DFS(k + 1);
		v[i] = false;
		if (ck)return;
	}
}
int main()
{
	int i;
	scanf("%s", p);
	for (i = 0; p[i]; i++){
		if (p[i] == '1')swap(p[0], p[i]);
		if (p[i] == '6')swap(p[1], p[i]);
		if (p[i] == '8')swap(p[2], p[i]);
		if (p[i] == '9')swap(p[3], p[i]);
	}
	n = i;
	DFS(0);
}