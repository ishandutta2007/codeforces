#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef double D;

#define PII pair <int, int>
#define PLL pair <LL, LL>
#define PDD pair <D, D>
#define mp make_pair
#define st first
#define nd second
#define pb push_back

void WriteInt(int a){
	printf("%d\n", a);
	fflush(stdout);
}

void WriteDouble(double a){
	printf("%.6lf\n", a);
	fflush(stdout);
}

void WriteString(string a){
	cout << a << "\n";
	cout.flush();
}

void wypisz(pair <PII, PII> a){
	printf("%d %d %d %d\n", a.st.st, a.st.nd, a.nd.st, a.nd.nd);
	fflush(stdout);
}

int n;
pair <PII, PII> ans1;
pair <PII, PII> ans2;
bool first_run = true;

bool jest(pair <PII, PII> res){
	return (res.st.st <= ans1.st.st && res.st.nd <= ans1.st.nd && res.nd.st >= ans1.nd.st && res.nd.nd >= ans1.nd.nd);
}

pair <PII, PII> BS_right(pair <PII, PII> res){
	int pocz = 1, kon = n;
	while(pocz < kon){
		int sred = (pocz + kon) / 2;
		res.nd.nd = sred;
		printf("? ");
		wypisz(res);

		int a;
		scanf("%d", &a);
		if(!first_run && jest(res))
			--a;
		if(a > 0)
			kon = sred;
		else
			pocz = sred + 1;
	}
	
	res.nd.nd = pocz;
	return res;
}

pair <PII, PII> BS_left(pair <PII, PII> res){
	int pocz = 1, kon = res.nd.nd;
	while(pocz < kon){
		int sred = (pocz + kon + 1) / 2;
		res.st.nd = sred;
		printf("? ");
		wypisz(res);

		int a;
		scanf("%d", &a);
		if(!first_run && jest(res))
			--a;
		if(a > 0)
			pocz = sred;
		else
			kon = sred - 1;
	}
	
	res.st.nd = pocz;
	return res;
}

pair <PII, PII> BS_up(pair <PII, PII> res){
	int pocz = 1, kon = n;
	while(pocz < kon){
		int sred = (pocz + kon) / 2;
		res.nd.st = sred;
		printf("? ");
		wypisz(res);

		int a;
		scanf("%d", &a);
		if(!first_run && jest(res))
			--a;
		if(a > 0)
			kon = sred;
		else
			pocz = sred + 1;
	}
	
	res.nd.st = kon;
	return res;
}

pair <PII, PII> BS_down(pair <PII, PII> res){
	int pocz = 1, kon = res.nd.st;
	while(pocz < kon){
		int sred = (pocz + kon + 1) / 2;
		res.st.st = sred;
		printf("? ");
		wypisz(res);

		int a;
		scanf("%d", &a);
		if(!first_run && jest(res))
			--a;
		if(a > 0)
			pocz = sred;
		else
			kon = sred - 1;
	}
	
	res.st.st = pocz;
	return res;
}

void find(){
	pair <PII, PII> req = mp(mp(1, 1), mp(n, n));
	req = BS_right(req);
	req = BS_left(req);
	req = BS_up(req);
	req = BS_down(req);
	
	if(first_run)
		ans1 = req;
	else
		ans2 = req;
}

int main(){
	scanf("%d", &n);
	find();
	first_run = false;
	find();
	printf("! ");
	printf("%d %d %d %d", ans1.st.st, ans1.st.nd, ans1.nd.st, ans1.nd.nd);
	printf(" ");
	wypisz(ans2);
	return 0;
}