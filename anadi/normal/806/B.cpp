#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef double D;

#define st first
#define nd second
#define pb push_back
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int inf = 1e9 + 7;

const int N = 130;
const int DX[] = {2, 4, 8, 16, 32, inf + 7};
const int MX[] = {500, 1000, 1500, 2000, 2500, 3000};

int n;
int solved[5];
int minutes[N][5];

int wynik(int czas, int ile_acc, int sum_sub){
	if(czas == -1)
		return 0;
	for(int i = 0; i < 6; ++i){
		if(1LL * ile_acc * DX[i] <= sum_sub)
			continue;
		
		return MX[i] - czas * MX[i] / 250;
	}
}

bool ok(int acc){
	int my_score = 0, pet_score = 0;
	for(int j = 0; j < 5; ++j){
		if(minutes[1][j] == minutes[2][j])
			continue;
		
		if(minutes[1][j] < minutes[2][j] || minutes[2][j] == -1){
			my_score += wynik(minutes[1][j], solved[j], n + acc);
			pet_score += wynik(minutes[2][j], solved[j], n + acc);
		}
		else if(minutes[1][j] == -1)
			pet_score += wynik(minutes[2][j], solved[j], n + acc);
		else{
			my_score += wynik(minutes[1][j], solved[j] + acc, n + acc);
			pet_score += wynik(minutes[2][j], solved[j] + acc, n + acc);
		}
	}

	return my_score > pet_score;
}

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
		for(int j = 0; j < 5; ++j)
			scanf("%d", &minutes[i][j]),
			solved[j] += minutes[i][j] >= 0;
	
	const int C = 10000;
	for(int i = 0; i < C; ++i)
		if(ok(i)){
			printf("%d\n", i);
			return 0;
		}
		
	puts("-1");
	return 0;
}