#include<cstdio>
#include<algorithm>
#include<map>
#include<vector>
#define BS 1000
#define N_ 501000
using namespace std;

int T1[501000], T2[501000], w[N_];

struct AA {
	int Mn, Mx, b, e, c, bc;
	void UDT() {
		Mn = 1e9;
		Mx = -1e9;
		int i;

		T1[b - 1] = 1e9;
		T2[e + 1] = -1e9;
		for (i = b; i <= e; i++) {
			T1[i] = min(T1[i - 1], w[i]);
		}
		for (i = e; i >= b; i--) {
			T2[i] = max(T2[i + 1], w[i]);
		}
		bc = 0;
		for (i = b; i <= e; i++) {
			if (T1[i - 1] > T2[i])bc++;
		}

		for (i = b; i <= e; i++) {
			Mn = min(Mn, w[i]);
			Mx = max(Mx, w[i]);
		}
	}
	void Calc(int M1, int M2) {
		int i;
		if (M1 > Mx && Mn > M2) {
			c = bc;
			return;
		}
		T1[b - 1] = M1;
		T2[e + 1] = M2;
		for (i = b; i <= e; i++) {
			T1[i] = min(T1[i-1], w[i]);
		}
		for (i = e; i >= b; i--) {
			T2[i] = max(T2[i+1], w[i]);
		}
		c = 0;
		for (i = b; i <= e; i++) {
			if (T1[i - 1] > T2[i]) {
				c++;
			}
		}
	}
}T[1010];
int BB[501000];

int n, BC;

int MMn[1010], MMx[1010], BMMn[1010], BMMx[1010], Res = 0;

void PreCalc() {
	int i;
	for (i = 0; i <= BC + 1; i++)BMMn[i] = MMn[i], BMMx[i] = MMx[i];
	MMn[0] = 1e9;
	MMx[BC+1] = -1e9;
	for (i = 1; i <= BC; i++) {
		MMn[i] = min(MMn[i - 1], T[i].Mn);
	}
	for (i = BC; i >= 1; i--) {
		MMx[i] = max(MMx[i + 1], T[i].Mx);
	}
}
void Calc(int a, int oo) {
	Res -= T[a].c;
	if (MMn[a - 1] < MMx[a + 1]) {
		T[a].c = 0;
		return;
	}
	else if (oo == 1 || MMn[a - 1] != BMMn[a - 1] || MMn[a] != BMMn[a] || MMx[a] != BMMx[a] || MMx[a + 1] != BMMx[a + 1]) {
		T[a].Calc(MMn[a - 1], MMx[a + 1]);
	}
	Res += T[a].c;
}

int RR() {
	return rand() % 1000 * 1000 + rand() + 1;
}

int main() {
	int i, a, b, Q;
	//srand(1879);
	scanf("%d%d", &n,&Q);
	for (i = 1; i <= n; i++) {
		scanf("%d", &w[i]);
		//w[i] = RR();
		if (!T[i / BS + 1].b) {
			T[i / BS + 1].b = i;
		}
		T[i / BS + 1].e = i;
	}
	BC = n / BS + 1;
	for (i = 1; i <= BC; i++) {
		T[i].UDT();
	}
	PreCalc();
	for (i = 1; i <= BC; i++) {
		Calc(i, 1);
	}
	while(Q--) {
		scanf("%d%d", &a, &b);
		//a = RR() % n + 1;
		//b = RR();
		w[a] = b;
		T[a/BS+1].UDT();
		PreCalc();
		for (i = 1; i <= BC; i++) {
			if(i!=a/BS+1)Calc(i, 0);
			else Calc(i, 1);
		}
		printf("%d\n", Res);
		//if (Q % 10000 == 0)printf("%d\n", Q);
	}
}