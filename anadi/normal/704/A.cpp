#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

#define mp mkae_pair
#define pb push_back
#define PII pair <int, int>

const int mxn = 3e5 + 7;

int n, q;
int wsk = 1;
int ile_wsk = 0;
int read[mxn];
int quest[mxn];
deque <int> Q[mxn];

bool nieprzeczytane(int a){
	int b = quest[a];
	if(read[b] == 0)
		return false;
	if(Q[b].front() > a)
		return false;
	return true;
}

int main(){
	scanf("%d %d", &n, &q);
	int sum = 0;
	for(int i = 1; i <= q; ++i){
		int type, a;
		scanf("%d %d", &type, &a);
		if(type == 1){
			read[a]++;
			quest[i] = a;
			Q[a].pb(i);
			++sum;
		}

		if(type == 2){
			sum -= read[a];
			while(!Q[a].empty())
				Q[a].pop_front();
			read[a] = 0;
		}
		
		if(type == 3){
			while(ile_wsk < a){
				if(nieprzeczytane(wsk)){
					--sum;
					Q[quest[wsk]].pop_front();
					read[quest[wsk]]--;
				}
				
				if(quest[wsk] != 0)
					++ile_wsk;
				++wsk;
			}
		}
		
		printf("%d\n", sum);
	}

	return 0;
}