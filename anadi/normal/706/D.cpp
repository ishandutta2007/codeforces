#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef double D;

#define pb push_back
#define mp make_pair
#define PII pair <int, int>
#define st first
#define nd second
#define PLL pair <LL, LL>
#define PDD pair <D, D>

const int N = 6e6 + 7;
const int B = 30;

int q;
int son[N][2];
int p[N];
map <int, int> M;
map <int, int> W;
int licz = 0;

void wypisz(){
	for(int i = 0; i <= licz; ++i)
		printf("%d %d\n", son[i][0] == 0 ? -1 : son[i][0], son[i][1] == 0 ? -1 : son[i][1]);
}

void dodaj(int a){
	int now = 0;
	for(int i = B; i >= 0; --i)
		if(a & (1 << i)){
			if(!son[now][1]){
				son[now][1] = ++licz;
				p[licz] = now;
			}
			
			now = son[now][1];
		}
		else{
			if(!son[now][0]){
				son[now][0] = ++licz;
				p[licz] = now;
			}
			
			now = son[now][0];
		}
	
	W[a] = now;
}

void usun(int a){
	int now = W[a];
	bool delt = true;
	for(int i = 0; i <= B; ++i){
		if(son[now][0] + son[now][1] > 0)
			delt = false;
		
		if(a & (1 << i)){
			if(delt)
				son[p[now]][1] = 0;
		}
		else{
			if(delt)
				son[p[now]][0] = 0;
		}
		now = p[now];
	}
}

int wynik(int a){
	int now = 0;
	int r = 0;
	for(int i = B; i >= 0; --i){
		if(a & (1 << i)){
			if(son[now][0]){
				now = son[now][0];
				r += 1 << i;
			}
			else
				now = son[now][1];
		}
		else{
			if(son[now][1]){
				now = son[now][1];
				r += 1 << i;
			}
			else
				now = son[now][0];
		}
	}
	
	return r;
}

int main(){
	dodaj(0);
	M[0]++;
	scanf("%d", &q);

	while(q--){
		char type;
		int a;
		scanf(" %c ", &type);
		scanf("%d", &a);
		if(type == '+'){
			if(M[a] == 0)
				dodaj(a);
			M[a]++;
		}
		
		if(type == '-'){
			M[a]--;
			if(M[a] == 0)
				usun(a);
		}
		
		if(type == '?')
			printf("%d\n", wynik(a));
	}

	return 0;
}