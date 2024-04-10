#include <bits/stdc++.h>
using namespace std;
typedef long long lli;

struct bigint{
	int len;
	int mod;
	int sum;
	char arr[1001];
};

bool chk[550][5050];

queue<bigint> Q;

int main() {
	int D, S;
	scanf("%d %d", &D, &S);
	bigint init;
	init.len = 0;
	init.mod = 0;
	init.sum = 0;
	init.arr[0] = 0;
	chk[0][0] = 1;
	Q.push(init);
	while(!Q.empty()){
		bigint x = Q.front();
		int mod = x.mod;
		int sum = x.sum;
		Q.pop();
		int len = x.len;
		if(mod == 0 && sum == S){
			for(int i = 0; i < len; i++){
				printf("%c", x.arr[i]);
			}
			puts("");
			return 0;
		}
		for(int i = 0; i <= 9; i++){
			int nmod = (mod*10 + i)%D;
			int nsum = sum + i;
			if(nsum <= S && chk[nmod][nsum] == 0){
				chk[nmod][nsum] = 1;
				bigint nele;
				nele.len = len + 1;
				nele.sum = nsum;
				nele.mod = nmod;
				for(int i = 0; i < len; i++){
					nele.arr[i] = x.arr[i];
				}
				nele.arr[len] = i + '0';
				Q.push(nele);
			}
		}
	}
	printf("-1\n");
	return 0;
}